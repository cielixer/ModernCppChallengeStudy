// ConsoleApplication2.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <iomanip>

auto convert_8bit2hexaString(const uint8_t& value)
{
	uint8_t upper = value >> 4;
	uint8_t lower = value & 0x0F;

	std::stringstream ss;
	if (upper < 10) {
		ss << std::to_string(upper);
	}
	else {
		ss << char((upper - 10) + 'A');
	}

	if (lower < 10) {
		ss << std::to_string(lower);
	}
	else {
		ss << char((lower - 10) + 'A');
	}

	return ss.str();
}

auto convert_hexaString_8bit(const std::string& hexastring)
{
	uint8_t upper, lower;

	if (hexastring[0] >= 'A') {
		upper = hexastring[0] - 'A';
	}
	else {
		upper = hexastring[0] - '0';
	}

	upper <<= 4;

	if (hexastring[1] >= 'A') {
		lower = hexastring[1] - 'A';
	}
	else {
		lower = hexastring[1] - '0';
	}

	return upper + lower;
}

auto Binary_to_Hexadecimal(const std::vector<uint8_t>& values)
-> std::string
{
	std::stringstream ss;

	for (const auto& value : values) {
		ss << convert_8bit2hexaString(value);
	}

	return ss.str();
}

auto Hexadecimal_to_Binary(const std::string& hexacode)
{
	std::vector<std::string> sliced;
	for (auto i = 0;  i != hexacode.size(); i += 2) sliced.push_back(hexacode.substr(i, 2));

	std::vector<uint8_t> hexadecimals;

	for (const auto& s : sliced) {
		hexadecimals.push_back(convert_hexaString_8bit(s));
	}

	return hexadecimals;
}

int main(int argc, char* argv[])
{

	std::cout << Binary_to_Hexadecimal({ 0xBA, 0xAD, 0xFD, 0x0D }) << std::endl;
	std::cout << Binary_to_Hexadecimal({ 1, 2, 3, 4, 5, 6 }) << std::endl;

	auto ex = Hexadecimal_to_Binary("BAADFD0D");
	 
	return 0;
}
