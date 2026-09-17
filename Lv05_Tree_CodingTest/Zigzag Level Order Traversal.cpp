#include <iostream>
#include <queue>

int tree[100] = { 3, 9, 20, 0, 0, 15, 7, };

int main()
{
	std::queue<int> mqueue;
	mqueue.push(0);	
	int level = 1;

	while (!mqueue.empty())
	{
		int now = (level & 1) ? mqueue.front() : mqueue.back();
		int size = mqueue.size();

		for (int i = 0; i < size; ++i)
		{
			if (level & 1)
			{
				if (tree[(now + i) * 2 + 1] != 0)
					mqueue.push((now + i) * 2 + 1);

				if (tree[(now + i) * 2 + 2] != 0)
					mqueue.push((now + i) * 2 + 2);

				std::cout << tree[now + i] << ' ';
			}
			else
			{
				if (tree[(now - i) * 2 + 1] != 0)
					mqueue.push((now - i) * 2 + 1);

				if (tree[(now - i) * 2 + 2] != 0)
					mqueue.push((now - i) * 2 + 2);

				std::cout << tree[now - i] << ' ';
			}

			mqueue.pop();
		}
		level++;
		std::cout << std::endl;
	}


	return 0;
}