#include <iostream>
#include <vector>
#include <sstream>
#include <iterator>

using namespace std;

class TreeNode {
public:
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

bool areStructurallyIdentical(TreeNode* root1, TreeNode* root2) {
    // If both trees are empty, they are structurally identical
    if (!root1 && !root2) {
        return true;
    }

    // If one tree is empty and the other is not, they are not structurally identical
    if (!root1 || !root2) {
        return false;
    }

    // Recursively check the left and right subtrees
    return areStructurallyIdentical(root1->left, root2->left) && areStructurallyIdentical(root1->right, root2->right);
}

TreeNode* buildTree(vector<string>& nodes, int& index) {
    if (index >= nodes.size() || nodes[index] == "false") {
        // Return nullptr for NULL node
        index++;
        return nullptr;
    }

    // Create a new node with the current value
    TreeNode* newNode = new TreeNode(stoi(nodes[index]));

    // Recursively build left and right subtrees
    index++;
    newNode->left = buildTree(nodes, index);
    index++;
    newNode->right = buildTree(nodes, index);

    return newNode;
}

int main() {
    // Input for the first tree
    string input1;
    getline(cin, input1);
    istringstream iss1(input1);
    vector<string> nodes1((istream_iterator<string>(iss1)), istream_iterator<string>());
    int index1 = 0;
    TreeNode* root1 = buildTree(nodes1, index1);

    // Input for the second tree
    string input2;
    getline(cin, input2);
    istringstream iss2(input2);
    vector<string> nodes2((istream_iterator<string>(iss2)), istream_iterator<string>());
    int index2 = 0;
    TreeNode* root2 = buildTree(nodes2, index2);

    // Check if the trees are structurally identical
    if (areStructurallyIdentical(root1, root2)) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }

    return 0;
}
