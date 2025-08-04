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
    int maxSum;

    int maxPathSum(TreeNode* root) {
        maxSum = INT_MIN;
        solve(root);
        return maxSum;
    }

    int solve(TreeNode* root){
        if(!root) return 0;

        int l = solve(root->left);
        int r = solve(root->right);

        int niche_hi_milgya_ans = l + r + root->val;

        int koi_ek_acha = max(l,r) + root->val;
 
        int only_root_acha = root->val;

        maxSum = max({maxSum, niche_hi_milgya_ans, koi_ek_acha, only_root_acha});
        return max(koi_ek_acha, only_root_acha);
    }
};