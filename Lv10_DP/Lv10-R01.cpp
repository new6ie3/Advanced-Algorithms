#include <iostream>
#include <queue>
#include <vector>

int arr[4] = { 15, 30, 50, 10 };

int main()
{
    std::priority_queue<int, std::vector<int>, std::greater<int>> q;

    for (int i = 0; i < 4; ++i)
        q.push(arr[i]);

    int res = 0;
    int wait = 0;

    while (!q.empty())
    {
        int front = q.top();
        q.pop();

        res += wait;
        wait += front;
    }

    std::cout << res;

    return 0;
}