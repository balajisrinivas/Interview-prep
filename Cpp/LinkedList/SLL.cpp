#include<iostream>

using namespace std;

struct SLLNode {
	int data;
	struct SLLNode *next;
};

typedef struct SLLNode* node;

void insertAtEnd(node &head, int x) {
	node temp = new SLLNode;
	temp->data = x;
	temp->next = NULL;
	node cur = head;
	if(head == NULL)
		head = temp;
	else {
		while(cur->next != NULL)
			cur = cur->next;
		cur->next = temp;
	}
}

void insertAtStart(node &head, int x) {
	node temp = new SLLNode;
	temp->data = x;
	temp->next = NULL;
	if(head == NULL)
		head = temp;
	else {
		temp->next = head;
		head = temp;
	}
}

void insertAtPos(node &head, int x, int pos) {
	node temp = new SLLNode;
	temp->data = x;
	temp->next = NULL;

	if(head == NULL) {
		if(pos == 1)
			head = temp;
		else {
			cout<<"Insert at pos greater than the length of the array not possible"<<endl;
			exit(1);
		}
	}

	int count = pos-2;
	node cur = head;
	node nxt = cur->next;
	while(count) {
		cur = cur->next;
		nxt = nxt->next;
		count--;
	}
	temp->next = nxt;
	cur->next = temp;
}	

void deleteAtEnd(node &head) {
	if(head == NULL) {
		cout<<"Delete in an empty list not possible"<<endl;
		exit(1);
	}
	if(head->next == NULL) {
		delete head;
		head = NULL;
		return;
	}
	node cur = head;
	node nxt = cur->next;
	while(nxt->next) {
		cur = cur->next;
		nxt = nxt->next;
	}
	cur-> next = NULL;
	delete nxt;
}

void deleteAtStart(node &head) {
	if(head == NULL) {
		cout<<"Delete in an empty list not possible"<<endl;
		exit(1);
	}
	node nxt = head->next;
	delete head;
	head = nxt;
} 

void deleteAtPos(node &head, int pos) {
	if(head == NULL) {
		cout<<"Delete in an empty list not possible"<<endl;
		exit(1);
	}
	int count = pos-2;
	node cur = head;
	node nxt = cur->next;
	while(count) {
		cur = cur->next;
		nxt = nxt->next;
		count--;
	}
	cur->next = nxt->next;
	delete nxt;
}

void deleteValue(node &head, int value) {
	if(head == NULL) {
		cout<<"Delete in an empty list not possible"<<endl;
		exit(1);
	}

	if(head->data == value) {
		node temp = head;
		head = head->next;
		delete temp;
	}
	
	node cur = head;
	node nxt = cur->next;
	while(nxt) {
		while(nxt && nxt->data == value) {
			cur->next = nxt->next;
			delete nxt;
			nxt = cur->next;
		}
		if(nxt) {
			cur = cur->next;
			nxt = nxt->next;
		}
	}
}

void deleteAll(node &head) {
	if(head == NULL) {
		cout<<"Delete in an empty list not possible"<<endl;
		exit(1);
	}

	node cur = head;
	node nxt = cur->next;
	while(nxt) {
		delete cur;
		cur = nxt;
		nxt = nxt->next;
	}
	head = NULL;
}

void display(node head) {
	node cur = head;
	cout<<"list :";
	while(cur!= NULL) {
		cout<<cur->data<<"\t";
		cur = cur->next;
	}
	cout<<endl;
}

int main() {
	node root = NULL;
	insertAtEnd(root, 100);
	insertAtStart(root, 4);
	insertAtStart(root, 9);
	insertAtPos(root, 10, 2);
	insertAtPos(root, 15, 5);
	display(root);
	deleteAtEnd(root);
	display(root);
	deleteAtStart(root);
	display(root);
	deleteAtPos(root, 2);
	display(root);
	insertAtStart(root, 100);
	insertAtEnd(root, 100);
	insertAtPos(root, 100, 3);
	display(root);
	deleteValue(root, 100);
	display(root);
	insertAtEnd(root, 29);
	insertAtEnd(root, 29);
	insertAtEnd(root, 29);
	display(root);
	deleteAll(root);
	display(root);
	return 0;
}
