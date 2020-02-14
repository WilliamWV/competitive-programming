#ifndef MM_H
#define MM_H

#include <cstdlib>

// Define a linked list of pointers
typedef struct pointer{
	void* ptr;
	struct pointer* next;
}Pointer;

void* allocate(size_t s);

void* reallocate(void* ptr, size_t size);

void deallocate_all();

#endif