#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
#include <numeric>

auto joinig_string(std::vector<std::string> &&words)
{
    std::transform(std::begin(words), std::end(words), std::begin(words),
        [](std::string word) -> std::string
            { return word + " "; });

    return std::accumulate(std::begin(words), std::end(words), std::string{},
        [](std::string &a, const std::string &b) -> decltype(auto)
            { return a += b; });
}

int main(int argc, char *argv[])
{
    std::cout << joinig_string({"i", "have", "an", "apple"}) << std::endl;

    return 0;
}
