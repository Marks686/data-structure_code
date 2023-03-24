#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

#define getpch(type) (type*)malloc(sizeof(type))
#define NULL 0
#define TIME 2//时间片长度

typedef struct pcb {//进程管理块
	char name[10];//进程名字
	char state;		//进程状态
	int queue;		//进程所在的队列
	int ntime;		//进程需要运行的时间
	int rtime;		//进程已经运行的时间
	int etime;		//进程在本队列可运行的时间片
	struct pcb* link;
}PCB;

PCB* ready = NULL, * pinsert = NULL, * pfend = NULL, * p = NULL;	 //就绪队列，进程插入位置的变量

int geti()	//使用户仅能输入整数
{
	char ch;
	int i = 0;
	fflush(stdin);
	ch = getchar();
	while (ch == '\n') {
		fflush(stdin);
		ch = getchar();
	}
	while (ch != '\n') {
		if (ch > '9' || ch < '0') {
			printf("\t输入有误!!输入只能为正整数，请重新输入...\n");
			fflush(stdin);
			i = 0;
			ch = getchar();
		}
		else {
			i = i * 10 + (ch - '0');
			ch = getchar();
		}
	}
	return i;
}

void findpos()//更新状态量
{
	PCB* ps = pfend;
	if (!ps || !ps->link || (ps->link->queue - ps->queue) > 1)
		pinsert = ps;
	else {
		while (ps->link && ps->link->queue != (pfend->queue + 2))
			ps = ps->link;
		pinsert = ps;


	}
}

void insert()//插入进程
{
	if (!ready) {

		ready = p;
		pfend = p;
		pinsert = p;
	}
	else if (ready->queue == 1) {//第一队列存在
		p->link = pfend->link;
		pfend->link = p;
		pfend = p;
		findpos();
	}
	else {
		p->link = ready;
		ready = p;
		findpos();
	}

}

void input()/*建立进程控制块函数*/
{
	int i, num;

	printf("\n请输入进程的个数?");
	num = geti();
	for (i = 0; i < num; i++)
	{
		printf("\n进程号No.%d:\n", i + 1);
		p = getpch(PCB);
		printf("\n输入进程名:");
		scanf("%s", p->name);
		printf("输入进程运行时间:");
		p->ntime = geti();
		printf("\n");
		p->rtime = 0;
		p->state = 'w';
		p->queue = 1;
		p->etime = TIME;
		p->link = NULL;
		insert();/*调用insert函数*/
	}
}

void disp(PCB* pr)  /*建立进程现实函数，用于显示当前进程*/
{
	printf("\nname\t state\t queue\t ntime\t rtime\t在队列可停留时间\t \n");
	printf("|%s\t", pr->name);
	printf(" |%c\t", pr->state);
	printf(" |%d\t", pr->queue);
	printf(" |%d\t", pr->ntime);
	printf(" |%d\t", pr->rtime);
	printf(" |%d\t", pr->etime);
	printf("\n");
}

void check()/*建立进程查看函数*/
{
	PCB* pr;
	printf("\n ****当前正在运行的进程是:%s", ready->name);/*显示当前运行的进程*/
	disp(ready);
	pr = ready->link;
	printf("\n****当前就绪队列状态为:\n");/*显示就绪队列状态*/
	while (pr != NULL)
	{
		disp(pr);
		pr = pr->link;
	}
}


void sort()//调整进程队列
{
	if (!ready->link || ready->queue < ready->link->queue) return;

	p = ready->link;
	ready->link = pinsert->link;
	pinsert->link = ready;
	pinsert = ready;
	ready = p;
	if (ready && ready->queue == pinsert->queue) {
		findpos();
	}

}

void addnew()//添加新的进程
{
	if (ready->queue != 1) {
		(ready->queue)++;
		ready->etime *= 2;
		ready->state = 'w';
		sort();/*调用sort函数*/
		input();
	}
	else {
		input();

	}

}
void destroy()/*建立进程撤销函数(进程运行结束，撤销进程)*/
{
	printf("\n进程[%s]已完成.\n", ready->name);
	p = ready;
	ready = ready->link;
	free(p);
	if (ready && ready->queue == pinsert->queue)
		findpos();
}


void running()/*建立进程就绪函数(进程运行时间到，置就绪状态)*/
{
	(ready->rtime)++;
	ready->etime--;
	if (ready->rtime == ready->ntime) {
		destroy();
		return;
	}
	else if (ready->etime == 0) {
		int time = 2;
		(ready->queue)++;
		for (int i = 2; i != ready->queue; ++i)
			time *= 2;
		ready->etime = time;
		ready->state = 'w';
		sort();/*调用sort函数*/
	}
}


void main()
{
	char ch;
	input();
	while (ready != NULL)
	{
		printf("\nThe execute name:%s\n", ready->name);
		ready->state = 'R';
		check();
		running();
		printf("\n按i键添加新进程....按其他任意键继续运行...");
		fflush(stdin);
		ch = getchar();
		if (ch == 'i' || ch == 'I')
			addnew();

	}
	printf("\n\n 进程已经完成\n");
	system("pause");
}
