#pragma once
#include<stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

//#define N 100
//typedef int STDataType;
//struct Stack
//{
//	STDataType a[N];
//	int top;
//};

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
bool StackEmpty(ST* sp);
int StackSize(ST* ps);