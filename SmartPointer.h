#ifndef SMARTPOINTER_H
#define SMARTPOINTER_H

#include <iostream>

template <class T> 
class SmartPointer {
private:
	T *obj;
	unsigned int * ref_count;
public:
	SmartPointer(T * _obj) {
		obj = obj;
		*ref_count = 1;
	}
	~SmartPointer() {
		remove();
	}

	SmartPointer<T> & operator= (SmartPointer<T> & ptr) {
		if(this != &ptr) {
			if(ref_count && *ref_count > 0) {
				remove();
			}
			obj = ptr.obj;
			ref_count = ptr.ref_count;
			(*ref_count)++;
		}

		return *this;
	}
private:
	void remove() {
		(*ref_count)--;
		if(*ref_count == 0) {
			free(obj);
			free(ref_count);
			obj = NULL;
			ref_count = NULL;
		}
	}
};

#endif