#include <iostream>
#include <math.h>

int main()
{
    int num;
    std::cin >> num;

    int step = 0;
    while (num / std::pow(10, step) >= 10)
    {
        step += 1;
    }

    int digit[step + 1], sum = 0, N = num;
    for (int i = step; i >= 0; i -= 1)
    {
        digit[i] = N / std::pow(10, i);
        N -= digit[i] * std::pow(10, i);
        sum += std::pow(digit[i], step + 1);
    }

    if (sum == num)
        std::cout << "true\n";
    else
        std::cout << "false\n";

    return 0;
}