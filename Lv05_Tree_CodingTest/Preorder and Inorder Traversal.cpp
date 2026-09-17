#include <iostream>

int preorder[100] = {3, 9, 20, 0, 0, 15, 7,};
int inorder[100] = { 0, 9, 0, 3, 20, 15, 7,};

void Print_Preorder(const int* tree, int now = 0)
{
	if (tree[now] == 0)
		return;

	std::cout << tree[now] << ' ';
	Print_Preorder(tree, now * 2 + 1);
	Print_Preorder(tree, now * 2 + 2);
}

void Print_Inorder(const int* tree, int now = 0)
{
	if (now >= 100)
		return;

	Print_Inorder(tree, now * 2 + 1);

	if(tree[now] != 0)
		std::cout << tree[now] << ' ';

	Print_Inorder(tree, now * 2 + 2);
}

int main()
{
	Print_Preorder(preorder);
	std::cout << std::endl;
	Print_Inorder(inorder);

	return 0;
}