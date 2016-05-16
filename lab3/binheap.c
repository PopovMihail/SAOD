#include <stdlib.h>
#include "binheap.h"
//создание пустой кучи
struct heap *heap_create(int maxsize) {
	struct heap *h;
	h = malloc(sizeof(*h));
	if (h != NULL) {
		h->maxsize = maxsize;
		h->nnodes = 0;
	/* Heap nodes [0, 1, ..., maxsize] */
		h->nodes = malloc(sizeof(*h->nodes) * (maxsize + 1));
		if (h->nodes == NULL) {
			free(h);
			return NULL;
		}
	}
	return h;
}
//удаление кучи
void heap_free(struct heap *h) {
	free(h->nodes);
	free(h);
}

void heap_swap(struct heapnode *a, struct heapnode *b) {
	struct heapnode temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

//поиск макс элемента
struct heapnode *heap_max(struct heap *h) {
	if (h->nnodes == 0)
	return NULL;
	return &h->nodes[1];
}
//вставка элемента в кучу
int heap_insert(struct heap *h, int key, char *value) {
	if (h->nnodes >= h->maxsize) {
	/* Heap overflow */
		return -1;
	}
		h->nnodes++;
		h->nodes[h->nnodes].key = key;
		h->nodes[h->nnodes].value = value;
		// HeapifyUp
	for (int i = h->nnodes; i > 1 && h->nodes[i].key > h->nodes[i / 2].key; i = i / 2) {
		heap_swap(&h->nodes[i], &h->nodes[i / 2]);
	}
	return 0;
}

//удаление макс эелемента
struct heapnode heap_extract_max(struct heap *h) {
	if (h->nnodes == 0)
		return (struct heapnode){0, NULL};
	struct heapnode maxnode = h->nodes[1];
	h->nodes[1] = h->nodes[h->nnodes];
	h->nnodes--;
	heap_heapify(h, 1);
	return maxnode;
}
//восстановление свойств кучи

void heap_heapify(struct heap *h, int index) {
	for (;;) {
		int left = 2 * index;
		int right = 2 * index + 1;
		// Find largest key: A[index], A[left] and A[right]
		int largest = index;
		if (left <= h->nnodes && h->nodes[left].key > h->nodes[index].key) {
			largest = left; 
		}
		if (right <= h->nnodes && h->nodes[right].key > h->nodes[largest].key) {
			largest = right; 
		}
		if (largest == index)
			break;
		heap_swap(&h->nodes[index], &h->nodes[largest]);
		index = largest;
	}
}
