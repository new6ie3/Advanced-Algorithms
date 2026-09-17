#include <iostream>
#include <queue>

struct Node
{
	int val;
	Node* left;
	Node* right;
	Node* next;
};

class BinaryTree
{
public:
	BinaryTree() : level(0), root(nullptr)
	{
	};

	~BinaryTree()
	{
		// delete nodes;
	}
	
	void AddNode(int _val)
	{
		Node* node = new Node();
		node->val = _val;
		node->left = nullptr;
		node->right = nullptr;
		node->next = nullptr;

		if (parents.empty())
		{
			parents.push(node);
			root = node;
			return;
		}

		Node* parent = parents.front();

		if (parent->left == nullptr)
		{
			parent->left = node;
		}
		else
		{
			parent->right = node;
			parents.pop();
			level++;
		}

		parents.push(node);
	}
	
 
	void ConnectNext()
	{
		ConnectNext(root);
	}

	void PrintNodes()
	{
		Node* levelStart = root;

		while (levelStart != nullptr)
		{
			Node* node = levelStart;

			while (node != nullptr)
			{
				std::cout << node->val << ' ';
				node = node->next;
			}

			std::cout << "# ";

			levelStart = levelStart->left;
		}
	}

private:
	Node* root;
	std::queue<Node*> parents;
	int level;

	void ConnectNext(Node* node)
	{
		if (node == nullptr)
			return;

		if (node->left == nullptr)
			return;

		node->left->next = node->right;

		if (node->next != nullptr)
		{
			node->right->next = node->next->left;
		}

		ConnectNext(node->left);
		ConnectNext(node->right);
	}
};




int main()
{
	BinaryTree tree;
	for (int i = 1; i < 8; ++i)
	{
		tree.AddNode(i);
	}

	tree.ConnectNext();
	tree.PrintNodes();

	return 0;
}