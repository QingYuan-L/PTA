#include "binary_tree.h"
#include <iostream>
#include <stack>
using namespace std;

void btree_traverse(btree bt){
    if(bt){
        cout<<bt->data<<endl;//先序遍历二叉树；
        btree_traverse(bt->left);
        //cout<<bt->data<<endl;//中序遍历二叉树；
        btree_traverse(bt->right);
        //cout<<bt->data<<endl;//后序遍历二叉树；
    }
} 
void btree_traverse_stack(btree bt){
    btree temp_tree=bt;
    stack<btree> node_stack;
    while(temp_tree||!node_stack.empty()){
        while(temp_tree){
            cout<<temp_tree->data<<endl;//先序遍历二叉树
            node_stack.push(temp_tree);
            temp_tree = temp_tree->left;
        }
        if(!node_stack.empty()){
            temp_tree = node_stack.top();
            //cout<<temp_tree->data<<endl;//中序遍历二叉树
            node_stack.pop();
            temp_tree = temp_tree->right;
        }
    }
}