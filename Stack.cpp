#include <bits/stdc++.h>

// Last In first Out

using namespace std;

struct Node{
	int data;
	Node* next;
};

struct Node* createNode(int data){
	struct Node* newNode = NULL;
	newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
}

struct Node* push(struct Node* head,int data){
    if(head == NULL){
		head = createNode(data);
		return head;
	}
	else{
		struct Node* temp = createNode(data);
		temp->next = head;
		head = temp;
	}
	return head;
}

struct Node* pop(struct Node* head){
	if(head == NULL){
		return head;
	}
	else{
		struct Node* temp = head;
		while(temp->next->next != NULL){
			temp = temp->next;
		}
		temp->next = NULL;
	}
	return head;
};

void display(struct Node* head){
	Node* temp = head;
	while(temp != NULL){
		cout << temp->data << " ";
		temp = temp->next;
	}
	return;
}

int main(){
	struct Node* list = NULL;
	list = push(list,5);
	list = push(list,2);
	list = push(list,4);
	list = push(list,3);
	list = push(list,1);
	list = pop(list);
	list = pop(list);
	display(list);
}


