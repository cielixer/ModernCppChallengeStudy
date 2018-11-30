#include <iostream>

// Literals of various temperature scales

#include <chrono>

using namespace std;
using namespace chrono;
using namespace chrono_literals;

int main(int argc, char* argv[])
{
    time_point<steady_clocK> tp{};

    auto five_minute = 5min;
    auto seven_second = 7s;

    return 0;
}


// chrono 대신해서 google의 cctz를 사용 => 시간 관리 라이브러리
//                boost의 DateTime?? 도 있음
//      => 미국같이 주마다 시간이 다른 경우 핸들링 가능함




// 예를 들어 500KB가 있을 때
// constexpr int KB = 1024;
// auto data_size = 500 * KB;
// 이런식으로 하지 말고 literals를 사용해서 표현하는 것이 훨씬 권장됨