#include<stdio.h>
#include"sort.h"
#define DATA_LEN 20
void bubbleSort(datatype* p,int len){
    int i;
    for(i=0;i<len;i++){
        int j;
        for(j=len-1;j>0;j--){
            if(p[j]<p[j-1]){
                int temp = p[j];
                p[j] = p[j-1];
                p[j-1] = temp;
            }
        }
    }
}
void insertSort(datatype* p,int len){
    int i;
    for(i=1;i<len;i++){
        int j;
        int temp = p[i];
        for(j=i-1;j>=0;j--){
            if(temp<p[j]){
                p[j+1]=p[j];
            } 
            else{
                break;
            }
            p[j] = temp;
        }
    }
}
void _quickSort(datatype* p,int start,int end){
    int i=start,j=end;
    if(i>=j){
        return;
    }
    datatype key = p[start];
    while(i<j){
        while(i<j&&p[j]>=key){
            j--;
        }
        p[i] = p[j];
        while(i<j&&p[i]<=key){
            i++;
        }
        p[j] = p[i];
    }
    p[i] = key;
    //printData(p,DATA_LEN);
    //printf("i:%d,j:%d\n",i,j);
    _quickSort(p,start,i-1);
    _quickSort(p,j+1,end);
    return;
}
void _Merge(int sourceArr[],int tempArr[],int startIndex,int midIndex,int endIndex)
{
    int i = startIndex,j=midIndex+1,k = startIndex;
    while(i<=midIndex && j<=endIndex)
    {
        if(sourceArr[i]<sourceArr[j])
            tempArr[k++] = sourceArr[i++];
        else
            tempArr[k++] = sourceArr[j++];
    }
    while(i<=midIndex)
        tempArr[k++] = sourceArr[i++];
    while(j<=endIndex)
        tempArr[k++] = sourceArr[j++];
    for(i=startIndex;i<=endIndex;i++)
        sourceArr[i] = tempArr[i];
} 
//内部使用递归
void _mergeSort(int sourceArr[],int tempArr[],int startIndex,int endIndex)
{
    int midIndex;
    if(startIndex<endIndex)
    {
        midIndex=(startIndex+endIndex)/2;
        _mergeSort(sourceArr,tempArr,startIndex,midIndex);
        _mergeSort(sourceArr,tempArr,midIndex+1,endIndex);
        _Merge(sourceArr,tempArr,startIndex,midIndex,endIndex);
    }
}
void printData(datatype*p,int len){
    int i;
    printf("---+----+---\n");
    for(i=0;i<len;i++){
        printf("%d ",p[i]);
    }
    printf("\nend!\n");
}
/*int main(void){
    datatype temp[DATA_LEN]={1,2,4,6,5,2321,4,3,4,545,6,4,42,3,434,};
    datatype temp2[DATA_LEN];

    printData(temp,DATA_LEN);
    //quickSort(temp,DATA_LEN);
    mergeSort(temp,temp2,DATA_LEN);
    //insertSort(temp,DATA_LEN);
    printData(temp,DATA_LEN);
    return 0;

}*/
