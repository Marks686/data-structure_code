#include "BTree.h"

#include "Queue.h"

#include "Stack.h"

BTNode* BinaryTreeCreate(BTDataType* src, int n, int* pi)
{
	if (*pi >= n || src[*pi] == '#')
	{
		(*pi)++;
		return NULL;
	}

	BTNode* cur = (BTNode*)malloc(sizeof(BTNode));
	cur->_data = src[*pi];
	(*pi)++;

	cur->_left = BinaryTreeCreate(src,n,pi);
	cur->_right = BinaryTreeCreate(src, n, pi);

	return cur; 
}

void BinaryTreePrevOrder(BTNode* root)
{
	if (root)
	{
		putchar(root->_data);
		BinaryTreePrevOrder(root->_left);
		BinaryTreePrevOrder(root->_right);

	}
}

void BinaryTreeInOrder(BTNode* root)
{
	if (root)
	{
		BinaryTreeInOrder(root->_left);
		putchar(root->_data);
		BinaryTreeInOrder(root->_right);
	}
}

void BinaryTreePostOrder(BTNode* root)
{
	if (root)
	{
		BinaryTreePostOrder(root->_left);
		BinaryTreePostOrder(root->_right);
		putchar(root->_data);
	}
}

void BinaryTreeDestory(BTNode** root)
{
	if (*root)
	{
		BinaryTreeDestory(&(*root)->_left);
		BinaryTreeDestory(&(*root)->_right);
		free(*root);
		*root = NULL;
	}
}

void BinaryTreeLeve10rder(BTNode* root)
{
	Queue qu;
	BTNode* cur;


	QueueInit(&qu);

	QueuePush(&qu, root);

	while (!QueueEmpty(&qu))
	{
		cur = QueueTop(&qu);

		putchar(cur->_data);

		if (cur->_left)
		{
			QueuePush(&qu, cur->_left);
		}

		if (cur->_right)
		{
			QueuePush(&qu, cur->_right);
		}

		QueuePop(&qu);
	}
	QueueDestroy(&qu);

}