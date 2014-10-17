/**
 * Implementation for skiplist
 * 
 * http://en.wikipedia.org/wiki/Skip_list
 * 
 */
#ifndef SKIP_LIST_H
#define SKIP_LIST_H

#include <cstdlib>
#include <ctime>
#include <climits>

 class SkipListNode {
 public:
 	int elem;
 	int level;
 	SkipListNode **forward;

 	SkipListNode(int data, int lev) {
 		elem = data;
 		level = lev;
 		forward = new SkipListNode*[lev];
 		memset(forward, 0, level*sizeof(SkipListNode*));
 	}
 };

 class SkipList
 {
 private:
 	int MAX_LEVEL;
 	double UP_PROB;
 	SkipListNode* head;
 	SkipListNode* tail;
 	int _size;

 public:
 	SkipList(int maxLevel, double probability) {
 		srand(time(NULL));

 		MAX_LEVEL = maxLevel;
 		UP_PROB = probability;
 		head = new SkipListNode(INT_MIN, MAX_LEVEL);
 		tail = new SkipListNode(INT_MAX, MAX_LEVEL);
 		int _size = 0;

 		for(int i = 0; i < MAX_LEVEL; ++i) {
 			head->forward[i] = tail;
 		}
 	}

 	/**
 	 * @brief find an element in the list
 	 * 
 	 * @param elem 
 	 * @return true if found, false otherwise
 	 */
 	bool find(int elem) {
 		SkipListNode *curr = head;
 		for(int i = MAX_LEVEL - 1; i >= 0; --i) {
 			SkipListNode *next = curr->forward[i];
 			while(next->elem < elem) {
 				curr = next;
 				next = curr->forward[i];
 			}
 		}

 		curr = curr->forward[0];
 		return curr->elem == elem;
 	}

 	/**
 	 * @brief insert a new element in the list
 	 * 
 	 * @param newElem 
 	 * @return true if succeed, false if has duplicate
 	 */
 	bool insert(int newElem) {
 		SkipListNode *curr = head;
 		SkipListNode **prevs = new SkipListNode*[MAX_LEVEL];

 		for(int i = MAX_LEVEL - 1; i >= 0; --i) {
 			SkipListNode *next = curr->forward[i];
 			while(next->elem < newElem) {
 				curr = next;
 				next = curr->forward[i];
 			}
 			prevs[i] = curr;
 		}

		// element already exists
 		if(curr->forward[0]->elem == newElem) {
 			return false;
 		}

 		int newLevel = generateRandomLevel();
 		SkipListNode * newNode = new SkipListNode(newElem, newLevel+1);
 		for(int i = 0; i <= newLevel; ++i) {
 			newNode->forward[i] = prevs[i]->forward[i];
 			prevs[i]->forward[i] = newNode;
 		}

 		_size++;

 		return true;
 	}

 	/**
 	 * @brief remove an element in the list
 	 * 
 	 * @param elem 
 	 * @return true if removed, false if doesn't exist
 	 */
 	bool remove(int elem) {
 		SkipListNode *curr = head;
 		SkipListNode **prevs = new SkipListNode*[MAX_LEVEL];

 		for(int i = MAX_LEVEL - 1; i >= 0; --i) {
 			SkipListNode *next = curr->forward[i];
 			while(next->elem < elem) {
 				curr = next;
 				next = curr->forward[i];
 			}
 			prevs[i] = curr;
 		}

 		// node to be deleted
		curr = curr->forward[0];
 		if(curr->elem != elem) {
 			return false;
 		}

 		for(int i = 0; i < curr->level; ++i) {
 			prevs[i]->forward[i] = curr->forward[i];
 		}
 		delete curr;
 		_size--;

 		return true;
 	}

 	int size() {
 		return _size;
 	}

 	/**
 	 * @brief print list information by level
 	 */
 	void print() {
 		for(int i = MAX_LEVEL -1; i >= 0; --i) {
 			SkipListNode * tmp = head;
 			printf("Level %d: ", i);
 			while(1) {
 				if(tmp == tail) {
 					printf("%d\n", tmp->elem);
 					break;
 				} else {
 					printf("%d -> ", tmp->elem);
 				}
 				tmp = tmp->forward[i];
 			}
 		}
 	}
 private:
 	/**
 	 * @brief generate random double between [0, 1)
 	 */
 	double getRandom() {
 		return ((double)(rand()))/INT_MAX;
 	}
 	/**
 	 * @brief generate a randome int level number between [0, MAX_LEVEL)
 	 */
 	int generateRandomLevel() {
 		int newLevel = 0;
 		while(newLevel < MAX_LEVEL-1 && getRandom() < UP_PROB) {
 			newLevel++;
 		}
 		return newLevel;
 	}
 };

#endif