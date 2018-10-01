/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */
// A wrapper over leftViewUtil()

void leftViewUtil(Node *root, int level, bool first_level[]){
    if(root == NULL){
        return;
    }
    
    if(!first_level[level]){
        cout << root->data << " ";
        first_level[level] = true;
    }
    // level = level + 1;
    leftViewUtil(root->left,level+1,first_level);
    leftViewUtil(root->right,level+1,first_level);
}

void leftView(Node *root)
{
    bool first_level[1000];
    for(int i=0;i<1000;i++){
        first_level[i] = false;
    }
    int level = 0;
   // Your code here
    leftViewUtil(root,level,first_level);
   
}