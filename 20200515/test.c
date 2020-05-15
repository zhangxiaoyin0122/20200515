#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
typedef char Type;

typedef struct BinaryTreeNode {
	Type _value;
	struct BinaryTreeNode* _left;
	struct BinaryTreeNode* _right;
}BTNode;

BTNode* creatTree(char* str,int* idx) {
	if (str[*idx] != '#') {
		BTNode* root = (BTNode*)malloac(sizeof(Type));
		root->_value = str[*idx];
		++(*idx);
		root->_left=creatTree(str, idx);
		++(*idx);
		root->_right=creatRoot(str, idx);
	}
	else
		return NULL;
}
//二叉树的销毁
void BinaryTreeDestory(BTNode** root) {
	BTNode* cur = *root;
	while (cur) {
		BinaryTreeDestory(&cur->_left);
		BinaryTreeDestory(&cur->_right);
		free(cur);
	}
	*root = NULL;
}
//二叉树的节点个数
int BinaryTreeSize(BTNode* root) {
	if (root == NULL)
		return 0;
	return BinaryTreeSize(root->_left) + BinaryTreeSize(root->_right) + 1;
}

void BinaryTreeSize1(BTNode* root, int* count) {
	BTNode* cur = root;
	while (cur) {
		++(*count);
		BinaryTreeSize1(root->_left, count);
		BinaryTreeSize1(root->_right, count);
	}
}

int BinaryTreeLeafSize(BTNode* root) {
	if (root == NULL)
		return 0;
	if (root->_left == NULL && root->_right == NULL)
		return 1;
	return BinaryTreeLeafSiae1(root->_left) + BinaryTreeLeafSize1(root->_right);
}

int BinaryTreeLevelKSize(BTNode* root, int k) {
	if (k == 0)
		return 0;
	if (k == 1)
		return 1;
	return BinaryTreeLevelKSize(root->_left, k - 1) + BinaryTreeLevelKSize(root->_right, k - 1);
}

BTNode* BinaryTreeFind(BTNode* root, Type x) {
	if (root == NULL)
		return NULL;
	if (root->_value == x)
		return root;
	BTNode* ret = BinaryTreeFind(root->_left, x);
	if (ret)
		return ret;
	return BinaryTreeFind(root->_right, x);
}
//递归遍历树
void BinaryTreePrevOrder(BTNode* root) {
	if (root) {
		printf("%c ", root);
		BinaryTreePrevOrder(root->_left);
		BinaryTreePrevOrder(root->_right);
	}
}

void BinaryTreeInOrder(BTNode* root) {
	if (root) {
		BinaryTreeInOrder(root->_left);
		printf("%c ", root);
		BinaryTreeInOrder(root->_right);
	}
}

void BinaryTreePostOrder(BTNode* root) {
	if (root) {
		BinaryTreePostOrder(root->_left);
		BinaryTreePostOrder(root->_right);
		printf("%c ", root);

	}
}

