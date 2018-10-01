
// C++ program to create a Complete Binary tree from its Linked List 
// Representation 
#include <iostream> 
#include <string> 
#include <queue> 
using namespace std;

struct ListNode{
	int data;
	ListNode* next;
};

struct BinaryTreeNode{
	int data;
	BinaryTreeNode *left, *right;

};

void push(struct ListNode** head_ref, int data){

	struct ListNode* newNode = new ListNode;
	newNode->data = data;
	newNode->next = *head_ref;
	*head_ref = newNode;
}

BinaryTreeNode* newBinaryTreeNode(int data){
	BinaryTreeNode *temp = new BinaryTreeNode;
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;
}

void convertList2Binary(ListNode *head, BinaryTreeNode* &root){

	queue<BinaryTreeNode *> q;

	if(head == NULL){
		root = NULL;
		return;
	}

	root = newBinaryTreeNode(head->data);
	q.push(root);

	head = head->next;

	while(head){

		BinaryTreeNode *parent = q.front();
		q.pop();

		BinaryTreeNode *left = NULL;
		BinaryTreeNode *right = NULL;

        left = newBinaryTreeNode(head->data); 
		q.push(left);

		head = head->next;
		if(head){

            right = newBinaryTreeNode(head->data); 
			q.push(right);
			head = head->next;
		}

		parent->left = left;
		parent->right = right;

	}
}
	// Utility function to traverse the binary tree after conversion 
void inorderTraversal(BinaryTreeNode* root) 
{ 
    if (root) 
    { 
        inorderTraversal( root->left ); 
        cout << root->data << " "; 
        inorderTraversal( root->right ); 
    } 
} 
  
// Driver program to test above functions 
int main() 
{ 
    // create a linked list shown in above diagram 
    struct ListNode* head = NULL; 
    push(&head, 36);  /* Last node of Linked List */
    push(&head, 30); 
    push(&head, 25); 
    push(&head, 15); 
    push(&head, 12); 
    push(&head, 10); /* First node of Linked List */
  
    BinaryTreeNode *root; 
    convertList2Binary(head, root); 
  
    cout << "Inorder Traversal of the constructed Binary Tree is: \n"; 
    inorderTraversal(root); 
    return 0; 
} 
