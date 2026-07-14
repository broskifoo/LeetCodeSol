class Solution {
public:
    vector<int> largestValues(TreeNode* root) {

        vector<int> ans;

        if(root == NULL)
            return ans;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty())
        {
            int levelSize = q.size();

            int maximum = INT_MIN;

            for(int i = 0; i < levelSize; i++)
            {
                TreeNode* current = q.front();
                q.pop();

                maximum = max(maximum, current->val);

                if(current->left)
                    q.push(current->left);

                if(current->right)
                    q.push(current->right);
            }

            ans.push_back(maximum);
        }

        return ans;
    }
};