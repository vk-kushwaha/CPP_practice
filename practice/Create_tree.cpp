#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class TreeNode {
public:
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder, int& preIndex, int inStart, int inEnd, unordered_map<int, int>& indexMap) {
    if (preIndex >= preorder.size() || inStart > inEnd) {
        return nullptr;
    }

    int rootData = preorder[preIndex++];
    TreeNode* root = new TreeNode(rootData);

    int inIndex = indexMap[rootData];

    root->left = buildTree(preorder, inorder, preIndex, inStart, inIndex - 1, indexMap);
    root->right = buildTree(preorder, inorder, preIndex, inIndex + 1, inEnd, indexMap);

    return root;
}

void modifiedPreorder(TreeNode* root) {
    if (root) {
        if (root->left) {
            cout << root->left->data << " => ";
        } else {
            cout << "END => ";
        }

        cout << root->data << " <= ";

        if (root->right) {
            cout << root->right->data;
        } else {
            cout << "END";
        }

        cout << endl;

        modifiedPreorder(root->left);
        modifiedPreorder(root->right);
    }
}


int main() {
    int n;
    cin >> n;

    vector<int> preorder(n);
    for (int i = 0; i < n; ++i) {
        cin >> preorder[i];
    }

    int m;
    cin >> m;

    vector<int> inorder(m);
    for (int i = 0; i < m; ++i) {
        cin >> inorder[i];
    }

    unordered_map<int, int> indexMap;
    for (int i = 0; i < m; ++i) {
        indexMap[inorder[i]] = i;
    }

    int preIndex = 0;
    TreeNode* root = buildTree(preorder, inorder, preIndex, 0, m - 1, indexMap);

    modifiedPreorder(root);

    return 0;
}
