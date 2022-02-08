
#include "TreeNode.h"

void PrintTree(TreeNode *root)
{
    std::queue<TreeNode*> q;
    std::queue<int> layer;
    q.push(root);
    layer.push(0);

    int iCurrLayer = 0;
    while (!q.empty())
    {
        TreeNode *node = q.front();
        int l = layer.front();
        if(l != iCurrLayer)
        {
            cout << endl;
            iCurrLayer = l;
        }
        cout << q.front()->value<< " , ";
        q.pop();
        layer.pop();

        if(node->left)
        {
            q.push(node->left);
            layer.push(l + 1);
        }
        
        if (node->right)
        {
            q.push(node->right);
            layer.push(l + 1);
        }
    }
    cout << endl;
}