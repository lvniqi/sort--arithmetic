#include<stdlib.h>
#include<stdbool.h>
#include"sort.h"
#include<stdio.h>
bool binSearch(datatype*p,datatype value,int start,int end){
    if(start > end){
        return false;
    }
    else{
        int mid = start+(end-start)/2;
        if(p[mid] == value){
            printf("find! %d.\n",p[mid]); 
            return true;
        }
        else if(p[mid]>value){
            //printf("start:%d,end%d\n",start,mid-1);
            return binSearch(p,value,start,mid-1);
        }
        else{
            //printf("start:%d,end%d\n",mid+1,end);
            return binSearch(p,value,mid+1,end);
        }
    }
}
int main(void){
    int a[100];
    datatype i;
    srand(i);
    for(i=0;i<100;i++){
        a[i] = rand()%100;
    }
    quickSort(a,100);
    for(i=0;i<100;i++){
        binSearch(a,i,0,99);
    }
    printData(a,100);
    return 0;
}
