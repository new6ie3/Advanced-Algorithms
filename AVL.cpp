#include <iostream>
#include <vector>

struct AVLNode
{
    int data;
    int height;
    AVLNode* left;
    AVLNode* right;

    AVLNode(int value) : data(value), height(1), left(nullptr), right(nullptr) {}
};

class AVLTree
{
public:
    AVLTree() { }
    ~AVLTree() { destroy(root); }

    void insert(int value)
    {
        root = insert(root, value);
    }

    void inorderSort(std::vector<int>& result)
    {
        inorder(root, result);
    }

private:
    int getHeight(AVLNode* node)
    {
        return node ? node->height : 0;
    }

    int getBalanceFactor(AVLNode* node)
    {
        return node ? getHeight(node->left) - getHeight(node->right) : 0;
    }

    void updateHeight(AVLNode* node)
    {
        if (node)
            node->height = 1 + std::max(getHeight(node->left), getHeight(node->right));
    }

    AVLNode* rotateRight(AVLNode* y)
    {
        AVLNode* x = y->left;
        y->left = x->right;
        x->right = y;
        updateHeight(y);
        updateHeight(x);
        return x;
    }

    AVLNode* rotateLeft(AVLNode* x)
    {
        AVLNode* y = x->right;
        x->right = y->left;
        y->left = x;
        updateHeight(x);
        updateHeight(y);
        return y;
    }

    AVLNode* insert(AVLNode* node, int value)
    {
        if (!node) return new AVLNode(value);

        if (value < node->data)
            node->left = insert(node->left, value);
        else
            node->right = insert(node->right, value);

        updateHeight(node);

        int balance = getBalanceFactor(node);

        // LL Case
        if (balance > 1 && value <= node->left->data)
            return rotateRight(node);

        // RR Case
        if (balance < -1 && value >= node->right->data)
            return rotateLeft(node);

        // LR Case
        if (balance > 1 && value > node->left->data)
        {
            node->left = rotateLeft(node->left);
            return rotateRight(node);
        }

        // RL Case
        if (balance < -1 && value < node->right->data)
        {
            node->right = rotateRight(node->right);
            return rotateLeft(node);
        }

        return node;
    }

    void inorder(AVLNode* node, std::vector<int>& result)
    {
        if (node)
        {
            inorder(node->left, result);
            result.push_back(node->data);
            inorder(node->right, result);
        }
    }

    void destroy(AVLNode* node)
    {
        if (node)
        {
            destroy(node->left);
            destroy(node->right);
            delete node;
        }
    }

private:
    AVLNode* root = nullptr;
};

int main()
{
    AVLTree tree;
    std::vector<int> values = { 10, 20, 30, 40, 50, 35 };
    for (int value : values)
        tree.insert(value);

    std::vector<int> sortedValues;
    tree.inorderSort(sortedValues);
    for (int value : sortedValues)
        std::cout << value << " ";

    return 0;
}