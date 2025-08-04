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
    TreeNode* buildTree(vector<int>& pre, vector<int>& in) {
        int n = pre.size();
        int idx = 0;

        return solve(0, n-1, idx, pre, in);
    }

    TreeNode* solve(int start, int end, int &idx, vector<int>& pre, vector<int>& in){
        if(start > end){
            return NULL;
        }

        int rootVal = pre[idx];
        int i = start;
        for(; i <= end; i++){
            if(in[i] == rootVal){
                break;
            }
        }

        idx++;

        TreeNode* root = new TreeNode(rootVal);
        root->left = solve(start, i-1, idx, pre, in);
        root->right = solve(i+1, end, idx, pre, in);

        return root;
    }
};