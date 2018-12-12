#include "pch.h"
#include <iostream>
#include <iterator>
#include <thread>
#include <functional>
#include <numeric>

template <typename Iter, typename Pred>
auto par_transform(Iter srcBegin, Iter srcEnd, Iter dstBegin, Pred predicate)
{
	auto length = std::distance(srcBegin, srcEnd);
	std::vector<std::thread> executions;
	for (auto srcIt = srcBegin, dstIt = dstBegin; srcIt != srcEnd; ++srcIt, ++dstIt) {
		executions.push_back(std::thread{ [srcIt, dstIt, predicate]() -> void {
			*dstIt = predicate(*srcIt);
		} });
	}

	for (auto& t : executions) {
		t.join();
	}
}

int main()
{
	std::vector<int> range(10);
	std::vector<int> res(10);
	std::iota(std::begin(range), std::end(range), 0);

	par_transform(std::begin(range), std::end(range), std::begin(res),
		[](const auto& val) -> decltype(val) { return sqrt(val); });

	for (const auto val : res) {
		std::cout << val << "\t";
	}

}