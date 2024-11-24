#include "rbtree.h"
#include "rbtree.c"
#include <stdio.h>
void test_find_erase_rand(const size_t n, const unsigned int seed) {
  srand(seed);
  rbtree *t = new_rbtree();
  key_t *arr = calloc(n, sizeof(key_t));
  for (int i = 0; i < n; i++) {
    arr[i] = rand();
    printf("%d ", arr[i]);
  }
  for (int i = 0; i < n; i++) {
    node_t *p = rbtree_insert(t, arr[i]);
  }
  
  for (int i = 0; i < n; i++) {
    node_t *p = rbtree_find(t, arr[i]);
    rbtree_erase(t, p);
  }
  printTree(t,t->root);
  delete_rbtree(t);
}
int main(){
    test_find_erase_rand(8000000, 19);
    printf("SUCCESS");
}