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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> v;
        solve(root,v,0);
        return v;
    }
    void solve(TreeNode* root, vector<int>& v, int h){
        if(!root) return;

        if(h==v.size()){
            //size 0 pe push 1 value, size1 pe push 1 value
            v.push_back(root->val);
        }
        
        solve(root->right,v,h+1);// see if right exist
        solve(root->left,v,h+1);//if it doesnt, push left values
    }
};