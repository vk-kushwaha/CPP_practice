#include <iostream>
#include <queue>
#include <map>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Function to build a binary tree from level order traversal
TreeNode* buildTree() {
    int val;
    cin >> val;

    if (val == -1) {
        return nullptr;
    }

    TreeNode* root = new TreeNode(val);

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* current = q.front();
        q.pop();

        int leftVal, rightVal;
        cin >> leftVal >> rightVal;

        if (leftVal != -1) {
            current->left = new TreeNode(leftVal);
            q.push(current->left);
        }

        if (rightVal != -1) {
            current->right = new TreeNode(rightVal);
            q.push(current->right);
        }
    }

    return root;
}

void bottomView(TreeNode* root) {
    if (!root) {
        return;
    }

    map<int, int> bottomViewMap; // Map to store the bottom view nodes

    // Queue for level order traversal
    queue<pair<TreeNode*, int>> q;
    q.push({root, 0});

    while (!q.empty()) {
        TreeNode* current = q.front().first;
        int level = q.front().second;
        q.pop();

        // Update the bottom view node for the current level
        bottomViewMap[level] = current->val;

        if (current->left) {
            q.push({current->left, level - 1});
        }
        if (current->right) {
            q.push({current->right, level + 1});
        }
    }

    // Print the bottom view nodes
    for (auto it : bottomViewMap) {
        cout << it.second << " ";
    }
}

int main() {
    cout << "Enter the level order traversal of the binary tree (enter -1 for null): ";
    TreeNode* root = buildTree();

    cout << "Bottom View: ";
    bottomView(root);

    return 0;
}
