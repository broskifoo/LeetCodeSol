/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Codec {
public:

    // -------------------- SERIALIZE --------------------

    void preorder(TreeNode* root, string &s)
    {
        if(root == NULL)
        {
            s += "#,";
            return;
        }

        s += to_string(root->val) + ",";

        preorder(root->left, s);
        preorder(root->right, s);
    }

    string serialize(TreeNode* root)
    {
        string s;

        preorder(root, s);

        return s;
    }

    // -------------------- DESERIALIZE --------------------

    TreeNode* build(vector<string> &nodes, int &index)
    {
        if(nodes[index] == "#")
        {
            index++;
            return NULL;
        }

        TreeNode* root = new TreeNode(stoi(nodes[index]));
        index++;

        root->left = build(nodes, index);
        root->right = build(nodes, index);

        return root;
    }

    TreeNode* deserialize(string data)
    {
        vector<string> nodes;
        string temp = "";

        // Split the string using ','
        for(char c : data)
        {
            if(c == ',')
            {
                nodes.push_back(temp);
                temp = "";
            }
            else
            {
                temp += c;
            }
        }

        int index = 0;

        return build(nodes, index);
    }
};