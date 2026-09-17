#include <iostream>

int tree[100] = { 1, 2, 3, 4, 5, 0, 8, 0, 0, 6, 7, 0, 0, 9, 0,};

void Inorder_Traversal(int now = 0)
{
	if (tree[now] == 0)
		return;

	Inorder_Traversal(now * 2 + 1);		// left;
	std::cout << tree[now];
	Inorder_Traversal(now * 2 + 2);		// right;
}

int main()
{
	Inorder_Traversal();

	return 0;
}
