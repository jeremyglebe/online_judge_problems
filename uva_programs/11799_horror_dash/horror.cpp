#include <iostream>

int main()
{
    // number of test cases
    int T;
    while (std::cin >> T)
    {
        for (int cs = 1; cs <= T; cs++)
        {
            // number of super spooky runners
            int N;
            std::cin >> N;
            // largest speed read in
            int max = -1;
            // loop n time to check speeds
            for (int i = 0; i < N; i++)
            {
                int temp;
                std::cin >> temp;
                if (temp > max)
                {
                    max = temp;
                }
            }
            // output results
            std::cout << "Case " << cs << ": " << max << '\n';
        }
    }
}