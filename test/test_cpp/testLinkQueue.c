/*********************************************************
-  Copyright (C): 2016
-  File name    : queue.c
-  Author       : - Zhaoxinan -
-  Date         : 2016年04月21日 星期四 15时34分59秒
-  Description  : 单链队列的存储

*  *******************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE      1
#define FALSE    -1
#define OK        1
#define ERROR    -1
#define OVERFLOW -2
#define BUFFERSIZE 512



/* ----     单链队列----队列的链式存储结构   ---- */
typedef struct Qnode
{
    char  date[BUFFERSIZE];
    struct Qnode *next;
}QNode, * QueuePtr;

typedef struct
{
    QueuePtr head;    //队头指针
    QueuePtr tail;    //队尾指针
}LinkQueue;

/* ---- 基本操作函数 ---- */
/* ---- 构造一个空队列 ---- */

int InitQueue(LinkQueue *Q)
{
    Q->head = Q->tail = (QueuePtr)malloc(sizeof(QNode));
    if (Q->head == NULL)
    {
        exit(OVERFLOW);
    }
    memset(Q->tail, 0, sizeof(QNode));
    Q->tail->next = NULL;
    return OK;
}

/* ---- 将Q清空空队列 ---- */
int ClearQueue(LinkQueue *Q)
{
     QueuePtr temp = Q->head;
     //Q->tail = Q->head->next;

	 //QueuePtr template;
	 //template = Q->head->next;
	 //printf("Q->head  = %p \n\n",Q->head);
	 //printf("Q->head->next  = %p \n\n",Q->head->next);
	 //printf("template->next = %p \n\n",template->next);

     while(temp != Q->tail)
     {
	QueuePtr template = temp->next;
        //temp = Q->tail->next; //指向下一个待释放的单元
		//printf("Q->tail  = %2d \n\n",Q->tail);
		printf("delete value:= %s \n\n",temp->date);
        free(temp);
		//printf("after free : Q->tail  = %2d \n\n",Q->tail);
        temp = template;
     }

     Q->head = Q->tail; //修改队尾指针


	 //printf("Q->head  = %p \n\n",Q->head);
	 //printf("Q->tail  = %p \n\n",Q->tail);
	 //printf("Q->head->next  = %p \n\n",Q->head->next);
	 //printf("template->next = %p \n\n",template->next);

     return OK;
}


/* ---- 销毁队列Q,Q不再存在 ---- */
int DestoryQueue(LinkQueue *Q)
{
    //head->node1->node2->node3->tail;
    //             tail
    //       head->node2
    ClearQueue(Q);
    if(Q->head)
    {
        free(Q->head);
    }
    Q->head = Q->tail = NULL;
    return OK;

}


/* ---- 若队列Q为空队列,返回TRUE,否则返回FALSE ---- */
int QueueEmpty(LinkQueue Q)
{
    if (Q.head == Q.tail && Q.head != NULL)
    {

        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

/* ---- 返回Q的元素个数,即队列的长度 ---- */
int QueueLength(LinkQueue Q)
{
    if (Q.head == Q.tail)
    {
        return 0;
    }

    QueuePtr temp;
    int count = 1;
    temp = Q.head->next;

    while(temp != Q.tail)
    {
		//printf("QueueLength temp->next 指针 %2d\n",temp->next);
        temp = temp->next;
        ++count;
		//printf("count is %d \n",count);
    }

    return count;
}

/* ---- 显示当前队列的值从队头到队尾 ---- */
void show_queue(LinkQueue Q)
{
    if (Q.head == Q.tail) {
	return;
    }
    QueuePtr temp;
    temp = Q.head;
    printf("  当前队列从头到尾：");
    while(temp != Q.tail)
    {
        printf("%s", temp->date);
        temp = temp->next;
    }
    printf("\n\r");
}


/* ---- 若队列不空,则用e返回Q的队头元素,并返回OK, 否则返回ERROR ---- */
int GetHead(LinkQueue Q, char *e)
{
    if (QueueEmpty(Q) == TRUE)
    {
        return ERROR;
    }
	//printf("队头元素date ：%s\n",Q.head->next->date);
    //*e = Q.head->next->date;
	//e = Q.head->next->date;
	strcpy(e,Q.head->next->date);
	//printf("队头元素 ：%s\n",e);

    return  OK;

}

/* ---- 插入元素e为Q的新的对尾元素 ---- */
int EnQueue(LinkQueue *Q, char *e)
{
    if (Q->head == NULL || Q->tail == NULL)
    {
        return ERROR;
    }
    QueuePtr ptr = (QueuePtr)malloc(sizeof(QNode));
	//ptr->date = (char) malloc(BUFFERSIZE);
    if (!ptr)
    {
        exit(OVERFLOW);
    }
	strncpy(Q->tail->date, e, sizeof(ptr->date));
    memset(ptr, 0, sizeof(QNode));

    //ptr->date = e;
    ptr->next = NULL;

    Q->tail->next = ptr;
    Q->tail = ptr;
    return OK;
}

/* ---- 若队列不空,则删除Q的队头元素,并用e返回其值,并返回OK,否则返回ERROR ---- */
int DeQueue(LinkQueue *Q, char *e)
{
    if (Q->head == Q->tail)
    {
        return ERROR;
    }
    /* ptr为临时变量 */
    //QueuePtr ptr = (QueuePtr)malloc(sizeof(QNode));
    //head->node1->node2->tail;
    //       ptr
    //      head->node2->tail

    QueuePtr ptr = Q->head->next;

    //*e = ptr->date;
	//e = ptr->date;
    strncpy(e, Q->head->date, strlen(Q->head->date));
	//printf("出对元素 ：%s\n\r",e);
    //Q->head->next = ptr->next;
    //if (Q->tail == ptr)
    {
	free(Q->head);
        Q->head = ptr;
    }
	//free(ptr->date);
    return OK;
}

int main()
{
    int i;        //循环变量
    int count;    //计数变量
    char outque[512];   //出队元素值
	char enque[512];
	char element = 0;
    LinkQueue Q;

    /* 初始化队列 */
    InitQueue(&Q);
    printf("is empty %d \n", QueueEmpty(LinkQueue Q));
    /* 插入10个元素 */
    printf("________________入队10个元素________________\n\n");
    for (i = 0; i < 10; i++)
    {
        /* 入队 */
		sprintf(enque,"%d",i);
        EnQueue(&Q, enque);
        /* 获得当前队列中元素个数 */
        count = QueueLength(Q);
        printf("%2d 入队_当前队列中元素个数：%2d",i, count);
        show_queue(Q);
    }

    printf("________________出队5个元素________________\n\n");


    for (i = 0; i < 5; i++)
    {
        /* 出队 */
        DeQueue(&Q, outque);
        /* 获得当前队列中元素个数 */
        count = QueueLength(Q);
        printf("%s 出队_当前队列中元素个数：%2d", outque, count);
        show_queue(Q);
    }
    /* 获得当前队头值 */
    GetHead(Q, outque);
    printf("\n当前队头为：%s \n", outque);

    printf("________________清空队列_________________\n\n");
    ClearQueue(&Q);
	printf("________________清空队列完毕_________________\n\n");

	//QueuePtr template;
	//template = Q.head->next;
	//printf("Q.head  = %2d \n\n",Q.head);
	//printf("Q.head.next  = %2d \n\n",Q.head->next);
	//printf("template->next  = %2d \n\n",template->next);

    count = QueueLength(Q);
    printf("当前队列中元素个数：%2d", count);
    show_queue(Q);

    printf("________________销毁队列_________________\n\n");
    DestoryQueue(&Q);
    count = QueueLength(Q);
    printf("当前队列中元素个数：%2d\n\n", count);

    return 0;
}
