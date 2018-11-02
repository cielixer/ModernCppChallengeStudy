#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cctype>

auto split_to_word(const std::string& str)
{
    std::vector<std::string> words;
    std::istringstream iss(str);

    do {
        std::string word;
        iss >> word;
        words.push_back(word);
    } while (iss);

    return words;
}

auto CapitalizeTitle(const std::string& str)
{
    auto splited = split_to_word(str);
    std::string completed;
    for (auto& word : splited) {
        word[0] -= 32;
        completed += word + " ";
    }

    return completed;
}

int main(int argc, char* argv[])
{
    std::cout << CapitalizeTitle("i have a apple, i have a pinapple. ang!") << std::endl;

    return 0;
}