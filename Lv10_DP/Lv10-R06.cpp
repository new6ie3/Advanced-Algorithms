#include <iostream>

int dp[100] = {};

int main()
{
    int n = 4;

    dp[0] = 1;
    dp[1] = 1;

    for (int i = 2; i <= n; ++i)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    std::cout << dp[n];

    return 0;
}