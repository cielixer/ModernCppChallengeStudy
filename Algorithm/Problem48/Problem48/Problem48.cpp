// Problem48.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"
#include <iostream>
#include <map>
#include <algorithm>
#include <iterator>
#include <initializer_list>

auto find_frequency(std::initializer_list<int> ilist)
{
	std::map<int, int> _map;

	for (const auto& i : ilist) {
		_map.insert(std::make_pair());
	}

}

int main()
{
	auto freq = find_frequency({ 1,1,3,5,8,13,3,5,8,8,5 });

	for (const auto& p : freq) {
		std::cout << p << std::endl;
	}
}