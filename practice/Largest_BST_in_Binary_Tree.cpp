#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) : val(value), left(NULL), right(NULL) {}
};

// Helper function to build a binary tree from preorder and inorder traversals
TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder, int& preIndex, int inStart, int inEnd) {
    if (inStart > inEnd) {
        return NULL;
    }

    TreeNode* root = new TreeNode(preorder[preIndex++]);

    int inIndex;
    for (int i = inStart; i <= inEnd; i++) {
        if (inorder[i] == root->val) {
            inIndex = i;
            break;
        }
    }

    root->left = buildTree(preorder, inorder, preIndex, inStart, inIndex - 1);
    root->right = buildTree(preorder, inorder, preIndex, inIndex + 1, inEnd);

    return root;
}

// Helper function to determine if a tree is a valid BST and find its size
int largestBSTUtil(TreeNode* root, int& maxSize, int& minVal, int& maxVal) {
    if (root == NULL) {
        minVal = INT_MAX;
        maxVal = INT_MIN;
        return 0;
    }

    int leftSize, rightSize;
    int leftMin, leftMax, rightMin, rightMax;

    // Check if left and right subtrees are BSTs and get their sizes and ranges
    leftSize = largestBSTUtil(root->left, maxSize, leftMin, leftMax);
    rightSize = largestBSTUtil(root->right, maxSize, rightMin, rightMax);

    // Check if the current subtree is a BST
    if ((leftSize == 0 || (leftSize > 0 && root->val > leftMax)) &&
        (rightSize == 0 || (rightSize > 0 && root->val < rightMin))) {
        int currentSize = leftSize + rightSize + 1;
        maxSize = max(maxSize, currentSize);
        minVal = (leftSize > 0) ? leftMin : root->val;
        maxVal = (rightSize > 0) ? rightMax : root->val;
        return currentSize;
    } else {
        // If the current subtree is not a BST, return 0
        return 0;
    }
}

// Function to find the size of the largest BST in the tree
int largestBST(TreeNode* root) {
    int maxSize = 0;
    int minVal, maxVal;
    largestBSTUtil(root, maxSize, minVal, maxVal);
    return maxSize;
}

int main() {
    int n;
    cin >> n;

    vector<int> preorder(n);
    vector<int> inorder(n);

    for (int i = 0; i < n; i++) {
        cin >> preorder[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> inorder[i];
    }

    int preIndex = 0;
    TreeNode* root = buildTree(preorder, inorder, preIndex, 0, n - 1);

    int result = largestBST(root);
    cout << result << endl;

    return 0;
}
