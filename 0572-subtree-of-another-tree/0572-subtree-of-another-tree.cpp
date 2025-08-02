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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root) return false;

        if(checkSameTree(root, subRoot)){
            return true;
        }

        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot); 
    }

    bool checkSameTree(TreeNode* p, TreeNode* q){
        if(!p && !q) return true;
        if(!p || !q) return false;

        if(p->val == q->val){
            return checkSameTree(p->left,q->left) && checkSameTree(p->right, q->right);
        }

        return false;
    }
};