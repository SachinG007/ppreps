/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/* The structure of a BST Node is as follows:
struct Node {
  int data;
  Node * right, * left;
}; */

Node *delUtil(Node *root){
    Node *current = root;
    while(current->left!=NULL){
        current = current->left;
    }
    return current;
}

Node * deleteNode(Node *root,  int x)
{
  if(root==NULL){
      return root;
  }
  bool data_eq = false;
  
  if(root->data == x){
      data_eq = true;
  }

  if(data_eq){
      if (root->left == NULL && root->right == NULL){
          free(root);
          return NULL;
      } 
      if(root-> left == NULL && root->right !=NULL){
          Node *temp = root->right ;
          free(root);
          return temp;
      }
      if(root-> left != NULL && root->right ==NULL){
          Node *temp = root->left;
          free(root);
          return temp;
      }
      if(root-> left != NULL && root->right !=NULL){
          Node *temp = delUtil(root->right);
          root->data = temp->data;
          root->right = deleteNode(root->right, temp->data);
          return root;
          
      }
  }
  
  else if(root->data<x){
      root->right = deleteNode(root->right, x);
  }
  else{
      root->left = deleteNode(root->left,  x);
  }
  return root;
}