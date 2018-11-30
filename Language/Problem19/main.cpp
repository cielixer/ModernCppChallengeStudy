// **fold expression : 종료조건을 사용 vs variadic template 이랑 다른거임
// template 에서 타입에 대한 문제 => static_assert 을 사용 -> concept 

template <typename Container>
void append_back(Container& _con) {};

template <typename Container, typename First, typename... Rest>
void append_back(Container& _con, First first, Rest... rest)
{
    _con.push_back(first);
    append_back(_con, rest...);
}

#include <vector>
#include <iostream>

int main(int argc, char* argv[])
{
    std::vector<int> vec{1,2,3};

    append_back(vec, 2, 3, 4);

    for (const auto& element : vec) {
        std::cout << element << " , ";
    }
    std::cout << std::endl;

    return 0;
}
