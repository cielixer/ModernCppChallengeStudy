#include "pch.h"
#include <iostream>
#include <utility>

template <typename T>
class DoubleBuffer {
public:
	inline DoubleBuffer(const T& value) : m_front{ value } {}

public:
	virtual void update(const T& value)
	{
		// do something ...
		m_back = value;

		switch_buffer();
	}

	inline T& operator ->() noexcept {
		return m_front;
	}

	inline T& operator *() noexcept {
		return m_front;
	}

	inline T& get() noexcept { return m_front; }

protected:
	void switch_buffer()
	{
		std::swap(m_front, m_back);
	}

private:
	T m_front;
	T m_back;
};

int main()
{
	DoubleBuffer buf{ 1 };

	std::cout << *buf << std::endl;
	std::cout << buf.get() << std::endl;

	buf.update(2);

	std::cout << *buf << std::endl;
	std::cout << buf.get() << std::endl;

}