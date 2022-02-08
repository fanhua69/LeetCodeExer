
#include "headers.h"

class TreeNode
{
public:
    TreeNode(int n)
    {
        value = n;
        left = nullptr;
        right = nullptr;
    }

    TreeNode *left;
    TreeNode *right;

    int value;


};

void PrintTree(TreeNode *root);