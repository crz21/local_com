#ifndef _LIST_H_
#define _LIES_H_

struct Node;
typedef struct Node List;
typedef struct Header pHead;

pHead *createList();
int isEmpty(pHead *l);
int Insert(pHead *l, int pos, int val);
void Delete(pHead *l, int ele);
List *find(pHead *l, int ele);
int Size(pHead *l);
void Destory(pHead *l);


struct Node
{
	int data;
	struct Node *next;
};

struct Header
{
	int length;
	struct Node *next;
};
#endif