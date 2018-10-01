/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

//User function Template for C++
/*
struct Node
{
    int data;
    struct Node *left, *right;
};
*/
// your task is to complete this function

void mySwap(Node *root, Node * &firstPtr, Node * &secondPtr)
{
    if(root == NULL){
        return;
    }
    
    if(root->left == NULL && root->right == NULL)
    {
        if(firstPtr == NULL)
        {
            firstPtr = root;
        }
        
        else if(secondPtr == NULL)
        {
            secondPtr = root;
        }
        
        if(firstPtr && secondPtr)
        {
            int temp = firstPtr -> data;
            firstPtr-> data = secondPtr -> data;
            secondPtr -> data = temp;
            firstPtr = NULL;
            secondPtr = NULL;
        }
    }
    
    mySwap(root->left,firstPtr,secondPtr);
    mySwap(root->right,firstPtr,secondPtr);
}

void pairwiseSwap(Node *root)
{
    // code here
    if(root == NULL)
    {
        return;
    }
    
    Node *firstPtr = NULL;
    Node *secondPtr = NULL;
    
    mySwap(root,firstPtr,secondPtr);
    
}