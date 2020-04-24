#include <iostream>
#include <math.h>

int main()
{
    int N, M;
    std::cin >> N;
    std::cin >> M;

    bool result = true;

	N = (N < 2) ? 2 : N;

    for (int i = N; i < M; i += 1)
	{
		result = true;

        for (int j = 2; j <= std::sqrt(i) && result; j += 1)
            if (i % j == 0)
                result = false;

        if (result)
            std::cout << i << " ";
    }

    std::cout << "\n";

    return 0;
}