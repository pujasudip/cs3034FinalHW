#ifndef _C
#define _C

#include <iostream>

#include "node.h"
#include "node.cpp"

using namespace std;

void replace(node *root, node *runner);
void print(node *root, node *runner);
void deleteNode(node *root, node *runner);

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
	print(root, runner);
	replace(root, runner);
	deleteNode(root, runner);
	print(root, runner);
}

void print(node *root, node *runner){
	cout << "List: ";
	runner = root;
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
	print(root, runner);
}

void deleteNode(node *root, node *runner){
	while(root->data > 50){
		node *tmp = root->next;
		delete root;
		root = tmp;
	}
	runner = root;

	node *nn = root->next;

	while(runner != NULL){
		while(nn->data > 50){
			nn = nn->next;
		}
		runner = nn->next;
	}



}

#endif