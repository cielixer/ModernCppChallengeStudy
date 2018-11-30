#include <iostream>
#include <utility>

// 생성자 소멸자를 통해 값을 제어
// Perfect forwarding 을 통해서 값들의 소유권을 제어하게 함

// a wraper class of smart pointer to handle the object's ownership...
template <typename T>
class Handler {
public:
    Handler(T& p_data)
    {

    }

    virtual bool isValid() = 0; // defined by the derived class

private:
    std::unique_ptr<T> m_data;
    // => unique_ptr 객체의 deleter을 지정할 수 있음
    //  => JNI를 사용할 때 Java쪽의 객체의 life cycle을 맞추기 위해 별도로 지정
};

int main(int argc, char* argv[])
{
    return 0;
}