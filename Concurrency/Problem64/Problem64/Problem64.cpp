#include "pch.h"
#include <iostream>
#include <algorithm>
#include <thread>

#include <random>

template <typename Iter>
auto parrallel_sort(Iter start, Iter end) -> void
{
	const auto pivot = start;
	
	auto left_it = start + 1;
	auto right_it = end - 1;

	while (left_it != right_it) {
		while (*left_it <= *pivot && left_it != end - 1) {
			std::advance(left_it, 1); // 왼쪽 탐색 범위에서 pivot보다 큰 값을 찾는 과정
		}
		while (*right_it >= *pivot && right_it != start) {
			std::advance(right_it, -1); // 오른쪽 탐색 범위에서 pivot보다 작은 값을 찾는 과정
		}

		if (std::distance(left_it, right_it) >= 0) { // 교차되지 않았으면
			std::iter_swap(left_it, right_it);
		}
	}

	std::iter_swap(start, left_it); // pivot을 만나는 지점에 두고


	std::thread left_th{ [&start, &pivot]() { parrallel_sort(start, pivot); } };
	std::thread right_th{ [&pivot, &end] () { parrallel_sort(pivot + 1, end); } };

	left_th.join(); right_th.join();

	return;
}


int main()
{
	std::random_device rd;
	std::mt19937 engine{ rd() };
	std::uniform_int_distribution<int> dist{ 0, 100 };

	std::vector<int> unsorted;
	for (auto i = 0; i < 20; ++i) unsorted.push_back(dist(engine));

	for (const auto& num : unsorted) {
		std::cout << num << " ";
	}

	parrallel_sort(std::begin(unsorted), std::end(unsorted));

	std::cout << "-------------------------------------------------------" << std::endl;

	for (const auto& num : unsorted) {
		std::cout << num << " ";
	}

	return 0;
}
