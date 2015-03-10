#include<stdio.h>
#define DATA_LEN 20
typedef int qS_data;

extern void printData(qS_data*p,int len);
void bubbleSort(qS_data* p,int len){
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
void insertSort(qS_data* p,int len){
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
void quickSort(qS_data* p,int low,int high){
    int i=low,j=high;
    if(i>=j){
        return;
    }
    qS_data key = p[low];
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
    printData(p,DATA_LEN);
    printf("i:%d,j:%d\n",i,j);
    quickSort(p,low,i-1);
    quickSort(p,j+1,high);
    return;
}
void printData(qS_data*p,int len){
    int i;
    printf("---+----+---\n");
    for(i=0;i<len;i++){
        printf("%d ",p[i]);
    }
    printf("\nend!\n");
}
int main(void){
    qS_data temp[DATA_LEN]={1,2,4,6,5,2321,4,3,4,545,6,4,42,3,434,};
    printData(temp,DATA_LEN);
    //quickSort(temp,0,DATA_LEN-1);
    insertSort(temp,DATA_LEN);
    printData(temp,DATA_LEN);
    return 0;

}
