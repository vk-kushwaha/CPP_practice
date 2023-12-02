#include <iostream>
#include <queue>
#include <string>
#include <sstream>
#include <cstdlib>

using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

Node* buildTree() {
    string input;
    getline(cin, input);

    stringstream ss(input);
    string word;
    ss >> word;

    if (word == "END") {
        return NULL;
    }

    int val;
    try {
        val = stoi(word);
    } catch (const invalid_argument& e) {
        cerr << "Invalid input (stoi): " << e.what() << endl;
        exit(EXIT_FAILURE);
    }

    Node* root = new Node(val);

    ss >> word;
    if (word == "true") {
        root->left = buildTree();
    } else if (word != "false") {
        cerr << "Invalid input (left child): " << word << endl;
        exit(EXIT_FAILURE);
    }

    ss >> word;
    if (word == "true") {
        root->right = buildTree();
    } else if (word != "false") {
        cerr << "Invalid input (right child): " << word << endl;
        exit(EXIT_FAILURE);
    }

    return root;
}


int sumOfNodes(Node* root) {
    if (root == NULL) {
        return 0;
    }

    return root->data + sumOfNodes(root->left) + sumOfNodes(root->right);
}

int main() {
    Node* root = buildTree();
    int sum = sumOfNodes(root);
    cout << sum << endl;

    return 0;
}
