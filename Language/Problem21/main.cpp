#include <iostream>
#include <utility>

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
};

int main(int argc, char* argv[])
{
    return 0;
}