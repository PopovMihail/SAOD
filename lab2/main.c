#include "bstree.h"
#include <stdio.h>
#include <stdlib.h>



int main() 
{
	bstree *tree, *node;
	tree = bstree_create("Tigr", 180);
	
	bstree_add(tree, "Lev", 200);
	bstree_add(tree, "Volk", 60);
	bstree_add(tree, "Suslik", 5);
	bstree_add(tree, "Rabit", 2);
	
	node = bstree_lookup(tree, "Rabit");
	printf("Value = %d\n", node->value);
	
	node = bstree_max(tree);
	printf("Min: value = %s\n", node->key);

	return 0;
}


