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
	bool isBalanced(Node* root){

		if(root== NULL){
			return true;
		}
		int leftHeight= getHeight(root->left);
		int rightHeight= getHeight(root->right);

		if(abs(leftHeight - rightHeight)<= 1 && isBalanced(root->left)&& isBalanced(root->right)){

			return true;
		}
		return false;
	}

	int getHeight(Node * node){
		if (node==NULL){
			return 0;
		}

		int leftHeight = getHeight(node->left);
		int rightHeight= getHeight(node->right);

		return 1+ max(leftHeight, rightHeight);
	}
};

int main(){

	Node* root= new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);

	Solution sol;

	if(sol.isBalanced(root)){

		cout<<" True"<<endl;
	}
	else{

		cout<< "False"<< endl;
	}

	return 0;
}