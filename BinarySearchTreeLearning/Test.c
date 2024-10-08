#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "Queue.h"

typedef int BTDataType;

typedef struct BinaryTreeNode
{
	BTDataType data;
	struct BinaryTreeNode* left;
	struct BinaryTreeNode* right;
}BTNode;

BTNode* BuyNode(BTDataType x)
{
	BTNode* node = (BTNode*)malloc(sizeof(BTNode));
	if (node == NULL)
	{
		perror("malloc fail");
		return NULL;
	}

	node->data = x;
	node->left = NULL;
	node->right = NULL;

	return node;
}

BTNode* CreatBinaryTree()
{
	BTNode* node1 = BuyNode(1);
	BTNode* node2 = BuyNode(2);
	BTNode* node3 = BuyNode(3);
	BTNode* node4 = BuyNode(4);
	BTNode* node5 = BuyNode(5);
	BTNode* node6 = BuyNode(6);
	BTNode* node7 = BuyNode(7);

	node1->left = node2;
	node1->right = node4;
	node2->left = node3;
	node4->left = node5;
	node4->right = node6;
	node2->right = node7;

	return node1;
}

void PreOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}
	printf("%d ", root->data);
	PreOrder(root->left);
	PreOrder(root->right);
}

void InOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}

	InOrder(root->left);
	printf("%d ", root->data);
	InOrder(root->right);
}

void PostOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}

	PostOrder(root->left);
	PostOrder(root->right);
	printf("%d ", root->data);
}

//int size = 0;//全局变量容易出问题
//void TreeSize(BTNode* root)
//{
//	if (root == NULL)
//	{
//		return;
//	}
//
//	++size;
//	TreeSize(root->left);
//	TreeSize(root->right);
//}

//传入数字
//void TreeSize(BTNode* root, int* psize)
//{
//	if (root == NULL)
//	{
//		return;
//	}
//
//	++(*psize);
//	TreeSize(root->left, psize);
//	TreeSize(root->right, psize);
//}

//分治思想
int TreeSize(BTNode* root)
{
	return root == NULL ? 0 :
		TreeSize(root->left) 
		+ TreeSize(root->right) 
		+ 1;
}

//自己写的,错误的，先从左边开始，会犯错误
//int TreeHeight(BTNode* root)
//{
//	if (root == NULL)
//	{
//		return 0;
//	}
//	else
//	{
//		if (root->left != NULL)
//		{
//			return TreeHeight(root->left) + 1;
//		}
//		else if(root->right != NULL)
//		{
//			return TreeHeight(root->right) + 1;
//		}
//		else
//		{
//			return 1;
//		}
//	}
//}

int TreeHeight(BTNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	//记录数据，可以减少很多复杂度，提高效率
	int leftHeight = TreeHeight(root->left);
	int rightHeight = TreeHeight(root->right);

	return leftHeight > rightHeight ? leftHeight + 1 : rightHeight + 1;
}

//根的第k层结点的个数
int TreeLevelK(BTNode* root, int k)
{
	assert(k > 0);

	if (root == NULL)
	{
		return 0;
	}
	if (k == 1)
	{
		return 1;
	}
	return TreeLevelK(root->left, k - 1)+TreeLevelK(root->right, k - 1);

}

//查找值为x的结点
BTNode* BinaryTreeFind(BTNode* root, BTDataType x)
{
	if (root == NULL)
	{
		return NULL;
	}
	if (root->data == x)
	{
		return root;
	}
	BTNode* lret = BinaryTreeFind(root->left, x);
	if (lret)
	{
		return lret;
	}
	BTNode* rret = BinaryTreeFind(root->right, x);
	if (rret)
	{
		return rret;
	}
	//左右树都没有，返回空
	return NULL;
}

//层序遍历
void LevelOrder(BTNode* root)
{
	Queue q;
	QueueInit(&q);
	if (root != NULL)
	{
		QueuePush(&q, root);
	}
	while (!QueueEmpty(&q))
	{
		BTNode* front = QueueFront(&q);
		QueuePop(&q);
		printf("%d ", front->data);

		if (front->left)
		{
			QueuePush(&q, front->left);
		}
		if (front->right)
		{
			QueuePush(&q, front->right);
		}
	}
	printf("\n");
	QueueDestory(&q);
}

//判断二叉树是否为完全二叉树判断
bool TreeComplete(BTNode* root)
{
	Queue q;
	QueueInit(&q);
	//为空则不入
	if (root)
	{
		QueuePush(&q, root);

	}
	while (!QueueEmpty(&q))
	{
		BTNode* front = QueueFront(&q);
		QueuePop(&q);

		if (front == NULL)
		{
			break;
		}
		else
		{
			QueuePush(&q, front->left);
			QueuePush(&q, front->right);
		}

	}

	//判断是不是完全二叉树
	while (!QueueEmpty(&q))
	{
		BTNode* front = QueueFront(&q);
		QueuePop(&q);
		//后面有非空，说明非空结点不是完全连续
		if (front)
		{
			QueueDestory(&q);
			return false;
		}
	}
	QueueDestory(&q);
	return true;
}

//后序遍历不用储存根的位置
void TreeDestory(BTNode* root)
{
	if (root == NULL)
	{
		return;
	}
	TreeDestory(root->left);
	TreeDestory(root->right);
	free(root);
}

int main()
{
	BTNode* root = CreatBinaryTree();
	PreOrder(root);
	printf("\n");
	InOrder(root);
	printf("\n");
	PostOrder(root);
	printf("\n");

	//int size1 = 0;
	//TreeSize(root, &size1);
	//printf("TreeSize:%d\n", size1);

	//int size2 = 0;
	//TreeSize(root, &size2);
	//printf("TreeSize:%d\n", size2);

	printf("TreeSize:%d\n", TreeSize(root));	
	printf("TreeSize:%d\n", TreeSize(root));

	printf("TreeHeight:%d\n", TreeHeight(root));
	LevelOrder(root);

	int ret = TreeComplete(root);
	printf("TreeComplete:> %d\n", ret);

	TreeDestory(root);
	root = NULL;
	return 0;
}

