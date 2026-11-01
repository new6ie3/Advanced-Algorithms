#include <iostream>
#include <string>
#include <algorithm>

std::string str1 = "ABABCGKABABC";
std::string str2 = "BTBCKABABCT";

int dp[100][100] = {};

int main()
{
    int maxLen = 0;
    std::string res = "";

    for (int i = 0; i < str1.size(); ++i)
    {
        for (int j = 0; j < str2.size(); ++j)
        {
            if (str1[i] == str2[j])
            {
                if (i == 0 || j == 0)
                    dp[i][j] = 1;
                else
                    dp[i][j] = dp[i - 1][j - 1] + 1;

                if (maxLen < dp[i][j])
                {
                    maxLen = dp[i][j];
                    res = "";

                    for (int k = i - maxLen + 1; k <= i; ++k)
                        res += str1[k];
                }
            }
        }
    }

    std::cout << res;

    return 0;
}