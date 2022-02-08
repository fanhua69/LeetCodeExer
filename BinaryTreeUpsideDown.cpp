#include "BinaryTreeUpsideDown.h"

TreeNode * upsideDownBinaryTree(TreeNode *root)
{
    if (root == nullptr || root->left == nullptr)
    {
        return root;
    }

    TreeNode *TotalRoot = nullptr;
    TotalRoot = upsideDownBinaryTree(root->left);

    TreeNode *newRoot = root->left;
    newRoot->left = root->right;
    newRoot->right = root;

    root->left = nullptr;
    root->right = nullptr;

    return TotalRoot;
}

TreeNode * upsideDownBinaryTreeIt(TreeNode *root)
{
    TreeNode *cur = root, *pre = nullptr, *next = nullptr, *tmp = nullptr;
    while (cur)
    {
        next = cur->left;
        cur->left = tmp;
        tmp = cur->right;
        cur->right = pre;
        pre = cur;
        cur = next;
    }

    return tmp;
}

void upsideDownBinaryTreeMain()
{
    TreeNode node1(1);
    TreeNode node2(2);
    TreeNode node3(3);
    TreeNode node4(4);
    TreeNode node5(5);

    node1.left = &node2;
    node1.right = &node3;
    node2.left = &node4;
    node2.right = &node5;

    PrintTree(&node1);

    TreeNode *newRoot = upsideDownBinaryTree(&node1);

    PrintTree(newRoot);

}