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
    bool validate(TreeNode* root , long long Minval , long long Maxval){
        if(root == NULL){
            return true;
        }

        if(root->val <=Minval || root->val >=Maxval){
            return false;
        }

        return validate(root->left , Minval , root->val) && validate(root->right , root->val ,Maxval );
    }
    bool isValidBST(TreeNode* root) {
        return validate(root , LLONG_MIN , LLONG_MAX);
        
    }
};