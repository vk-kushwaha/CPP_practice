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

void topView(TreeNode* root) {
    if (!root) {
        return;
    }

    map<int, int> topViewMap; // Map to store the top view nodes

    // Queue for level order traversal
    queue<pair<TreeNode*, int>> q;
    q.push({root, 0});

    while (!q.empty()) {
        TreeNode* current = q.front().first;
        int level = q.front().second;
        q.pop();

        if (topViewMap.find(level) == topViewMap.end()) {
            // If the level is not in the map, add the node to the top view
            topViewMap[level] = current->val;
        }

        if (current->left) {
            q.push({current->left, level - 1});
        }
        if (current->right) {
            q.push({current->right, level + 1});
        }
    }

    // Print the top view nodes
    for (auto it : topViewMap) {
        cout << it.second << " ";
    }
}

int main() {
    // cout << "Enter the level order traversal of the binary tree (enter -1 for null): ";
    TreeNode* root = buildTree();

    // cout << "Top View: ";
    topView(root);

    return 0;
}
