class Solution {
public:
    void inOrder_bt(TreeNode* root, vector<int>& array) {
    if (root == NULL)       return;
        inOrder_bt(root->left, array);
        array.push_back(root->val);
        inOrder_bt(root->right, array);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> array;
        inOrder_bt(root, array);
        return array;
    }
};
