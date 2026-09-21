class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> st;

        TreeNode* current = root;

        while (current != nullptr || !st.empty()) {
            // Go as far left as possible
            while (current != nullptr) {
                st.push(current);
                current = current->left;
            }

            // Process the node
            current = st.top();
            st.pop();

            result.push_back(current->val);

            // Move to the right subtree
            current = current->right;
        }

        return result;
    }
};
