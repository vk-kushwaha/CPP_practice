#include <iostream>
using namespace std;

// Define the TreeNode structure
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) : val(value), left(nullptr), right(nullptr) {}
};

// Function to replace each node's value with the sum of all nodes greater than itself
int replaceWithSum(TreeNode* root, int sum) {
    if (root == nullptr) {
        return sum;
    }

    // Recursively process the right subtree
    sum = replaceWithSum(root->right, sum);

    // Update the current node's value and pass it to the left subtree
    int temp = root->val;
    root->val = sum;
    sum += temp;

    // Recursively process the left subtree
    sum = replaceWithSum(root->left, sum);

    return sum;
}

// Function to display the tree in-order
void displayTree(TreeNode* root) {
    if (root != nullptr) {
        displayTree(root->left);
        cout << root->val << " ";
        displayTree(root->right);
    }
}

int main() {
    // Constructing the sample tree
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(2);
    root->right = new TreeNode(13);

    // Display the original tree
    cout << "Original tree: ";
    displayTree(root);
    cout << endl;

    // Replace each node's value with the sum of all nodes greater than itself
    replaceWithSum(root, 0);

    // Display the modified tree
    cout << "Modified tree: ";
    displayTree(root);
    cout << endl;

    // Clean up the allocated memory
    // (Note: In a complete program, you should properly deallocate memory)
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
