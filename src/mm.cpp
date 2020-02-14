//This file provide some functions to memory management to avoid memory leaks

#include "../include/mm.h"
#include <string>
#include <vector>


Pointer* pointers = NULL;

void addPointer(void* p){
	Pointer* aux = pointers;
	if(pointers == NULL){
		pointers = (Pointer*) malloc(sizeof(Pointer));
		pointers->ptr = p;
		pointers->next = NULL;
	}
	else{
	
		while(aux->next!=NULL){
			aux = aux->next;
		}
		aux->next= (Pointer*) malloc(sizeof(Pointer));
		aux->next->ptr = p;
		aux->next->next = NULL;
	}
}

void removePointer(void* p){
	Pointer* aux = pointers;
	Pointer* temp = pointers;
	if(aux!=NULL){
		if(aux->ptr == p){
			pointers = pointers->next;
			free(aux);
		}
		else{
			aux = aux->next;
			
			while(aux!= NULL && aux->ptr != p){
				temp = aux;
				aux = aux->next;
			}	
			if(aux!=NULL && aux->ptr == p){
				temp->next = aux->next;
				free(aux);
			}
		}
	}
}

void* allocate(size_t s)
{
	void* p = malloc(s);	
	addPointer(p);
	return p;
}


void* reallocate(void* ptr, size_t size)
{
	void* p = realloc(ptr, size);
	removePointer(ptr);
	addPointer(p);
	return p;
}

void deallocate_all()
{
	Pointer* aux;
	while(pointers!=NULL){
		aux = pointers;
		free(pointers->ptr);
		pointers = pointers->next;
		free(aux);
	}
}
