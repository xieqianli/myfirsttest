#pragma once
#include "datastruct.h"
#include <stack>
#include <string>
#include <vector>
using namespace std;

ListNode* CreateList(int* ary, int count);
void PrintList(ListNode* pList);
ListNode* removeNthFromEnd(ListNode* head, int n) ;
ListNode* rotateRight(ListNode* head, int k);
ListNode* addTwoNumbersRev(ListNode* l1, ListNode* l2);
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2);
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2);
ListNode* swapPairs(ListNode* head);
int lengthOfLongestSubstring(string s);

string longestPalindrome(string s);

string zigzagConvert(string s, int numRows);

int reverse(int x);

bool isPalindrome(int x);

TreeNode* sortedArrayToBST(vector<int>& nums);

double myPow(double x, int n);

ListNode* reverseList(ListNode* head);

bool isSameTree(TreeNode* p, TreeNode* q);

bool isSymmetric(TreeNode* root);

string intToRoman(int num);

string longestCommonPrefix(vector<string>& strs);

vector<vector<int>> twoSum(vector<int>& nums);

vector<vector<int>> threeSum(vector<int>& nums);

#define MAX_LETTER_PER_NOTE 4
typedef struct tagLetterTreeNode {
	string val;
	tagLetterTreeNode* child[MAX_LETTER_PER_NOTE];
	tagLetterTreeNode(){ memset(this, 0, sizeof(tagLetterTreeNode)); }
}LetterTreeNode;

vector<string> letterCombinations(string digits);

bool isValidParentheses(string s);


vector<string> generateParenthesis(int n);