#include <iostream>
using namespace std;
class node{	
	public:
		int data;
		node * next;
		node(int val){
		data=val;
		next = NULL;
		}
	};
class LinkedList{
	node * last;;
	int count;
	node * head;
	public:
		LinkedList(){
			last = NULL;
			count = 0;
			head = NULL;
		}
	int get_first_element(){
		return head->data;
	}
	int get_length(){
		return count;
	}
	int get_last_element(){
		return last->data;
	}
	void insert_at_head(int val){
		node * temp = new node(val);
		temp->next=head;
		head=temp;
		count++;
	}	
	bool search(int n){
		node* temp=head;
		while (temp!=NULL){
			if(temp->data==n) return true;
			temp=temp->next;
		}
		return false;	
	}
	void insert_at_tail(int val){	
		node * n = new node(val);
		if (head==NULL){
		head = n;
		last = n;
		count++;
		return;
		}
		node* temp=head;
		while(temp->next!=NULL){
			temp=temp->next;
		}
		temp->next=n;
		last = n;
		count++;
	}
	
	void display(){
	node* temp=head;
	while (temp!=NULL){
	cout << temp->data <<" --> ";
	temp=temp->next;
	}
	cout <<"NULL";	
	}
	bool isEmpty(){
		return (head==NULL);
	}
	bool delete_node(int x){
		node* del = NULL;
		node* temp = head;
		if(temp->data==x){
			del = temp;
			head = temp->next;
			delete del;
			count--;
			return true;
		}
		while(temp->next->data!=x){
			temp=temp->next;
		}
		if(temp->next==last) last=temp;
		del = temp->next;
		temp->next=temp->next->next;
		delete del;
		count--;
		return true;
	}
};
	int main(){
		LinkedList L1;
		L1.insert_at_tail(1);
		L1.insert_at_tail(23);
		L1.insert_at_tail(24);
		L1.insert_at_tail(25);
		L1.insert_at_tail(26);
		cout<<"Original Linked List : \n";
		L1.display();
		cout<<endl<<endl;
		L1.delete_node(L1.get_first_element());
		cout <<"After Deleting From Begining: \n";
		L1.display();
		cout<<endl<<endl;
		L1.delete_node(L1.get_last_element());
		cout <<"After Deleting From End: \n";
		L1.display();
		cout<<endl<<endl;
		cout<<"IsEmpty List: ";(L1.isEmpty())? cout <<"True"<<endl : cout<<"False" <<endl;
		cout <<"\nFirst Element : " <<L1.get_first_element() <<endl;
		cout <<"\nLast Element : " <<L1.get_last_element()<<endl;
		cout <<"\nTotal Elements in The List : " <<L1.get_length()<<endl;
		
		
	}
		
		
		
