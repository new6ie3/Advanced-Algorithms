#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> vec = { 0, 2, 4, -5, -7, 6, 20, 7, -10, -8, -4, -1, 0};

int main()
{
    int n = vec.size();
    std::vector<int> dp(n, INT_MIN);

    dp[0] = vec[0];

    for (int i = 0; i < n; ++i)
    {
        if (dp[i] == INT_MIN)
            continue;

        int next[3] =
        {
            i + 2,
            i + 3,
            i * 2
        };

        for (int j = 0; j < 3; ++j)
        {
            int ni = next[j];

            if (ni >= n || ni <= i)
                continue;

            dp[ni] = std::max(dp[ni], dp[i] + vec[ni]);
        }
    }


    std::cout << dp[n - 1];

    return 0;
}