#pragma once
using namespace std;
typedef struct tagListNode {
	int val;
	tagListNode *next;
	struct tagListNode(int x) : val(x), next(NULL) {}
}ListNode;

typedef struct tagTreeNode {
	int val;
	tagTreeNode *left;
	tagTreeNode *right;
	tagTreeNode(int x) : val(x), left(NULL), right(NULL) {}
}TreeNode;

