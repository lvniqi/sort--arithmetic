#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define MAXSIZE 100
typedef int datatype;
typedef struct {
	datatype data[MAXSIZE];
	int top;
}SqStack;

void initStack(SqStack* p){
	p->top = -1;
}

bool isEmpty(const SqStack* p){
	if(p->top == -1){
		return true;
	}
	else{
		return false;
	}
}
bool push(SqStack* p,datatype d){
	if(p->top<MAXSIZE-1){
		p->data[++(p->top)] = d;
		return true;
	}
	return false;
}
bool pop(SqStack* p,datatype* d){
	if(p->top > -1){
		*d = p->data[(p->top)--];
		return true;
	}
	return false;
}
bool getTop(const SqStack* p,datatype* d){
	if(p->top > -1){
		*d = p->data[(p->top)];
		return true;
	}
	return false;
}
bool clear(SqStack* p){
	p->top = -1;
}
int getISP(char t){
	switch(t){
		case '+':case '-':return 3;
		case '*':case '/':return 5;
		case '(':return 1;
		case ')':return 6;
		default: return 0;
	}
}
int getICP(char t){
	switch(t){
		case '+':case '-':return 2;
		case '*':case '/':return 4;
		case '(':return 6;
		case ')':return 1;
		default: return 0;
	}
}
bool n2s(char* str){
	SqStack* stack = (SqStack*)malloc(sizeof(SqStack));
	initStack(stack);
	for(;*str!= '\0';str++){
		char ch = *str;
		if(ch == '+' ||
		   ch == '-' ||
		   ch == '*' ||
		   ch == '/' ||
		   ch == '(' ||
		   ch == ')'    ){
			while(true){
				int t;
				if(!getTop(stack,&t)){
					t = -1;
				}
				if(getISP(t)>getICP(ch)){
					pop(stack,&t);
					putchar(t);
				}
				else if(getISP(t) == getICP(ch)){
					pop(stack,&t);
					break;
				}
				else{
					push(stack,ch);
					break;
				}
			}
		}
		else{
			putchar(ch);
		}
	}
	while(!isEmpty(stack)){
		int t;
		pop(stack,&t);
		putchar(t);
	}
	free(stack);
}
int main(void){
	char *s = "a+b-a*((c+d)/e-f)+g";
	SqStack* stack = (SqStack*)malloc(sizeof(SqStack));
	n2s(s);
	//push(stack,0);
	//push(stack,55);
	//int t;
	//pop(stack,&t);
	//printf("1:\t%d\r\n",t);
	//pop(stack,&t);
	//printf("1:\t%d\r\n",t);
	return 0;
}
