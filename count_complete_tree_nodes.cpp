/**
 *  Count Complete Tree Nodes 
 *  Given a complete binary tree, count the number of nodes.
 */


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int countNodes(TreeNode* root) {
       if (NULL == root)
        {
            return 0;
        }

        int leftHeight = 1;
        int rightHeight = 1;
        TreeNode *p = root->left;
        while (p != NULL)
        {
            leftHeight++;
            p = p->left;
        }
    
        p = root->right;
        while (p != NULL)
        {
            rightHeight++;
            p = p->right;
        }

        if (leftHeight == rightHeight)
        {
            return (1 << leftHeight) - 1;
        }

        return countNodes(root->left) + countNodes(root->right) + 1; 
     
    }
};