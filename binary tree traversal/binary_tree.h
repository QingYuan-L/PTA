#ifndef BINARY_TREE_H 
#define BINARY_TREE_H 

typedef int ElemType;
typedef struct btree_node {
    ElemType data;
    btree left;
    btree right;
} btree_node;

typedef btree_node *btree;
void btree_traverse_stack(btree bt);//非递归遍历二叉树
void btree_traverse(btree bt);//递归遍历二叉树

#endif	// BINARY_TREE_H