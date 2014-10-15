#ifndef TRIE_H
#define TRIE_H

#include <unordered_map>
#include <string>
using namespace std;

class TrieNode {

public:
    TrieNode() {}
    //TrieNode(char c): value(c) {}

    bool insert(string str) {
        if(str.empty()) {
            if(leaf == true){
                return false;
            }
            else {
                leaf = true;
                return true;
            }
        }

        char first = str[0];
        TrieNode *child;
        if(children.find(first) == children.end()) {
            child = new TrieNode(/*first*/);
            children[first] = child;
        } else {
            child = children[first];
        }

        return child->insert(str.substr(1));
    }

    bool search(string str) {
        if(str.empty()) {
            return leaf;
        }
        char first = str[0];
        if(children.find(first) == children.end()) {
            return false;
        } else {
            return children[first]->search(str.substr(1));
        }
    }

    bool remove(string str) {
        if(str.empty()) {
            leaf = false;
            return true;
        }
        char first = str[0];
        if(children.find(first) == children.end()) {
            return false;
        } else {
            if(!children[first]->remove(str.substr(1))){
                return false;
            }
            else{
                if(children[first]->children.size() == 0 && !children[first]->leaf) {
                    delete children[first];
                    children.erase(first);
                }
                return true;
            }
        }
    }

private:
    //char value;
    bool leaf;
    unordered_map <char, TrieNode *> children;
};

class Trie {

public:
    Trie() {
        root = new TrieNode();
        size = 0;
    }

    bool insert(string str) {
        if(root->insert(str)) {
            size++;
            return true;
        } else {
            fprintf(stderr,"Error inserting duplicate :\"%s\"" " \n", str.c_str());
            return false;
        }

    }

    bool remove(string str) {
        if(root->remove(str) ) {
            size--;
            return true;
        } else {
            fprintf(stderr,"Error remove nonexistence :\"%s\"" " \n", str.c_str());
            return false;
        }
    }

    bool search(string str) {
        return root->search(str);
    }

    int getSize() {
        return size;
    }

private:
    TrieNode *root;
    int size;
};


#endif //TRIE_H
