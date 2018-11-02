#include <array>
#include <string>
#include <sstream>
#include <iostream>
#include <ostream>
#include <optional>
#include <algorithm>
#include <iterator>

using namespace std;

class IPv4
{
	enum class ClassType : char { A = 0, B, C, D, E };

  public:
	IPv4(const string &ip = "127.0.0.1"s)
	{
		auto res = is_IPv4(ip);
		if (res == nullopt)
		{
			m_data.fill(-1);
			throw "unvalid IPv4 address"s;
		}

		m_data = res.value();
		setClassType();
	};

	IPv4(const IPv4 &other)
		: m_data{other.m_data}, m_classType{other.m_classType} {}

	IPv4(IPv4 &&other)
		: m_data{move(other.m_data)}, m_classType{other.m_classType} {}

	IPv4& operator = (const IPv4& rhs) = default;

	IPv4& operator = (IPv4&& rhs) = default;

	virtual ~IPv4() = default;

  public:
	string getClassType() noexcept
	{
		char class_name = static_cast<char>(m_classType) + 65;

		return ""s + class_name + " Class";
	}
	
	string getAddress() noexcept
	{
		string address{};
		for (const auto &part : m_data)
		{
			address += to_string(part);
			address += ".";
		}
		address.erase(end(address) - 1);

		return address;
	}

  private:
	static auto is_IPv4(const string &ip) -> optional<array<int, 4>>
	{
		stringstream ss{ip};
		array<int, 4> sliced;
		for (auto i = 0; i < 4; ++i)
		{
			string slice;
			getline(ss, slice, '.');
			if (slice.length() > 3)
				return nullopt;
			auto value = stoi(slice);

			if (value >= 0 && value <= 255)
				sliced[i] = value;
			else
				return nullopt;
		}

		return make_optional(sliced);
	}

	inline void setClassType() noexcept
	{
		if (m_data[0] < 128)
		{
			m_classType = ClassType::A;
		}
		else if (m_data[0] < 192)
		{
			m_classType = ClassType::B;
		}
		else if (m_data[0] < 224)
		{
			m_classType = ClassType::C;
		}
		else if (m_data[0] < 240)
		{
			m_classType = ClassType::D;
		}
		else
		{
			m_classType = ClassType::E;
		}
	}

  private:
	array<int, 4> m_data;
	ClassType m_classType;
};

ostream& operator << (ostream& os, IPv4& ip)
{
	return os << ip.getAddress();
}

int main(int argc, char *argv[])
{
	array<IPv4, 5> test;

	try {
		test[0] = IPv4{};
	} catch (string& e) {
		cout << e << endl;
	}

	try {
		test[1] = IPv4{"3.3.3.3"};
	} catch (string& e) {
		cout << e << endl;
	}

	try {
		test[2] = IPv4{"133.336.232.312"};
	} catch (string& e) {
		cout << e << endl;
	}

	try {
		test[3] = IPv4{"192.168.0.1"};
	} catch (string& e) {
		cout << e << endl;
	}

	try {
		test[4] = IPv4{"127.0.0.1"};
	} catch (string& e) {
		cout << e << endl;
	}

	for (auto& ip : test) {
		std::cout << ip << std::endl;
	}


	return 0;
}