#define _CRT_SECURE_NO_WARNINGS 1
#include "Heap.h"

void HeapInit(HP* php)
{
	assert(php);

	php->a = (HPDataType*)malloc(sizeof(HPDataType)*4);
	if (php->a == NULL)
	{
		perror("malloc fail");
		return;
	}

	php->size = 0;
	php->capacity = 4;
}

void HeapDestory(HP* php)
{
	free(php->a);
	php->a = NULL;
	php->size = 0;
	php->capacity = 0;
}

void Swap(HPDataType* p1, HPDataType* p2)
{
	HPDataType tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

//����child,�����ط����ɴ��/С��
void ADjustUp(HPDataType* a, int child)
{
	int parent = (child - 1) / 2;
	//������while(parent>=0) ��Ϊparent������-1������Ҳ�����ܣ���Ϊ����if����������
	while (child>0)
	{
		if (a[child] > a[parent])
		{
			Swap(&a[child], &a[parent]);
			child = parent;
			parent = (child - 1) / 2;
		}
		else
		{
			break;
		}
	}
}

void HeapPush(HP* php, HPDataType x)
{
	assert(php);

	if (php->size == php->capacity)
	{
		HPDataType* tmp = (HPDataType*)realloc(php->a, sizeof(HPDataType) * php->capacity * 2);
		if (tmp == NULL)
		{
			perror("realloc fail");
			return;
		}

		php->a = tmp;
		php->capacity *= 2;
	}
	php->a[php->size] = x;
	php->size++;

	ADjustUp(php->a, php->size - 1);
}

//�����������Ǵ�ѻ���С��
void ADjustDown(HPDataType* a, int sz, int parent)
{
	int child = parent * 2 + 1;
	while (child < sz)
	{
		//ѡ�����Һ����д��һ��
		//����child+1���ж���ǰ����Ҫ�ȷ������ж�
		if (child+1<sz && a[child + 1] > a[child])
		{
			//��ط����ܻ�Խ��
			++child;
		}

		if (a[child] > a[parent])
		{
			//Swap(&a[child], a[a[parent]]);  //�������д�ľ����������Ŷ
			Swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}

void HeapPop(HP* php)
{
	assert(php);
	assert(!HeapEmpty(php));

	Swap(&php->a[0], &php->a[php->size-1]);
	php->size--;

	ADjustDown(php->a, php->size, 0);
}

HPDataType HeapTop(HP* php)
{
	assert(php);

	return php->a[0];
}

bool HeapEmpty(HP* php)
{
	assert(php);

	return php->size == 0;
}

int HeapSize(HP* php)
{
	assert(php);
	return php->size;
}