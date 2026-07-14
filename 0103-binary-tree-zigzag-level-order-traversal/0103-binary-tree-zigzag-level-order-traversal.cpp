class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {

        vector<vector<int>> ans;

        if(root == NULL)
            return ans;

        queue<TreeNode*> q;
        q.push(root);

        bool leftToRight = true;

        while(!q.empty())
        {
            int levelSize = q.size();

            vector<int> level;

            for(int i = 0; i < levelSize; i++)
            {
                TreeNode* current = q.front();
                q.pop();

                level.push_back(current->val);

                if(current->left)
                    q.push(current->left);

                if(current->right)
                    q.push(current->right);
            }

            if(!leftToRight)
            {
                reverse(level.begin(), level.end());
            }

            ans.push_back(level);

            leftToRight = !leftToRight;
        }

        return ans;
    }
};