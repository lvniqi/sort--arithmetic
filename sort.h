#ifndef SORT_H_
    #define SOET_H_
	#include<stdio.h>
    typedef int datatype;
    extern void printData(datatype* p,int len);
    extern void bubbleSort(datatype* p,int len); 
    extern void insertSort(datatype* p,int len);
    extern void _quickSort(datatype* p,int start,int end);
    #define quickSort(a,b)  _quickSort((a),0,(b)-1)
    extern void _mergeSort(int sourceArr[],int tempArr[],
            int startIndex,int endIndex);
    #define mergeSort(a,b,c) _mergeSort((a),(b),0,(c)-1) 
#endif
