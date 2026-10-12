#include <iostream>
#include <vector>
#include <algorithm>

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    // Function to find the cnt-th largest element in BST
    int kthLargest(TreeNode* root, int cnt) {
        std::vector<int> values;
        inorderTraversal(root, values);
        // Sort in descending order to get largest elements first
        std::sort(values.begin(), values.end(), std::greater<int>());
        return values[cnt - 1];
    }
    
    // Helper function to perform inorder traversal and collect values
    void inorderTraversal(TreeNode* node, std::vector<int>& values) {
        if (node == nullptr) return;
        
        inorderTraversal(node->left, values);
        values.push_back(node->val);
        inorderTraversal(node->right, values);
    }
};

// Function to build BST from level order traversal values
TreeNode* buildTree(const std::vector<int>& values) {
    if (values.empty()) return nullptr;
    
    TreeNode* root = new TreeNode(values[0]);
    
    // For each subsequent value, insert it into the BST
    for (int i = 1; i < values.size(); i++) {
        insertIntoBST(root, values[i]);
    }
    
    return root;
}

// Helper function to insert a value into BST
void insertIntoBST(TreeNode*& root, int val) {
    if (root == nullptr) {
        root = new TreeNode(val);
        return;
    }
    
    if (val < root->val) {
        insertIntoBST(root->left, val);
    } else {
        insertIntoBST(root->right, val);
    }
}

// Function to delete tree to prevent memory leaks
void deleteTree(TreeNode* root) {
    if (root == nullptr) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

int main() {
    // Read 8 integers from stdin
    std::vector<int> inputs(8);
    for (int i = 0; i < 8; i++) {
        std::cin >> inputs[i];
    }
    
    // Extract the first 7 values for BST nodes
    std::vector<int> nodeValues(inputs.begin(), inputs.begin() + 7);
    int cnt = inputs[7];
    
    // Build the BST from level order values
    TreeNode* root = buildTree(nodeValues);
    
    // Find the cnt-th largest element
    Solution solution;
    int result = solution.kthLargest(root, cnt);
    
    // Output the result
    std::cout << result << std::endl;
    
    // Clean up memory
    deleteTree(root);
    
    return 0;
}