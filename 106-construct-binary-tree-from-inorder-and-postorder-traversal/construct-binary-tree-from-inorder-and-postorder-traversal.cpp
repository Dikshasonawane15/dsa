
class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> mp;

        for (int i = 0; i < inorder.size(); i++) {
            mp[inorder[i]] = i;
        }

        int postIndex = postorder.size() - 1;

        return solve(inorder, postorder, mp, postIndex,
                     0, inorder.size() - 1);
    }

    TreeNode* solve(vector<int>& inorder, vector<int>& postorder,
                    unordered_map<int, int>& mp, int& postIndex,
                    int start, int end) {

        if (start > end)
            return NULL;

        int rootVal = postorder[postIndex--];
        TreeNode* root = new TreeNode(rootVal);

        int inIndex = mp[rootVal];

        root->right = solve(inorder, postorder, mp, postIndex,
                            inIndex + 1, end);

        root->left = solve(inorder, postorder, mp, postIndex,
                           start, inIndex - 1);

        return root;
    }
};
