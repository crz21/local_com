#define _CRT_SECURE_NO_WARNTINGS
#include <stdlib.h>
#include <stdio.h>
#include "list.h"

int main()
{
	int ret;
	pHead *ph = createList();
	if (ph == NULL)
	{
		printf("创建列表失败！");
	}
	int arr[10] = { 1, 2, 3, 4, 56, 78, 7, 6, 53, 33};

	for (int i = 0; i <= 6; i++)
	{
		Insert(ph, 0, arr[i]);
	}
	printf("链表长度：%d\n", Size(ph));
	pritnf("打印链表中的元素：\n");
	print(ph);
	printf("请输入要删除的元素:\n");
	int num;
	scanf("%d", &num);
	Delete(ph, num);
	printf("删除元素成功");
	ptint(ph);
	ret = find(ph, 3);
	if (ret)
		ptintf("get!\n");
	else
		printf("NO\n");
	system("pause");
	return 0;

}

