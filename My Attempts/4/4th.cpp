#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    struct node* left;
    struct node* right;
};
struct node* newNode(int data){
    struct node* temp = new struct node;
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
void modifyBSTUtil(struct node* root, int* sum){
    if (root == NULL) return;
    modifyBSTUtil(root->right, sum);
    *sum = *sum + root->data;
    root->data = *sum;
    modifyBSTUtil(root->left, sum);
}
void modifyBST(struct node* root){
    int sum = 0;
    modifyBSTUtil(root, &sum);
}
void inorder(struct node* root){
    if (root != NULL){
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}
int main(){
    struct node* root = newNode(11);
    root->left = newNode(2);
    root->right = newNode(29);
    root->left->left = newNode(1);
    root->left->right = newNode(7);
    root->right->left = newNode(15);
    root->right->right = newNode(40);
    root->right->right->left = newNode(35);
    cout << "Inorder traversal of the original tree: " << endl;
    inorder(root);
 
    modifyBST(root);
 
    cout << "\nInorder traversal of the modified tree: " << endl;
    inorder(root);
 
    return 0;
}