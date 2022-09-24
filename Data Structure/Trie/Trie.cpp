#include<bits/stdc++.h>
using namespace std;

class Node{
    private:
        bool flag;
        vector<Node*> nodeV;
       
    public:
        Node(){
            nodeV = vector<Node*>(26,NULL);
        }
        bool containsKey(char c){
            return nodeV[c-'a']!=NULL;
        }
        void put(Node* node,char c){
            nodeV[c-'a']=node;
            return;
        }
        Node* get(char c){
            return nodeV[c-'a'];
        }
        void setEnd(){
            flag = true;
        }
        bool isEnd(){
            return flag;
        }

};

class Trie{
    private:
        Node* root;
       
    public:
        Trie(){
            root = new Node();
        }
        void insertWord(string word){
            Node* node = root;
            for(char c : word){
                if(!node->containsKey(c)){
                    node->put(new Node(),c);
                    
                }   
                node = node->get(c);
            }
            node->setEnd();
        }
        bool searchWord(string word){
            Node* node = root;
            for(char c : word){
                if(node->containsKey(c)){
                    node = node->get(c);
                }   
                else return false;
            }
            return node->isEnd();
        }
        bool startsWithWord(string word){
            Node* node = root;
            for(char c : word){
                if(node->containsKey(c)){
                    node = node->get(c);
                }   
                else return false;
            }
            return true;
        }

};

int main(){
    cout<<"hello world\n";
    Trie* trie = new Trie();
    trie->insertWord("bus");
    trie->insertWord("buses");
    trie->insertWord("truck");
    cout<<trie->searchWord("bu")<<endl;
    cout<<trie->searchWord("bus")<<endl;
    cout<<trie->searchWord("buses")<<endl;
    cout<<trie->startsWithWord("buse")<<endl;
    cout<<trie->searchWord("truck")<<endl;
    return 0;
}