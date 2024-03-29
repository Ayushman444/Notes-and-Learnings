#include<bits/stdc++.h>
using namespace std;

//apple
//apple
//apps
//apps

//countprefix and endwith

struct Node{
    Node* links[26];
    int cntEndWith = 0;
    int cntPrefix = 0;

    bool containsKey(char ch){
        return links[ch-'a'];
    }
    Node* get(char ch){
        return links[ch-'a'];
    }
    void put(char ch , Node* node){
        links[ch-'a' ] = node;
    }
    void increaseEnd(){
        cntEndWith++;
    }
    void increasePrefix(){
        cntPrefix++;
    }
    void deleteEnd(){
        cntEndWith--;
    }
    void reducePrefix(){
        cntPrefix--;
    }
    int getEnd(){
        return cntEndWith;
    }
    int getPrefix(){
        return cntPrefix;
    }
};

class Trie{
    private: Node* root;
    public:

    Trie(){

    }
    void insert(string &word){
        Node* node = root;
        for(int i=0;i<word.length();i++){
            if(!node->containsKey(word[i])){
                node->put(word[i], new Node());
            }
            node = node->get(word[i]);
            node->increasePrefix();
        }
        node->increaseEnd();
    }

    int countWordsEqualTo(string &word){
        Node* node = root;
        for(int i =0;i<word.size();i++){
            if(node->containsKey(word[i])){
                node = node->get(word[i]);
            }else{
                return 0;
            }
        }
        return node->getEnd();
    }

    int countWordsStartingWith(string &word){
        Node* node = root;
        for(int i =0;i<word.size();i++){
            if(node->containsKey(word[i])){
                node = node->get(word[i]);
            }
            else return 0;
        }
        return node->getPrefix();
    }

    void erase(string & word){
        Node* node  = root;
        for(int i=0;i<word.size();i++){
            if(node -> containsKey(word[i])){
                node = node->get(word[i]);
                node->reducePrefix();
            }else{
                return;
            }
        }
        node->deleteEnd();
    }
};
int main(){
    
return 0;
}