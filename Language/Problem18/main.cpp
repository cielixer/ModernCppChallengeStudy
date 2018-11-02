#include <iostream>
#include <algorithm>
#include <functional>

template <typename T1, typename T2>
constexpr auto min(const T1& n1, const T2& n2)
{
    return std::min(static_cast<double>(n1), static_cast<double>(n2));
}


int main(int argc, char* argv[])
{
    std::cout << min(10, 3.14) << std::endl;

    return 0;
}