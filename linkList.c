#include"linkList.h"
void initLinkList(link_list *p,datatype dat){
    p->next = 0;
    p->value = dat;
}
void printLinkList(link_list *p){
    if(NULL != p){
        printf("value:%d\n",p->value);
        printLinkList(p->next);
    }
}
void addLinkList(link_list *p,datatype dat){
    if(NULL != p->next){
        addLinkList(p->next,dat); 
    }
    else{
        link_list * p_temp = (link_list*)malloc(sizeof(link_list));
        initLinkList(p_temp,dat);
        p->next = p_temp;
    }
}
link_list* deleteLinkList(link_list *p,datatype dat){
    link_list* temp = p;
    if(NULL != p){
        if(p->value == dat){
            temp = p;
            p = p->next;
            free(temp);
        }
        else{
            temp = p->next;
            temp = deleteLinkList(temp,dat);
            p->next = temp;
        }
    }
    return p;
}
link_list_root deleteallLinkList(link_list *p){
    if(NULL !=p){
        deleteallLinkList(p->next);
        p->next = 0;
        free(p);
    }
    return NULL;
}
int main(void){
    link_list_root temp = (link_list*)malloc(sizeof(link_list));
    initLinkList(temp,0);
    int i;
    for(i=0;i<10;i++){
        addLinkList(temp,i);
    }
    deleteLinkList(temp,5);
    printLinkList(temp);
    temp =  deleteallLinkList(temp);
    return 0;
}
