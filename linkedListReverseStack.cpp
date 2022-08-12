#include<iostream>
#include<stack>

using namespace std;

struct node{
	int data;
	node* next;
};

node* top = NULL;

void push(int data){
	node* temp = new node();
	temp->data = data;
	temp->next = top;
	
	top = temp;			
}

void pop(){
	if(top == NULL){
		cout<<"Stack is empty.";
		return;
	}
	
	node* temp;
	temp = top;
	top = top->next;
	delete temp;
}
bool isEmpty(){
	if(top == NULL){
		return true;
	}else{
		return false;
	}
}
int getTop(){
	if(top == NULL)
		return 0;
	
	return top->data;
}
void print(){
	cout<<endl;
	node* temp = top;
	
	cout<<"\nThe list is: ";
	
	while(temp != NULL){
		cout<<temp->data<<", ";
		temp = temp->next;
	}
}

void reverseListUsingStackExplicitly()
{
	if(top == NULL) {
		cout<<"\nThe list is empty.";
		return;
	}
	
    stack<int> st;

    node* curr = top;

    while (curr != NULL)
    {
        st.push(curr->data);
        curr = curr->next;
    }

    curr = top;

    while (!st.empty())
    {
        curr->data = st.top();
        curr = curr->next;
        st.pop();
    }

}
int main(){
	push(1);
	push(2);
	push(3);
	push(4);
	push(5);
	
	print();
	
	reverseListUsingStackExplicitly();
	print();
}
