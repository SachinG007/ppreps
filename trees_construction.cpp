#include <iostream>
#include <list>
using namespace std;

struct Node{
	int data;
	struct Node *left,*right;
};

struct Node* newNode(int data){

	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

	newNode->data = data;
	newNode->left = NULL:
	new
}
