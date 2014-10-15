#ifndef SFFIX_TREE_H
#define SFFIX_TREE_H

#include <vector>
#include <unordered_map>

class SuffixTreeNode {

public:
	//SuffixTreeNode() {}
	SuffixTreeNode(/*char c*/): /*value(c),*/ leaf(false) {}

	void insert(string str, int index) {
		indexes.push_back(index);
		if(str.empty()) {
			leaf = true;
			return;
		}

		char first = str[0];
		SuffixTreeNode *child;
		if(children.find(first) != children.end()) {
			child = children[first];
		} else {
			child = new SuffixTreeNode(/*first*/);
			children[first] = child;
		}
		child->insert(str.substr(1), index);
	}

	std::vector<int> search(string str) {
		if(str.empty()) return indexes;
		char first = str[0];
		if(children.find(first) == children.end()) {
			return std::vector<int>();
		} else {
			return children[first]->search(str.substr(1));
		}
	}

	bool isSuffix(string str) {
		if(str.empty()) return leaf;
		char first = str[0];
		if(children.find(first) == children.end()) {
			return false;
		} else {
			return children[first]->isSuffix(str.substr(1));
		}
	}

private:
	//char value;
	bool leaf;
	std::vector<int> indexes;
	std::unordered_map<char, SuffixTreeNode*> children;
};

class SuffixTree {

public:
	SuffixTree(string str) {
		root = new SuffixTreeNode();
		for(int i = 0; i < str.size()-1; ++i) {
			root->insert(str.substr(i), i);
		}
	}

	std::vector<int> search(string str) {
		return root->search(str);
	}

	bool isSuffix(string str) {
		return root->isSuffix(str);
	}

private:
	SuffixTreeNode *root;
};

#endif //SFFIX_TREE_H
