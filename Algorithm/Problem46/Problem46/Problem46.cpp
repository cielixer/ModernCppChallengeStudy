#include "pch.h"
#include <iostream>
#include <vector>
#include <array>

template <typename T, int SIZE = 10>
class CircularBuffer {
private:
	CircularBuffer() = default;

public:
	CircularBuffer(std::initializer_list<T> p_list)
	{
		static_assert(SIZE > 0);
		static_assert(p_list.size() < SIZE);

		std::copy(std::begin(p_list), std::end(p_list), std::begin(m_data));
		m_movement = m_size = p_list.size();
	}

	inline auto empty() noexcept -> bool const { return m_size == 0; }
	inline auto full() noexcept -> bool const { return m_size == SIZE; }
	inline auto size() noexcept -> size_t const { return m_size; }
	inline constexpr auto capacity() noexcept const { return SIZE; }

	inline auto push(const T& value) noexcept -> void
	{
		m_data[(++m_movement) % SIZE] = value;
		if (m_size < SIZE) ++m_size;
	}

	inline auto pop() noexcept -> void
	{
		if (m_size > 0) --m_size;
		--m_movement;
	}

private:
	std::array<T, SIZE> m_data;
	size_t m_size = 0;

	int m_movement = 0;

};


int main()
{

}