/**
 *  Binary Tree Level Order Traversal II 
 *  输出由最后一层到第一层
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

    void swap(vector<int> &x, vector<int> &y)
    {
        vector<int> temp = x;
        x = y;
        y = temp;
    }
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
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
       
        return vector<vector<int>> (result.rbegin(),result.rend());
    }
};