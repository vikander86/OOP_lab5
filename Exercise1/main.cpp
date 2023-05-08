#include <iostream>
#include <cmath>

template <typename T>
bool inPiRange(T num)
{
    const T pi = T(3.1415926535897932385L);
    if (std::abs(num) < pi)
    {
        return true;
    }
    else
    {
        return false;
    }
}
int main()
{
    std::cout << "2 in range? " << std::boolalpha << inPiRange(2) << std::endl;
    std::cout << "3.01923 in range? " << std::boolalpha << inPiRange(3.01923) << std::endl;
    std::cout << "4.21923 in range? " << std::boolalpha << inPiRange(4.21923) << std::endl;
    std::cout << "4 in range? " << std::boolalpha << inPiRange(4) << std::endl;
    return 0;
}