#include<iostream>
using namespace std;

class Node{
public:
    int val;
    Node* left;
    Node* right;
    Node(int val){
        this->val = val;
        this->right = NULL;
        this->left = NULL;
    }
};
int main(){
    Node* a = new Node(10);
    Node* b = new Node(20); 
    Node* c = new Node(30);
    Node* d = new Node(40);
}