/*
 *
 * 红黑树的几个性质:
    1) 每个 结点只有红和黑两种颜色
    2) 根结点是黑色的
    3)空节点是黑色的（红黑树中，根节点的parent以及所有叶节点lchild、rchild都不指向NULL，而是指向一个定义好的空节点）。 
    4) 如果一个结点是红色的,那么它的左右两个子结点的颜色是黑色的
    5) 对于每个结点而言,从这个结点到叶子结点的任何路径上的黑色结点
    的数目相同
*/
#include <stdio.h>
#include <stdlib.h>
typedef int datatype;
typedef enum _NODECOLOR//节点颜色
{
    BLACK        = 0,
    RED          = 1
}NODECOLOR;
const char* NODECOLOR_STR[] = {
    "BLACK",
    "RED"
};
typedef struct _rbTree_node
{
    struct _rbTree_node *parent;
    struct _rbTree_node  *left, *right;
    datatype value;
    NODECOLOR   color;
}rbTree_node;
typedef rbTree_node* rbTree_root;
void printRbTree(rbTree_root p){
    printf("value: %d,color: %s",p->value,NODECOLOR_STR[p->color]);

}
rbTree_root insertRbTree(rbTree_root p,datatype value){
    
}
int main(void){
    return 0;
}
