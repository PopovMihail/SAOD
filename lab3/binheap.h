#ifndef BINHEAP
#define BINHEAP

struct heapnode {
	int key;
	char *value;
};

/* Priority (key) */
/* Data */
struct heap {
	int maxsize;
	int nnodes;
	struct heapnode *nodes;
};

struct heap *heap_create(int maxsize);
void heap_free(struct heap *h);
void heap_swap(struct heapnode *a, struct heapnode *b);
struct heapnode *heap_max(struct heap *h);
int heap_insert(struct heap *h, int key, char *value) ;
struct heapnode heap_extract_max(struct heap *h);
void heap_heapify(struct heap *h, int index);


#endif
