class Solution
{
public:
    int maxDepth(TreeNode *root)
    {
        if (!root)
            return 0;

        int depth = 0;

        queue<TreeNode *> q;
        q.push(root);

        while (q.size())
        {
            depth++;
            // for (int i = 0; i < q.size(); i++) // q.size() 가 변하면 반복문에 영향 미침.
            int n = q.size();
            for (int i = 0; i < n; i++) // 값 미리 저장.
            {
                auto cur_root = q.front();
                q.pop();
                if (cur_root->left)
                    q.push(cur_root->left);
                if (cur_root->right)
                    q.push(cur_root->right);
            }
        }

        return depth;
    }
};