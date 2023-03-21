#include<stdio.h>

int main()
{

	return 0;
}


//232. 用栈实现队列
//https://leetcode.cn/problems/implement-queue-using-stacks/

typedef struct {
    int* a;
    int front;
    int back;
    int N;
} MyCircularQueue;



MyCircularQueue* myCircularQueueCreate(int k) {
    MyCircularQueue* obj = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
    obj->a = (int*)malloc(sizeof(int) * (k + 1));
    obj->front = obj->back = 0;
    obj->N = k + 1;


    return obj;
}
bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
    return obj->front == obj->back;


}


bool myCircularQueueIsFull(MyCircularQueue* obj) {
    return (obj->back + 1) % obj->N == obj->front;
}



bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
    if (myCircularQueueIsFull(obj))
        return false;


    obj->a[obj->back] = value;
    obj->back++;


    //控制如果到空间尾后，back回到0的位置。
    obj->back %= obj->N;


    return true;
}


bool myCircularQueueDeQueue(MyCircularQueue* obj) {
    if (myCircularQueueIsEmpty(obj))
        return false;


    obj->front++;
    obj->front %= obj->N;
    return true;
}


int myCircularQueueFront(MyCircularQueue* obj) {
    if (myCircularQueueIsEmpty(obj))
        return -1;
    else
        return obj->a[obj->front];
}


int myCircularQueueRear(MyCircularQueue* obj) {
    /*if(myCircularQueueIsEmpty(obj))
        return -1;
    else if(obj->back == 0)
        return obj->a[obj->N-1];
    else
        return obj->a[obj->back-1];*/



    if (myCircularQueueIsEmpty(obj))
        return -1;
    else
        return obj->a[(obj->back - 1 + obj->N) % obj->N];


}



void myCircularQueueFree(MyCircularQueue* obj) {
    free(obj->a);
    free(obj);
}

/////////////////////////////////////////////////////////////////////////////////////////



//232. 用栈实现队列
//https://leetcode.cn/problems/implement-queue-using-stacks/


typedef int STDataType;
typedef struct Stack
{
    STDataType* a;
    int top;
    int capacity;
}ST;

void StackInit(ST* ps);
void StackDestroy(ST* ps);
void StackPush(ST* ps, STDataType x);
void StackPop(ST* ps);
STDataType StackTop(ST* ps);
bool StackEmpty(ST* ps);
int StackSize(ST* ps);



void StackInit(ST* ps)
{
    assert(ps);
    ps->a = NULL;
    ps->top = ps->capacity = 0;
}

void StackDestroy(ST* ps)
{
    assert(ps);
    free(ps->a);
    ps->a = NULL;
    ps->capacity = ps->top = 0;
}

void StackPush(ST* ps, STDataType x)
{
    assert(ps);
    if (ps->top == ps->capacity)
    {
        int newCapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
        STDataType* tmp = (STDataType*)realloc(ps->a, newCapacity * sizeof(STDataType));
        if (tmp == NULL)
        {
            perror("realloc fail");
            exit(-1);
        }

        ps->a = tmp;
        ps->capacity = newCapacity;
    }

    ps->a[ps->top] = x;
    ps->top++;
}

void StackPop(ST* ps)
{
    assert(ps);
    assert(!StackEmpty(ps));

    --ps->top;
}

STDataType StackTop(ST* ps)
{
    assert(ps);
    assert(!StackEmpty(ps));

    return ps->a[ps->top - 1];
}

bool StackEmpty(ST* ps)
{
    assert(ps);
    return ps->top == 0;
}

int StackSize(ST* ps)
{
    assert(ps);
    return ps->top;
}




typedef struct {
    ST pushST;
    ST popST;
} MyQueue;


MyQueue* myQueueCreate() {
    MyQueue* obj = (MyQueue*)malloc(sizeof(MyQueue));
    StackInit(&obj->pushST);
    StackInit(&obj->popST);

    return obj;
}

void myQueuePush(MyQueue* obj, int x) {
    StackPush(&obj->pushST, x);
}

void PushSTToPopST(MyQueue* obj)
{
    if (StackEmpty(&obj->popST))
    {
        while (!StackEmpty(&obj->pushST))
        {
            StackPush(&obj->popST, StackTop(&obj->pushST));
            StackPop(&obj->pushST);
        }
    }
}

int myQueuePop(MyQueue* obj) {
    PushSTToPopST(obj);

    int front = StackTop(&obj->popST);
    StackPop(&obj->popST);
    return front;
}

int myQueuePeek(MyQueue* obj) {
    PushSTToPopST(obj);

    return StackTop(&obj->popST);
}

bool myQueueEmpty(MyQueue* obj) {
    return StackEmpty(&obj->popST)
        && StackEmpty(&obj->pushST);
}

void myQueueFree(MyQueue* obj) {
    StackDestroy(&obj->pushST);
    StackDestroy(&obj->popST);

    free(obj);
}