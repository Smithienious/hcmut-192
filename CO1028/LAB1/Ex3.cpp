#include <iostream>

int main()
{
    int a, b, c;
    std::cin >> a; std::cin >> b; std::cin >> c;

    if (a == b && a == c)
    {
        std::cout << "Equilateral triangle\n";
        return 0;
    }

    if (a == b || a == c || b == c)
    {
        std::cout << "Isosceles triangle\n";
        return 0;
    }

    std::cout << "Scalene triangle\n";

    return 0;
}