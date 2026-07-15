class Solution {
public:

    int maxSum = INT_MIN;

    int dfs(TreeNode* root)
    {
        if(root == NULL)
            return 0;

        int leftGain = max(0, dfs(root->left));
        int rightGain = max(0, dfs(root->right));

        int currentPath = leftGain + rightGain + root->val;

        maxSum = max(maxSum, currentPath);

        return root->val + max(leftGain, rightGain);
    }

    int maxPathSum(TreeNode* root)
    {
        dfs(root);
        return maxSum;
    }
};