// Problem67.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <functional>
#include <algorithm>
#include <cstring>

using VALIDATOR = std::function<bool(const std::string&)>;

using std::string;
using namespace std::string_literals;

auto validate_password(const std::string& password,
								 const std::vector<VALIDATOR>& validators)
{
	size_t valid_count = 0;
	size_t unvalid_count = 0;

	for (const auto& val_func : validators) {
		val_func(password) == true ? valid_count++ : unvalid_count++;
	}

	return static_cast<float>(valid_count) / (valid_count + unvalid_count);
}

int main()
{
	auto score = validate_password("fkfnkn232FF_", {
		[](const std::string& password) -> bool // check at least one upper and one lower
	{
		return std::any_of(std::begin(password), std::end(password),[](const char& c) -> bool {
				return islower(c);
			})
													&& 
			std::any_of(std::begin(password), std::end(password), [](const char& c) -> bool {
				return isupper(c);
			});
	},
		[](const std::string& password) -> bool // check maximun length >= 10
	{
		return password.size() >= 0;
	}
		// ...
	});

	std::cout << "validation score : " << score << std::endl;
}