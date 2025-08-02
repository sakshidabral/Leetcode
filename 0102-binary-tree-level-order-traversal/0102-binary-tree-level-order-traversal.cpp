/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        
        solve(root, res, 0);
        return res;
    }

    void solve(TreeNode* root, vector<vector<int>> &res, int h){
        if(!root) return;
        if(res.size() == h){
            res.push_back({});
        }

        res[h].push_back(root->val);
        
        solve(root->left, res, h+1);
        solve(root->right, res, h+1);
    }
};