#include <iostream>
#include <queue>
#include <vector>
#include <sstream>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Helper function to convert string to integer or return -1 for "false"
int stringToInt(const string& s) {
    return (s == "false") ? -1 : stoi(s);
}

void printNodesWithoutSibling(TreeNode* root) {
    if (root == nullptr) {
        return;
    }

    queue<TreeNode*> q;
    q.push(root);

    vector<int> result;

    while (!q.empty()) {
        TreeNode* current = q.front();
        q.pop();

        // Check if the current node doesn't have a sibling
        if ((current->left != nullptr && current->right == nullptr) ||
            (current->left == nullptr && current->right != nullptr)) {
            result.push_back(current->left ? current->left->val : current->right->val);
        }

        if (current->left != nullptr) {
            q.push(current->left);
        }

        if (current->right != nullptr) {
            q.push(current->right);
        }
    }

    for (int val : result) {
        cout << val << " ";
    }
}

// Function to build a binary tree from pre-order traversal
TreeNode* buildTree(vector<string>& nodes, int& index) {
    if (index >= nodes.size() || nodes[index] == "false") {
        index++;
        return nullptr;
    }

    TreeNode* root = new TreeNode(stringToInt(nodes[index]));
    index++;

    root->left = buildTree(nodes, index);
    root->right = buildTree(nodes, index);

    return root;
}

int main() {
    string input;
    getline(cin, input);

    // Tokenize the input
    stringstream ss(input);
    string token;
    vector<string> nodes;

    while (ss >> token) {
        nodes.push_back(token);
    }

    int index = 0;
    TreeNode* root = buildTree(nodes, index);

    printNodesWithoutSibling(root);

    return 0;
}
