// LeetCode.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "algorithm.h"

struct Number
{
	int num;
	Number(){num = 0;}
};
void setNum(Number* tnum)
{
	tnum = new Number();
	tnum->num = 7;
}
#include <math.h>
int _tmain(int argc, _TCHAR* argv[])
{
	int arr1[5] = {1, 2, 3, 4, 5};
	int arr2[4] = {2, 4, 6, 8};
 	ListNode* list1 = CreateList(arr1, 5);
	ListNode* list2 = CreateList(arr2, 4);
 	PrintList(list1);
	PrintList(list2);

	ListNode* result = swapPairs(list1);
	PrintList(result);

// 	double n2 = pow((double)2, 2147483647);
// 	double n = myPow(2,2147483647);



// 	list1 = rotateRight(list1, 14);
// 	PrintList(list1);
// 
// 	int arr2[3] = {9, 9, 9};
// 	ListNode* list2 = CreateList(arr2, 3);
// 	PrintList(list2);
// 
// 
// 	ListNode* result = addTwoNumbersRev(list1, list2);
// 	PrintList(result);

	//lengthOfLongestSubstring("raikkonen");

	//longestPalindrome("ababaa");
	//zigzagConvert("ab", 1);
	//reverse(1534236469);
	//isPalindrome(111111);
	
	vector<int> nums(arr1, arr1 + 9 );
	//sortedArrayToBST(nums);
	//int i = maxArea(nums);
	TreeNode* p = new TreeNode(1);
	p->left = new TreeNode(2);
	p->left->right = new TreeNode(3);

	p->right = new TreeNode(2);
	p->right->right = new TreeNode(3);



	//bool same = isSymmetric(p);

	//intToRoman(40);

	system("pause");

	return 0;
}

