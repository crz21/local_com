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
		printf("�����б�ʧ�ܣ�");
	}
	int arr[10] = { 1, 2, 3, 4, 56, 78, 7, 6, 53, 33};

	for (int i = 0; i <= 6; i++)
	{
		Insert(ph, 0, arr[i]);
	}
	printf("�����ȣ�%d\n", Size(ph));
	pritnf("��ӡ�����е�Ԫ�أ�\n");
	print(ph);
	printf("������Ҫɾ����Ԫ��:\n");
	int num;
	scanf("%d", &num);
	Delete(ph, num);
	printf("ɾ��Ԫ�سɹ�");
	ptint(ph);
	ret = find(ph, 3);
	if (ret)
		ptintf("get!\n");
	else
		printf("NO\n");
	system("pause");
	return 0;

}

