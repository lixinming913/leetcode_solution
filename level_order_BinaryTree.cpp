/**
 *  Binary Tree Level Order Traversal 
 *  Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root == NULL)
            return {};
            
        vector<vector<int>> result;
        vector<int> level_node;
        queue<TreeNode*> queue;
        
        queue.push(root);
        int cnt = 1;
        int next = 0;
        while(!queue.empty()) {
            if(queue.front()->left) {
                queue.push(queue.front()->left);
                next++;
            }
                
            if(queue.front()->right) {
                queue.push(queue.front()->right);
                next++;
            }
                
                
            level_node.push_back(queue.front()->val);
            queue.pop();
            cnt--;
            
            if(cnt == 0) {
                result.push_back(level_node);
                level_node.clear();
                cnt = next;
                next = 0;
            }
        }
        
        
        return result;
    }
};