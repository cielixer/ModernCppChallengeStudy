#include "pch.h"
#include <iostream>
#include <utility>
#include <thread>
#include <functional>
#include <limits>
#include <algorithm>
#include <future>

// for testing
#include <random>

// parralel min_max function : implemented by using divide and conquer
template <typename Iter>
auto par_min_max(Iter start, Iter end)
	-> std::pair<Iter, Iter>
{
	auto dist = std::distance(start, end); // the distance(length) from start to end

	// base case
	if (dist == 1) {
		return std::make_pair(start, start);
	}
	else if (dist == 2) {

		return (*start < *std::next(start) ?
			std::make_pair(start, std::next(start))
							:
			std::make_pair(std::next(start), start)
		);
	}
	
	// inductive case
	auto half = start; std::advance(half, dist / 2);

	// left thread ( start ~ half )
	std::pair<Iter, Iter> left_res;
	std::thread left_th{ [start, half, &left_res]()
	{
		left_res = par_min_max(start, half);
	} }; 

	// right thread ( half ~ end )
	std::pair<Iter, Iter> right_res;
	std::thread right_th{ [half, end, &right_res]()
	{
		right_res = par_min_max(half, end);
	} };

	left_th.join(); right_th.join();

	return make_pair(
		*left_res.first < *right_res.first ? left_res.first : right_res.first,
		*left_res.second > *right_res.second ? left_res.second : right_res.second
	);
}

int main()
{
	std::random_device rd;
	std::mt19937 engine{ rd() };
	std::uniform_int_distribution<int> dist{ 0, 50 };

	std::vector<int> values;
	for (auto i = 0; i < 15; ++i) values.push_back(dist(engine));

	auto res = par_min_max(std::begin(values), std::end(values));

	for (const auto& i : values) {
		std::cout << i << " , ";
	}
	std::cout << std::endl;

	std::cout << *res.first << " , " << *res.second << std::endl;
}