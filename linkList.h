#ifndef LINK_LIST_H_
    #define LINK_LIST_H_ 
    #include<stdio.h>
    #include<stdlib.h>
    typedef int datatype;
    typedef struct _link_list{
        datatype value;
        struct _link_list* next;
    }link_list;
    typedef link_list* link_list_root;
#endif

