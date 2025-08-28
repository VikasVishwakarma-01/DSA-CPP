#include<bits/stdc++.h>
using namespace std;
class Node{
public:
    int val;
    Node* left;
    Node* right;
    Node(int val){
        this->val=val;
        this->left=NULL;
        this->right=NULL;
    }
};
void displayTree(Node* root){
    if(root==NULL) return;
    cout<<root->val<<" ";
    displayTree(root->left);
    displayTree(root->right);
}
int sum(Node* root){
    if(root==NULL) return 0;
    return root->val + sum(root->left) + sum(root->right);
}
int l=0;
int size1(Node* root){
    if(root==NULL) return l;
    l++;
    size1(root->left);
    size1(root->right);
}
int size2(Node* root){
    if(root==NULL) return 0;
    return 1 + size2(root->left) + size2(root->right);
}
int maxInTree(Node* root){
    if(root==NULL) return INT_MIN;
    int lMax = maxInTree(root->left);
    int rMax = maxInTree(root->right);
    return max(root->val,max(lMax,rMax));
}
int levels(Node* root){
    if(root==NULL) return 0;
    return 1 + max(levels(root->left),levels(root->right));
}

void displayTreeNthLevel(Node* root,int len){
    if(root==NULL) return;
    len--;
    if(len==0){
        cout<<root->val<<" ";
    }
    displayTreeNthLevel(root->left,len);
    displayTreeNthLevel(root->right,len);
}
int main(){
    Node* a = new Node(1);
    Node* b = new Node(2);
    Node* c = new Node(3);
    Node* d = new Node(4);
    Node* e = new Node(5);
    Node* f = new Node(6);
    Node* g = new Node(7);
    a->left=b;
    a->right=c;
    b->left=d;
    b->right=e;
    c->left=f;
    c->right=g;
    displayTree(a);
    cout<<endl;
    // cout<<sum(a)<<endl;
    // cout<<size1(a)<<endl;
    // cout<<size2(a)<<endl;
    // cout<<maxInTree(a);
    // cout<<endl;
    // cout<<levels(a);
    // cout<<endl;
    // cout<<levels(a->left);
    // cout<<endl;
    // cout<<levels(a->right);

    displayTreeNthLevel(a,3);



}