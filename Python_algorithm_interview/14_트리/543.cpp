class Solution
{
public:
    int dia;

    int dfs(TreeNode *node)
    {
        if (!node)
            return -1;

        int l = dfs(node->left);
        int r = dfs(node->right);
        dia = max(dia, l + r + 2);
        return max(l, r) + 1;
    }

    int diameterOfBinaryTree(TreeNode *root)
    {
        dfs(root);
        return dia;
    }
};