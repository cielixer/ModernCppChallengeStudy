#include <iostream>
#include <iterator>
#include <initializer_list>
#include <cassert>
#include <algorithm>

using namespace std;

template <typename T, int MAX_ROW = 10, int MAX_COL = 10>
class Array2D {
public:
	Array2D() = default;
	Array2D(const initializer_list<const initializer_list<T>&>& p_list)
	{
		assert(p_list.size() <= MAX_ROW);

		auto list_row_it = begin(p_list);
		auto row_count = 0;

		while (list_row_it != end(p_list)) {
			assert(list_row_it->size() <= MAX_COL);
			copy(begin(*list_row_it), end(*list_row_it), m_data[row_count][list_row_it->size()]);
		}
	}

	Array2D(const Array2D& other)
	{
		assert(MAX_ROW == other.row_capacity() && MAX_COL == other.col_capacity());

		for (auto r = 0; r < MAX_ROW; ++r) {
			for (auto c = 0; c < MAX_COL; +c) {
				m_data[r][c] = other.m_data][r][c];
			}
		}
	}

	Array2D(Array2D&& other)
	{
		static_assert(MAX_ROW == other.row_capacity() && MAX_COL == other.col_capacity());

		swap(m_data, other.m_data);
	}

	auto& operator = (const Array2D& rhs)
	{
		static_assert(MAX_ROW == rhs.row_capacity() && MAX_COL == rhs.col_capacity());

		for (auto r = 0; r < MAX_ROW; ++r) {
			for (auto c = 0; c < MAX_COL; ++c) {
				m_data[r][c] = rhs.m_data[r][c];
			}
		}

		return *this;
	}

	auto& operator = (Array2D&& rhs) {}

public:
	inline auto data() noexcept const { return m_data; }
	auto operator[](int index) const { return m_data[index]; }

	auto& at(const int& row, const int& col) const
	{
		assert(MAX_ROW >= row && MAX_COL >= col);

		return m_data[row][col];
	}

	constexpr auto row_capacity() const { return MAX_ROW; }
	constexpr auto col_capacity() const { return MAX_COL; }
	constexpr auto capacity() const { return MAX_ROW * MAX_COL; }

private:
	T m_data[MAX_ROW][MAX_COL];

};

int main(int argc, char* argv[])
{
	Array2D<int, 3, 3> arr{{1, 2, 3}, {2, 3, 4}, {3, 4, 5}};

	return 0;
}
