// Problem45.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <optional>
#include <functional>
#include <initializer_list>
#include <string>
#include <sstream>

template <typename T>
class PriorityQueue {
	using ComparePredicate = std::function<bool(const T&, const T&)>;
public:
	inline PriorityQueue(std::initializer_list<T> p_list, ComparePredicate p_predicate = std::less<>()) noexcept
		: m_data{ p_list }, m_predicate{ p_predicate }
	{
		std::make_heap(std::begin(m_data), std::end(m_data), m_predicate);
	}

	virtual ~PriorityQueue() = default;

public:
	inline auto push(const T& value) -> void
	{
		m_data.push_back(value);
		std::push_heap(std::begin(m_data), std::end(m_data), m_predicate);
	}

	inline auto pop() -> void
	{
		std::pop_heap(std::begin(m_data), std::end(m_data), m_predicate);
		m_data.pop_back();
	}

	inline const auto& top() const
	{
		if (m_data.empty() == true) {
			std::cerr << "[Element access failed!] Priority Queue > queue is empty!" << std::endl;
			return T{};
		}
		return m_data.front(); 
	}

	inline auto size() -> size_t const { return m_data.size(); }

	inline auto empty() -> bool const { return m_data.empty(); }

	void print() noexcept
	{
		if (empty() == true) {
			std::cout << "[]" << std::endl;
			return;
		}

		std::stringstream ss;
		ss << "[";
		for (const auto& element : m_data) {
			ss << element << ",";
		}
		auto res = ss.str();
		res.pop_back();
		res += ']';

		std::cout << res << std::endl;
	}

private:
	std::vector<T> m_data;
	ComparePredicate m_predicate;
};

int main()
{
	PriorityQueue<int> pq{ {1, 2, 3, 4, 5}, [](const auto& a, const auto& b) -> bool {
		return a < b;
	} };

	while (pq.empty() == false) {
		pq.pop();

		std::cout << pq.size() << std::endl;
		pq.print();
	}

}