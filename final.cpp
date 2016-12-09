#ifndef _C
#define _C

#include <iostream>

#include "node.h"
#include "node.cpp"

using namespace std;

void replace(node *root, node *runner);
void print(node *root);
void deleteNode(node *root, node *runner);
int sizeOfList(node *root, node *runner);
void split(node *root, node *runner, int size);

int main(){
	node *root;
	node *runner;

	root = new node;
	runner = root;

	for(int i = 1; i <= 50; i++){
		node *n = new node;
		n->data = i;
		runner->next = n;
		runner = runner->next;
	}

	runner = root;

	if(runner != 0){
		while(runner != 0){
			runner = runner->next;
		}
		cout << endl;
	}
	print(root);
	replace(root, runner);
	deleteNode(root, runner);
	print(root);
	int size = sizeOfList(root, runner);
	split(root, runner, size);
}

void print(node *printData){
	node *runner = new node;
	cout << "List: ";
	runner = printData;
	if(runner != 0){
		while(runner != 0){
			cout << runner->data << " ";
			runner = runner->next;
		}
		cout << endl;
	}
}

void replace(node *root, node *runner){
	runner = root;
	if(runner != 0){
		while(runner != 0){
			if(runner->data % 3 == 0 && runner->data % 10 == 0 && runner->data > 0){
				runner->data = 1000;
			}
			else if ( runner->data % 3 == 0 && runner->data > 0){
				runner->data = 100;
			}
			else if ( runner->data % 10 == 0 && runner->data > 0){
				runner->data = 1000;
			}
			runner = runner->next;
		}
	}
}

void deleteNode(node *root, node *runner){
	runner = root;
	if(runner != NULL){
		node *temp = runner;
		while(temp->next != NULL){
			if(temp->next->data <= 50){
				runner->next = temp->next;
				runner = runner->next;
			}
			temp = temp->next;
		}
	}
	//deleting tail
	if(runner->next->data > 50){
		runner->next = NULL;
	}
}
int sizeOfList(node *root, node *runner){
	int size = 0;
	runner = root;

	while(runner->next != NULL){
		size++;
		runner = runner->next;
	}
	return size;
}
void split(node *root, node *runner, int size){
	int firstHalf = size/2;
	cout << "half: " << firstHalf << endl;
	int secondHalf = size - firstHalf;
	cout << "half: " << secondHalf << endl;
	int count = 1;

	node *list1Head;
	node *list1;
	list1 = list1Head;

	runner = root;

	while(count < firstHalf){
		node *temp = new node;
		temp->data = runner->next->data;
		list1->next =  temp;
		list1 = list1->next;
		runner = runner->next;
		cout << "hello:" << list1->data << endl;
		count++;
		
	}
	print(list1Head);

	node *list2Head;
	node *list2;
	list2 = list2Head;

	count = 0;
	while(count < secondHalf){
		node *temp = new node;
		temp->data = runner->next->data;
		list2->next =  temp;
		list2 = list2->next;
		runner = runner->next;
		cout << "list2:" << list2->data << endl;
		count++;
	}
	print(list2Head);
}

#endif











