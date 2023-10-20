#include<iostream>
#include<algorithm>
using namespace std;

struct Node{
public:
	int data;
	Node* left;
	Node* right;

	Node(int val){
		data =val;
		left =NULL;
		right = NULL;
		}
};

class Solution{
public: 
int getHeight(Node * node){
		if (node==NULL){
			return 0;
		}

		int leftHeight = getHeight(node->left);
		int rightHeight= getHeight(node->right);

		return 1+ max(leftHeight, rightHeight);
	}

};
Node* buildBinaryTree() {
    int data;
    cin >> data;
    if (data == -1) {
        return nullptr; // -1 indicates a null node.
    }

    Node* root = new Node(data);
    root->left = buildBinaryTree();
    root->right = buildBinaryTree();

    return root;
}

int main() {
    // cout << "Enter the binary tree elements in preorder (enter -1 for null nodes): ";
    Node* root = buildBinaryTree();

    Solution solution;
    int treeHeight = solution.getHeight(root);

    cout << "Height of the binary tree: " << treeHeight << endl;

    return 0;
}
// This code allows you to input the binary tree in a preorder fashion. You can enter the elements one by one, specifying -1 for null nodes. The code then constructs the binary tree and calculates its height using the height function.





