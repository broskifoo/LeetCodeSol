class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {

        vector<double> ans;

        if(root == NULL)
            return ans;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty())
        {
            int levelSize = q.size();

            long long sum = 0;

            for(int i = 0; i < levelSize; i++)
            {
                TreeNode* current = q.front();
                q.pop();

                sum += current->val;

                if(current->left)
                    q.push(current->left);

                if(current->right)
                    q.push(current->right);
            }

            ans.push_back((double)sum / levelSize);
        }

        return ans;
    }
};