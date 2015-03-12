/*
* CCD.c
*
*  Created on: 2013-12-2
*      Author: lvniqi
*      Email: lvniqi@gmail.com
*/
/*
	���棡ʹ��ʱ����ǳ�С�ģ�
        ʹ��ǰ�����ʼ����
        ��Ҫ�������� ��֤���ݲ��⵽�޸�!
	ͬʱ ���ֹ��������� ��
	
 */
#ifndef SEQUEUE_H_
#define SEQUEUE_H_
/*************���ж���*******************************************/
typedef struct _u8_sequeue
{
	u8* dataspace;
	u16 front;
	u16 rear;
	u16 len;
	u16 len_should_cut;
	u16 len_max;
} u8_sequeue;
typedef struct _u16_sequeue
{
	u16* dataspace;
	u16 front;
	u16 rear;
	u16 len;
	u16 len_should_cut;
	u16 len_max;
} u16_sequeue;
typedef struct _int_sequeue
{
	int* dataspace;
	u16 front;
	u16 rear;
	u16 len;
	u16 len_should_cut;
	u16 len_max;
} int_sequeue;
typedef struct _angle_sequeue
{
        int* dataspace;
        u16 front;
        u16 rear;
        u16 len;
        u16 len_should_cut;
        u16 len_max;
        u8 lock;
        
} angle_sequeue;
typedef struct _float_sequeue
{
	float* dataspace;
	u16 front;
	u16 rear;
	u16 len;
	u16 len_should_cut;
	u16 len_max;
} float_sequeue;

/**************ѭ�������� ����*************************************/
/*�õ����г���*/
#define Sequeue_Getlen(sq)	\
	((sq)->len)

#define Sequeue_GetlenMax(sq)	\
	((sq)->len_max)


#define Sequeue_Full(sq)\
	( ((sq)->len) >=(sq)->len_max-1)

/*�ÿն�*/
#define Sequeue_Set_Null(sq,len_base)	\
{	\
    (sq)->front = 0;	\
    (sq)->rear = 0;	\
    (sq)->len = 0;	\
    (sq)->len_max = (len_base);	\
}

	
/*�жӿ�*/
#define Sequeue_Empty(sq)	\
    (!Sequeue_Getlen(sq))



/*ȡͷ�ڵ�*/
#define Sequeue_Get_Front(sq)	\
	(((sq)->dataspace)[((sq)->front)])

/*ȡβ�ڵ�*/
#define Sequeue_Get_Rear(sq)	\
	(  ((sq)->dataspace)[(((sq)->front)+((sq)->len)-1)%((sq)->len_max)]  )
	
/*ȡ�ýڵ�I*/
#define Sequeue_Get_One(sq,i)	\
    (  ((sq)->dataspace)[((sq)->front+i)%((sq)->len_max)])	
	
/*���*/
#define Sequeue_In_Queue(sq,x)	\
{										\
	(((sq)->dataspace)[(sq)->rear]) = x;		\
	(sq)->rear = ((sq)->rear +1)%((sq)->len_max);	\
        ((sq)->len)++;						\
}

/*���� ���棡 ����POP*/
#define Sequeue_Out_Queue(sq)	\
{								\
	((sq)->len)--;				\
	(sq)->front = ((sq)->front+1)%((sq)->len_max);	\
}
#define Sequeue_Init(sq,_data,len_m)\
{	\
	Sequeue_Set_Null(sq,len_m);\
	(sq)->len_should_cut = 0;	\
	(sq)->dataspace = _data;	\
}
#endif
