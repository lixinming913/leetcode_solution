/**
 *  Binary Tree Zigzag Level Order Traversal 
 *  Given a binary tree, return the zigzag level order traversal of its nodes' values.
 *   (ie, from left to right, then right to left for the next level and alternate between).
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) 
    {
        if(root == NULL)
            return {};
            
        vector<vector<int>> res;
        vector<int> row;
        stack<TreeNode*> s1;
        stack<TreeNode*> s2;
        
        s1.push(root);

        while(!s1.empty()) {
            if(s1.top()->left)
                s2.push(s1.top()->left);
            if(s1.top()->right)
                s2.push(s1.top()->right);
            
            row.push_back(s1.top()->val);
            s1.pop();
            
            if(s1.empty()) {
                res.push_back(row);
                row.clear();
                while(!s2.empty()) {
                    if(s2.top()->right)
                        s1.push(s2.top()->right);
                    if(s2.top()->left)
                        s1.push(s2.top()->left);
                        
                    row.push_back(s2.top()->val);
                    s2.pop();
                }
                
                if(!row.empty()) {
                    res.push_back(row);
                    row.clear();
                }
            }
            
        }
        
        return res;
        
    }
};