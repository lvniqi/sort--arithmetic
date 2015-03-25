#include<stdio.h>
/*
 *
 * 新加入节点I 父节点为(i-1)/2
 * 修复最小堆
 */

void fixMinHeap(int a[],int child){
    int parent,temp;
    temp = a[child];
    parent = (child-1)/2;
    while (parent >= 0 && child >0){
        //如果子节点的值大于父节点
        //则跳出
        if(a[parent] <= temp){
            break;
        }
        a[parent] = a[child];
        child = parent;
        parent = (child-1)/2;
    }
    a[child] = temp;
}
void insertMinHeap(int a[],int pos,int value){
    a[pos] = value;
    fixMinHeap(a,pos);
}
int main(void){

}
