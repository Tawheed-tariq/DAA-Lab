#include<iostream>
#include<bits/stdc++.h>
using namespace std;


class node{
    public:
    int data;
    node *left;
    node *right;
    node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

//insert node to BST
node *insertIntoBST(node* &root, int ele){
    if(root == NULL){
        root = new node(ele);
        return root;
    }
    if(ele > root->data){
        insertIntoBST(root->right, ele);
    }else{
        insertIntoBST(root->left, ele);
    }
    return root;
}
//take inputs
void takeInput(node* &root){
    int ele;
    cout << "enter elements : ";
    cin>> ele;
    while(ele != -1){
        insertIntoBST(root, ele);
        cin >> ele;
    }
}


//inorder traversal LNR(left node right)
void inOrder(node *root){
    if(root == NULL){
        return;
    }
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

int main(){
    node *root = NULL;
    takeInput(root);
    inOrder(root);
}