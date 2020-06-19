#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "list.h"
typedef struct Node List;
typedef struct Header pHead;


pHead * createList()
{
	pHead *ph = (pHead *)malloc(sizeof(pHead));
	ph->length = 0;
	ph->next = NULL;
	return ph;
}

//获取链表大小
int Size(pHead *ph)
{
	if (ph == NULL)
	{
		printf("参数传入有误！");
		return 0;
	}
	return ph->length;
}

int Insert(pHead *ph, int pos, int val)
{
	//健壮性：判断空间是否能分配
	if (ph == NULL || pos<0 || pos>ph->length)
	{
		printf("参数传入有误!");
		return 0;
	}
	List *pval = (List *)malloc(sizeof(List));
	pval->data = val;
	List *pCur = ph->next;
	if (pos == 0)
	{
		ph->next = pval;
		pval->next = pCur;
	}
	else
	{
		for (int i = 1; i < pos; i++)
		{
			pCur = pCur->next;
		}

		pval->next = pCur->next;
		pCur->next = pval;//将要插入的位置
	}

	ph->length++;
	return 1;
}

//查找某个元素
List *find(pHead *ph, int val)
{
	//作健壮性判断
	if (ph == NULL)
	{
		printf("参数传入有误！");
		return NULL;
	}

	//遍历链表来查元素
	List *pTmp = ph->next;
	do{
		if (pTmp->data == val)
		{
			return pTmp;
		}
		pTmp = pTmp->next;
	} while (pTmp->next != NULL);
	printf("没有值为%d的元素!", val);
	return NULL;
}

void Delete(pHead* ph, int val)
{
	List *pTmp = NULL;
	if (ph == NULL)
	{
		printf("链表传入错误!");
		return;
	}

	List *pval = find(ph, val);
	if (pval == NULL)
	{
		printf("没有值为%d的元素", val);
		return;
	}

	List *pRe = ph->next;
	List *pCur = NULL;
	if (pRe->data == val)
	{
		ph->next = pRe->next;
		ph->length--;
		free(pRe);
		return;
	}
	else
	{
		for (int i = 0; i < ph->length; i++)
		{
			pCur = pRe->next;
			if (pCur->data == val)
			{
				pRe->next = pCur->next;
				ph->length--;
				free(pCur);
				return;
			}
			pRe = pRe->next;
		}
	}
}

//销毁列表
void Destory(pHead* ph)
{
	List *pCur = ph->next;
	List *pTmp;
	if (ph == NULL)
	{
		printf("参数传入有误！");
	}
	while (pCur->next != NULL)
	{
		pTmp = pCur->next;
		free(pCur);
		pCur = pTmp;
	}
	ph->length = 0;
	ph->next = NULL;
}
/*
 *
 *
 */
void print(pHead *ph)
{
	if (ph == NULL)
	{
		printf("参数传入有误！");
	}
	List *pTmp = ph->next;
	while (pTmp != NULL)
	{
		printf("%d ", pTmp->data);
		pTmp = pTmp->next;
	}
	printf("\n");
}