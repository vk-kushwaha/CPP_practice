#include <iostream>
#include <map>
#include <vector>
#include <queue>

using namespace std;

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Function to perform vertical traversal of the binary tree
void verticalTraversal(TreeNode* root) {
    if (!root) {
        return;
    }

    // Using a map to store nodes at each vertical distance
    map<int, vector<int>> verticalMap;

    // Using a queue for level order traversal
    queue<pair<TreeNode*, int>> q;
    q.push({root, 0});  // Pair of node and its vertical distance

    while (!q.empty()) {
        TreeNode* node = q.front().first;
        int distance = q.front().second;
        q.pop();

        // Store the node value in the corresponding vertical distance
        verticalMap[distance].push_back(node->val);

        // Enqueue left child with a decreased vertical distance
        if (node->left) {
            q.push({node->left, distance - 1});
        }

        // Enqueue right child with an increased vertical distance
        if (node->right) {
            q.push({node->right, distance + 1});
        }
    }

    // Print nodes in each vertical column
    for (const auto& entry : verticalMap) {
        for (int val : entry.second) {
            cout << val << " ";
        }
    }

    cout << endl;
}

// Function to build a binary tree from level order traversal
TreeNode* buildTree(vector<int>& levelOrder, int index, int n) {
    TreeNode* root = NULL;

    if (index < n && levelOrder[index] != -1) {
        root = new TreeNode(levelOrder[index]);
        root->left = buildTree(levelOrder, 2 * index + 1, n);
        root->right = buildTree(levelOrder, 2 * index + 2, n);
    }

    return root;
}

int main() {
    int N;
    cin >> N;

    vector<int> levelOrder((1 << N) - 1);
    for (int i = 0; i < (1 << N) - 1; ++i) {
        cin >> levelOrder[i];
    }

    // Build the binary tree
    TreeNode* root = buildTree(levelOrder, 0, (1 << N) - 1);

    // Perform vertical traversal and print the result
    verticalTraversal(root);

    return 0;
}
