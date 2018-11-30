#include "pch.h"
#include <iostream>
#include <iterator>
#include <array>
#include <algorithm>

using namespace std;

/* ** naddu77 님의 방식
// - Zip을 이용하여 Pascal's Triangle을 만듦
//	 [1]
//	    [1]
//   [1, 1]
//      [1, 1]
//   [1, 2, 1]
//      [1, 2, 1]
//   [1, 3, 3, 1]
//      [1, 3, 3, 1]
//   [1, 4, 6, 4, 1]
*/

void print_pascal()
{
	array<array<int, 10>, 10> triangle;
	for (auto& arr : triangle) arr.fill(0);

	triangle[0][0] = 1;

	transform(begin(triangle), end(triangle),
		std::next(std::next(begin(triangle))),
		[](const auto& val) {

	});

}

int main()
{
	print_pascal();
}
