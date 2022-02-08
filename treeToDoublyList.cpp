
#include "TreeNode.h"

// the smallest (first) and the largest (last) nodes
TreeNode *first = NULL;
TreeNode *last = NULL;

void helper(TreeNode *node)
{
    if (node)
    {
        // left
        helper(node->left);
        // node
        if (last)
        {
            // link the previous node (last)
            // with the current one (node)
            last->right = node;
            node->left = last;
        }
        else
        {
            // keep the smallest node
            // to close DLL later on
            first = node;
        }
        last = node;
        // right
        helper(node->right);
    }
}

TreeNode *treeToDoublyList(TreeNode *root)
{
    first = nullptr;
    last = nullptr;

    if (!root)
        return NULL;

    helper(root);
    // close DLL
    last->right = first;
    first->left = last;
    return first;
}

void treeToDoublyListMain()
{
    TreeNode a1(1);
    TreeNode a2(2);
    TreeNode a3(3);
    TreeNode a4(4);
    TreeNode a5(5);

    a4.left = &a2;
    a4.right = &a5;
    a2.left = &a1;
    a2.right = &a3;

    TreeNode * head = treeToDoublyList(&a4);
    for (int i = 0; i < 5;i++)
    {
        cout << head->value << endl;
        head = head->right;
    }
}