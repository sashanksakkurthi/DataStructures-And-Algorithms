#include <bits/stdc++.h>

using namespace std;

struct Node{
	int data;
	struct Node* next;
};

struct Node* createNode(int k){
	struct Node *head = NULL;
	head = (struct Node*)malloc(sizeof(struct Node));
	head->data=k;
	head->next=NULL;
	return head;
}

int hashfun(int h,int size){
	return h%size;
}

void insert(struct Node *HashTable[],int k,int size){
	int index = hashfun(k,size);
	struct Node* temp = createNode(k);
	if(HashTable[index] == NULL){
		HashTable[index] = temp;
	}
	else{
		temp->next=HashTable[index];
		HashTable[index]=temp;
	}
}

void print(struct Node *HashTable[],int size){
	for (int i = 0; i < size; ++i){
		struct Node* temp = HashTable[i];
		if(i == 0){
			cout << "How many elements to insert into HastableList number 0 :" << "\t" ;
			while(temp != NULL){
				cout << "\t" << temp->data << " ";
				temp=temp->next;
			}
			cout << "" << endl;
		}
		else{
			cout << "List number " << i << ":" << "\t";
			while(temp != NULL){
				cout << "\t" << temp->data << " ";
				temp=temp->next;
			}
			cout << "" << endl;
		}
	}
}

int main(){
	int size;
    cin >> size;
	struct Node *HashTable[size];
	for (int i = 0; i < size; ++i)
	{
		HashTable[i] = NULL;
	}
	int number;
	cin >> number;
	for (int i = 0; i < size; ++i)
	{
		int x;
		cin >> x;
		insert(HashTable,x,size);
	}
	print(HashTable,size);
	if(size == 0){
		cout << "How many elements to insert into Hastable" << endl;
	}
}

