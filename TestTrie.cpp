#include <iostream>
#include <string>
using namespace std;

#include "Trie.h"

int main(int argc, char const *argv[])
{
	Trie trie;
	cout << "add \"find\"..." << endl;
	trie.insert("find");
	cout << "add \"fine\"..." << endl; 
	trie.insert("fine");
	cout << "add \"hello\"..." << endl;
	trie.insert("hello");
	cout << "add \"finding\"..." << endl;
	trie.insert("finding");
	cout << "add \"hello\"..." << endl;
	trie.insert("hello");


	cout << endl;
	cout << "search \"find\": ";
	cout << trie.search("find") << endl;
	cout << "search \"finding\": ";
	cout << trie.search("finding") << endl;
	cout << "search \"hello\": ";
	cout << trie.search("hello") << endl;

	cout << "remove \"hello\"... " << endl;
	trie.remove("hello");
	cout << "search \"hello\": ";
	cout << trie.search("hello") << endl;

	cout << "remove \"finding\"... " << endl;
	trie.remove("finding");
	cout << "search \"finding\": ";
	cout << trie.search("finding") << endl;
	cout << "search \"find\": ";
	cout << trie.search("find") << endl;

	return 0;
}