#include<iostream>
using namespace std;

class node{
public:
	int val;
	node* next;

	node(int x){
		val = x;
		next = NULL;
	}
};

void insert_at_tail(node* &head, int x){
	node* newNode = new node(x);

	while(head == NULL){
		head = newNode;
		return;
	}

	node* it = head;
	while(it->next != NULL){
		it = it->next;
	}
	it->next = newNode;
}

node* merge_sort(node* &head1, node* &head2){
	node* List = new node(0);

	node* it1 = List;
	while(head1 != NULL and head2 != NULL){
		if(head1->val > head2->val){
			it1->next = head2;
			head2 = head2->next;
			it1 = it1->next;
		}
		else{
			it1->next = head1;
			it1 = it1->next;
			head1 = head1->next;
		}
	}

	while(head1){
		it1->next = head1;
		it1 = it1->next;
		head1 = head1->next;
	}

	while(head2){
		it1->next = head2;
		it1 = it1->next;
		head2 = head2->next;
	}
	return List->next;
}

int main() {

	node* head1 = NULL;
	node* head2 = NULL;

	int t;
	cin>>t;

	for(int i =0; i<t; i++){
		int n;
		cin>>n;
		for(int j=0; j<n; j++){
			int x;
			cin>>x;
			insert_at_tail(head1, x);
		}

		int m;
		cin>>m;
		for(int k=0; k<m; k++){
			int y;
			cin>>y;
			insert_at_tail(head2, y);
		}

		node* ans = merge_sort(head1, head2);

		for(int l=0; l<(n+m); l++){
			cout<<ans->val<<' ';
			ans = ans->next;
		}
		cout<<endl;

	}

	return0;
}
