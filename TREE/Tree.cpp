#include <iostream>
using namespace std;

class node
{

public:
    int data;
    node *left;
    node *right;

    node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};
int main()
{

    node *root = new node(100);

    cout << root->data << endl;
    cout << root->left << endl;
    cout << root->right << endl;

    return 0;
}