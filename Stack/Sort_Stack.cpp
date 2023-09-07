/*
Write a C++ program to sort a given stack (using an array) using another stack.
Test Data:
Input some elements onto the stack:
Stack elements: 0 1 5 2 4 7
Sort the elements in the stack:
Display the sorted elements of the stack:
Stack elements: 0 1 2 4 5 7 
*/

#include<iostream>
#include<stack>
using namespace std;

void SortStack(stack<int>&st){
	stack<int>tmpst;
	while(!st.empty())
	{
		int topEle= st.top();
		st.pop();

		while(!tmpst.empty() && tmpst.top()>topEle){
			st.push(tmpst.top());
			tmpst.pop();
		}
		tmpst.push(topEle);

	}

	while(!tmpst.empty()){
		st.push(tmpst.top());
		tmpst.pop();
	}
}

void display(stack<int>st)
{
	while(!st.empty())
	{
		cout<<st.top()<<" ";
		st.pop();
	}
}

int main()
{
	stack<int>st;

	st.push(0);
	st.push(1);
	st.push(5);
	st.push(2);
	st.push(4);
	st.push(7);

	display(st);
	cout<<endl;
	SortStack(st);

	display(st);



}