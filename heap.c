#include<stdio.h>
/*
 *
 * 新加入节点I 父节点为(i-1)/2
 * 修复最小堆
 */

void fixMinHeap_up(int a[],int child){
    int parent,temp;
    temp = a[child];
    parent = (child-1)/2;
    while (parent >= 0 && child >0){
        //如 果子节点的值大于父节点
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
    fixMinHeap_up(a,pos);
}
void fixMinHeap_down(int a[],int start,int end){
    //找到最小的到a[0]
    int temp = a[start];
    int child = 2*start+1;
    while(child < end){
        if(child +1 <end && a[child+1] < a[child])
    }
} 
int main(void){

}
