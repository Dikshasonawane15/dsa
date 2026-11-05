
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> mp;

        for (int i = 0; i < inorder.size(); i++) {
            mp[inorder[i]] = i;
        }

        int preIndex = 0;

        return solve(preorder, inorder, mp, preIndex, 0, inorder.size() - 1);
    }

    TreeNode* solve(vector<int>& preorder, vector<int>& inorder,
                    unordered_map<int, int>& mp, int& preIndex,
                    int start, int end) {

        if (start > end)
            return NULL;

        int rootVal = preorder[preIndex++];
        TreeNode* root = new TreeNode(rootVal);

        int inIndex = mp[rootVal];

        root->left = solve(preorder, inorder, mp, preIndex,
                           start, inIndex - 1);

        root->right = solve(preorder, inorder, mp, preIndex,
                            inIndex + 1, end);

        return root;
    }
};
