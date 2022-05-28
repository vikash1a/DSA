#include <bits/stdc++.h>
using namespace std;

class Node
{
    public:
        int val;
        Node* next;
        Node(int x){
            val = x;
            next = NULL;
        }
};
void addNode(Node* node,Node* nodeToBeAdded){
    node->next = nodeToBeAdded;
    return;
}
void addNode(Node* node,int nodeToBeAdded){
    node->next = new Node(nodeToBeAdded);
    return;
}
void deleteNode(Node* node, Node* nodeTobeDeleted){
    while(node!=NULL){
        if(node->next == nodeTobeDeleted){
            node->next = node->next->next;
            return;
        }
        node = node->next;
    }
    return;
}
void print(Node* node){
    while(node!=NULL){
        cout<<node->val<<" ";
        node = node->next;
    }
    cout<<endl;
    return;
}


int main()
{
    cout<<"Hello World\n";

    Node* node = new Node(0);
    addNode(node,new Node(1));
    addNode(node->next,2);
    print(node);
    deleteNode(node,node->next);
    print(node);

    return 0;
}