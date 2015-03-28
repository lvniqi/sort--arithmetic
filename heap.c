#include<stdio.h>
void swap_int(int* p1,int* p2){
    int temp=*p1;
    *p1 = *p2;
    *p2 = temp;
}
/*
 *
 * 新加入节点I 父节点为(i-1)/2
 * 左节点 i*2+1
 * 右节点 i*2+2
 * 修复最小堆
 */
void showMinHeap(int a[],int len){
    int i;
    for(i=0;i<len;i++){
        printf("%d: %d\n",i,a[i]);
    }
}
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
        a[child] = a[parent];
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
        //在左右孩子中找最小的
        if(child +1 <end && a[child+1] < a[child]){
            child++;//子节点+1
        }
        //如果子节点比父节点大，就为正常，不必交换
        if(a[child] > temp){
            break;
        }
        a[start] = a[child];//将子节点上移
        start = child;
        child = 2*start + 1;
    }
} 
int main(void){
#define DATA_LEN 10
    int a[DATA_LEN];
    int i;
    showMinHeap(a,DATA_LEN);
    for(i=0;i<DATA_LEN;i++){
        insertMinHeap(a,i,100-i);
    }
    showMinHeap(a,DATA_LEN);
    return 0;
#undef DATA_LEN
}
