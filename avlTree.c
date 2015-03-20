#include <stdio.h>  
#include <stdlib.h> 
typedef int datatype;
typedef struct _avlTree_node
{
    datatype value;
    int nHeight;    /*树的平衡度*/
    struct _avlTree_node *left;
    struct _avlTree_node *right;
}avlTree_node;
typedef avlTree_node* avlTree_root;
int _printTree_byLevel(avlTree_root T, int level) {  
    if (!T || level <= 0){
        return 0;  
    }
    if (1 == level) {
        printf("%d\t",T->value);
        return 1;  
    }  
    return _printTree_byLevel(T->left, level - 1) 
        + _printTree_byLevel(T->right, level - 1);  
}
void printTree_byLevel(avlTree_root T) {  
     int i = 1;   
    while(1) {
        if(1 != i){
        printf("------%d-------\n",(i-1));
        }
        if (!_printTree_byLevel(T, i)){
           break; 
        }
        i++;   
    }    
    printf("\n");
}  

void initAvlTree(avlTree_node* p){
    p->nHeight = 1 ;
    p->left = NULL;
    p->right = NULL;
}
int getMax(int x,int y){
    return x > y ? x: y;
}
int getAvlTreeHeight(avlTree_node* p){
    if(NULL == p){
        return 0;
    }
    else{
        return p->nHeight;
    }
}
//向左旋转
avlTree_node* _rotateAvlTree_L(avlTree_node* p){  
    //以p为根节点的二叉排序树进行单向左旋处理  
    avlTree_node *r_child=p->right;  
    p->right=r_child->left;  
    r_child->left = p; 
    //需要更新节点高度值
    p->nHeight = getMax(getAvlTreeHeight(p->left),
            getAvlTreeHeight(p->right))+1;
    r_child->nHeight = getMax(getAvlTreeHeight(r_child->left),
            getAvlTreeHeight(r_child->right))+1;
    return r_child;
}
//向右旋转
avlTree_node* _rotateAvlTree_R(avlTree_node* p){
    avlTree_node* l_child = p->left;
    p->left = l_child->right;
    l_child->right = p;
    //需要更新节点高度值
    p->nHeight = getMax(getAvlTreeHeight(p->left),
            getAvlTreeHeight(p->right))+1;
    l_child->nHeight = getMax(getAvlTreeHeight(l_child->left),
            getAvlTreeHeight(l_child->right))+1;
    return l_child;
}
//LR型 左旋+右旋
avlTree_node* _rotateAvlTree_LR(avlTree_node* p){
    p->left = _rotateAvlTree_L(p->left);
    return _rotateAvlTree_R(p);
}
//RL型 右旋+左旋
avlTree_node* _rotateAvlTree_RL(avlTree_node* p){
    p->right = _rotateAvlTree_R(p->right);
    return _rotateAvlTree_L(p);
}
/**
 * 插入
 */
avlTree_root insertAvlTree(avlTree_node* p,datatype value){
    if (NULL == p){
        p = (avlTree_node*)malloc(sizeof(avlTree_node));
        initAvlTree(p);
        p->value = value;
    }
     /*插入到左子树中*/
    else if (value < p->value){
        p->left = insertAvlTree(p->left,value);
        /*AVL树不平衡*/
        if (getAvlTreeHeight(p->left)- getAvlTreeHeight(p->right) == 2){
            //数据成为左孩子的左子树(LL型)
            if (value < p->left->value){
                /*做右旋*/
                p = _rotateAvlTree_R(p);
            }
            //数据成为左孩子的右子树(LR型)
            else{
                p = _rotateAvlTree_LR(p);
            }
        }
    }
     /*插入到右子树中*/
    else if (value > p->value){
        p->right = insertAvlTree(p->right,value);
         /*AVL树不平衡*/
        if (getAvlTreeHeight(p->right) - getAvlTreeHeight(p->left) == 2){
             //数据成为右孩子的右子树(RR型)
            if (value > p->right->value){ 
                p = _rotateAvlTree_L(p);
            }
            //数据成为右孩子的左子树(RL型)
            else{
                p = _rotateAvlTree_RL(p);
            }
        }
    }
    p->nHeight = getMax(getAvlTreeHeight(p->left), 
            getAvlTreeHeight(p->right)) + 1;
    return p;
}
/*
 *删除
 */
avlTree_root deleteAvlTree(avlTree_node* p,datatype value){
    if(NULL == p){
        return p;
    }
    else{
        deleteAvlTree(p,value);
    }
}
int main(void){
    avlTree_root root = (avlTree_root)malloc(sizeof(avlTree_node));
    initAvlTree(root);
    root->value = 100;
    int i;
    for(i=0;i<20;i++){
        root = insertAvlTree(root,i);
    }
    printf("height: %d\n",getAvlTreeHeight(root));
    printTree_byLevel(root);
}
