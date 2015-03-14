#ifndef SORT_TREE_H_
	#define SORT_TREE_H_
	#include<stdio.h>
	typedef int datatype;
	typedef struct _sortTree_node{
		datatype value;
		struct _sortTree_node* left;
		struct _sortTree_node* right;
	}sortTree_node;
	typedef sortTree_node* sortTree_root;
	extern void initTree(sortTree_node* p);
	extern void printTree(sortTree_root p);
	extern bool searchTree(sortTree_root root, datatype dat);
	extern int getTreeDepth(sortTree_root p);
	extern sortTree_node* _insertTree(sortTree_root root,
		sortTree_node* now,datatype dat);
	#define insertTree(a,b) _insertTree((a),(a),b)
	extern bool _deleteTree(sortTree_root root,
			sortTree_node* now,datatype value); 
	#define deleteTree(a,b) _deleteTree((a),(a),b)
#endif
