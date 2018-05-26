#include "stdafx.h"
#include "algorithm.h"
using namespace std;

ListNode* CreateList(int* ary, int count)
{
	if (count == 0)
	{
		return NULL;
	}
	ListNode* pResult = new ListNode(0);
	ListNode* tail = pResult;
	for (int i = 0; i < count; i++)
	{
		tail->val = ary[i];
		if ( i < count - 1)
		{
			tail->next = new ListNode(0);
			tail = tail->next;
		}		
	}
	return pResult;
}

void PrintList(ListNode* pList)
{
	ListNode* tail = pList;
	while(tail != NULL)
	{
		printf("%d, ", tail->val);
		tail = tail->next;
	}
	printf("\n");
}
ListNode* swapPairs(ListNode* head)
{
	ListNode* result = head->next;
	ListNode* first = head;
	ListNode* pre = NULL;
	if (first == NULL || first->next == NULL)
	{
		return first;
	}
	ListNode* second = first->next;
	while (first != NULL && second != NULL )
	{
		first->next = second->next;
		second->next = first;
		first = first->next;
		second = first->next;
	}
	return result;
}
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
{
	ListNode** token;
	ListNode* result = NULL;// = &token;
	token = &result;
	while(l1 != NULL && l2 != NULL)
	{
		if (l1->val > l2->val)
		{
			*token = l2;
			l2 = l2->next;
			token = &((*token)->next);
		}
		else
		{
			*token = l1;
			l1 = l1->next;
			token = &((*token)->next);
		}
	}
	if (l1 != NULL)
	{
		*token = l1;
	}
	else if (l2 != NULL)
	{
		*token = l2;
	}	
	return result;
}
ListNode* removeNthFromEnd(ListNode* head, int n) 
{
	ListNode* result = head;
	ListNode* first = head;
	ListNode* second = NULL;
	int looptime = 0;
	while(first)
	{
		looptime++;
		first = first->next;
		if (looptime > n)
		{
			if (second == NULL)
			{
				second = head;
			}
			else
			{
				second = second->next;
			}
		}
		if (first == NULL)
		{
			if (second == NULL)
			{
				ListNode* tmp = head;
				head = head->next;
				delete tmp;
			}
			else
			{
				ListNode* tmp = second->next;
				second->next = second->next->next;
				delete tmp;
			}

		}
	}
	return head;
}

ListNode* reverseList(ListNode* head)
{
	ListNode* result = head;
	ListNode* pre = NULL;
	ListNode* next = NULL;
	while (head->next != NULL)
	{
		next = head->next;
		head->next = pre;
		pre = head;
		head = next;
	}
	head->next = pre;
	return head;
}

ListNode* rotateRight(ListNode* head, int k) 
{
	if (head == NULL)
	{
		return NULL;
	}
	ListNode* tail = head;
	int length = 1;
	while(tail->next != NULL)
	{
		length++;
		tail = tail->next;
	}
	tail->next = head;
	k = k%length;
	k = length - k;
	for (int i = 0; i < k; i++)
	{
		tail = head;
		head = head->next;
	}
	tail->next = NULL;
	return head;
}

ListNode* addTwoNumbersRev(ListNode* l1, ListNode* l2) {
	stack<int> s1;
	stack<int> s2;
	ListNode* pResult = new ListNode(0);
	ListNode* tmp = l1;
	while(tmp != NULL)
	{
		s1.push(tmp->val);
		tmp = tmp->next;
	}
	tmp = l2;
	while(tmp != NULL)
	{
		s2.push(tmp->val);
		tmp = tmp->next;
	}
	bool addOne = false;
	ListNode* head = pResult;
	while(true)
	{
		if(s1.size() == 0 && s2.size() == 0)
		{
			if(addOne)
			{
				head->val = 1;
			}
			break;
		}
		int num1 = 0;
		if(s1.size() > 0)
		{
			num1 = s1.top();
			s1.pop();
		}
		int num2 = 0;
		if(s2.size() > 0)
		{
			num2 = s2.top();
			s2.pop();
		}

		int sum = num1 + num2;
		if(addOne)
			sum++;

		head->val = sum%10;
		if (s1.size() > 0 || s2.size() > 0 || sum>9)
		{
			head->next = new ListNode(0);
			head = head->next;
		}

		if(sum>9)
		{
			addOne = true;
		}
		else
		{
			addOne = false;
		}
	}
	return pResult;
}


ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
{
	stack<int> s1;
	stack<int> s2;
	ListNode* pResult = new ListNode(0);
	ListNode* tmp = l1;
	while(tmp != NULL)
	{
		s1.push(tmp->val);
		tmp = tmp->next;
	}
	tmp = l2;
	while(tmp != NULL)
	{
		s2.push(tmp->val);
		tmp = tmp->next;
	}
	bool addOne = false;
	ListNode* head = pResult;
	while(true)
	{
		if(s1.size() == 0 && s2.size() == 0)
		{
			if(addOne)
			{
				head->val = 1;
			}
			break;
		}
		int num1 = 0;
		if(s1.size() > 0)
		{
			num1 = s1.top();
			s1.pop();
		}
		int num2 = 0;
		if(s2.size() > 0)
		{
			num2 = s2.top();
			s2.pop();
		}

		int sum = num1 + num2;
		if(addOne)
			sum++;

		head->val = sum%10;
		if (s1.size() > 0 || s2.size() > 0 || sum>9)
		{
			ListNode* pre = new ListNode(0);
			pre->next = head;
			head = pre;
		}

		if(sum>9)
		{
			addOne = true;
		}
		else
		{
			addOne = false;
		}
	}
	pResult = head;
	return pResult;
}

int lengthOfLongestSubstring(string s)
{
	int maxLen = 0;
	vector<char> vecChar;
	for(int i = 0; i < s.length(); i++)
	{
		for (vector<char>::iterator it = vecChar.begin(); it != vecChar.end(); it++)
		{
			if (s[i] == *it)
			{		
				vector<char> tmp;
				tmp.insert(tmp.begin(), it+1, vecChar.end());
				vecChar.clear();
				vecChar = tmp;
				break;
			}
		}
		vecChar.push_back(s[i]);
		if (vecChar.size() > maxLen)
		{
			maxLen = vecChar.size();
		}		
	}
	
	return maxLen;
}

string longestPalindrome(string s)
{
	string strResult;
	for(int i = 0; i < s.length() * 2; i++)
	{
		int nIndex = i/2;
		int odd = i%2;
		int j  = 0;
		while( nIndex >= j && nIndex + j + (1 - odd) < s.length() && s[nIndex - j] == s[nIndex + j + (1 - odd)])
		{
			j++;
		}
		j--;
		if (nIndex >= j )
		{
			if (j * 2 + 1 + (1 - odd)> strResult.length())
			{
				strResult = s.substr(nIndex - j,  j * 2 + 1 + (1 - odd));
			}
		}		
	}
	return strResult;
}


string zigzagConvert(string s, int numRows) 
{
	string strResult;
	int nUnit = 1;
	if (numRows > 1)
	{
		nUnit = numRows * 2 - 2;		
	}
	int nWidth = s.length() / nUnit + ((s.length() % nUnit > 0) ? 1 : 0);

	vector<vector<char>> vec2Table;
	vector<char> vecTmp;
	int nIndex = 0;
	for (int i = 0; i < nWidth; i++)
	{
		vecTmp.clear();
		for(int j = 0; j < nUnit; j ++)
		{
			if (nIndex < s.length())
			{
				vecTmp.push_back(s.at(nIndex++));
			}			
		}
		vec2Table.push_back(vecTmp);
	}

	for (int i = 0; i < numRows; i++)
	{
		for (vector<vector<char>>::iterator itvec = vec2Table.begin(); itvec != vec2Table.end(); itvec++)
		{
			vecTmp = *itvec;
			if (i < vecTmp.size())
			{
				strResult.push_back( vecTmp[i] );
			}
			if (i > 0 && i < numRows - 1)
			{
				if (i + (numRows - i - 1) * 2 < vecTmp.size())
				{
					strResult.push_back(vecTmp[i + (numRows - i - 1) * 2] );
				}
			}
		}
	}
	return strResult;
}
#include <math.h>
int reverse(int x)
{
	if (x > INT_MAX || x < INT_MIN )
	{
		return 0;
	}
	int nResult = 0;
	bool neg = false;
	if (x < 0)
	{
		neg = true;
		x *= -1;
	}
	int tmp = x;
	vector<int> vecNum;
	while (tmp > 0)
	{
		vecNum.push_back(tmp%10);
		tmp = tmp/10;
	}
	double dwTmp = 0;
	for (int i = 0; i < vecNum.size(); i++)
	{
		dwTmp = dwTmp * 10 + vecNum[i];
	}
	if (neg)
	{
		nResult *= -1;
	}
	if (dwTmp > INT_MAX || dwTmp < INT_MIN )
	{
		return 0;
	}
	else
	{
		return (int)dwTmp;
	}
}

int myAtoi(string str) 
{
	return 0;
}

bool isPalindrome(int x)
{
	if (x < 0)
	{
		return false;
	}
	int length = log10((double)x) + 1;
	for (int i = 0; i < length/2; i++)
	{
		int first = x % (int)pow((double)10, (double)(length - i)) / (int)pow((double)10, (double)(length - i) - 1);
		int second = x % (int)pow((double)10, (double)(i + 1)) / (int)pow((double)10, (double)(i));
		if (first != second)
		{
			return false;
		}
	}
	return true;
}

void CreateChilds(TreeNode*& root, vector<int>& nums)
{
	if (nums.size() == 0)
	{
		return;
	}
	else
	{
		root = new TreeNode(nums[nums.size()/2]);
		vector<int> tmp;
		tmp.insert(tmp.begin(), nums.begin(), nums.begin() + nums.size()/2);
		CreateChilds(root->left, tmp);
		tmp.clear();
		tmp.insert(tmp.begin(), nums.begin() + nums.size()/2 + 1, nums.end());
		CreateChilds(root->right, tmp);
	}
}

TreeNode* sortedArrayToBST(vector<int>& nums) 
{
	TreeNode* root = NULL;
	//TreeNode* tmp = root;
	CreateChilds(root, nums);
	return root;
}

double myPow(double x, int n)
{
	if(x == 0 || x == 1)
		return x;
	if (n < 0)
	{
		return 1.0/myPow(x, -n);
	}
	if (n == 0)
	{
		return 1;
	}
	else if (n == 1)
	{
		return x;
	}
	if (n%2 == 0)
	{
		return myPow(x, n/2) * myPow(x, n/2);
	}
	else
	{
		return myPow(x, n/2) * myPow(x, n/2) * x;
	}
}

bool isSameTree(TreeNode* p, TreeNode* q)
{
	if (p == NULL && q == NULL)
	{
		return true;
	}
	else if (p == NULL || q == NULL)
	{
		return false;
	}
	if (p->val == q->val)
	{
		if (isSameTree(p->left, q->left) && isSameTree(p->right, q->right))
		{
			return true;
		}
	}
	return false;
}


bool isMirrorTree(TreeNode* left, TreeNode* right)
{
	if (left == NULL && right == NULL)
	{
		return true;
	}
	else if (left == NULL || right == NULL)
	{
		return false;
	}
	else
	{
		if (left->val == right->val)
		{
			return isMirrorTree(left->right, right->left) && isMirrorTree(right->right, left->left);
		}
		else
		{
			return false;
		}		 
	}
}
bool isSymmetric(TreeNode* root)
{
	if (root == NULL)
	{
		return false;
	}
	return isMirrorTree(root->left, root->right);
}

string intToRoman(int num) 
{
	string result;
	result.clear();
	if (num < 1 || num > 3999)
	{
		return result;
	}
	while (num > 0)
	{
		int length = log10((double)num);
		int pownum = pow((double)10, length);
		int tmp = num / pownum;
		num = num - tmp * pownum;
		char unit;
		char five;
		char ten;
		if (length == 3)
		{
			unit ='M';
		}
		else if(length == 2)
		{
			unit = 'C';
			five = 'D';
			ten = 'M';
		}
		else if (length == 1)
		{
			unit = 'X';
			five = 'L';
			ten = 'C';
		}
		else
		{
			unit = 'I';
			five = 'V';
			ten = 'X';
		}
		if (tmp < 4)
		{
			for (int i = 0; i < tmp; i++)
			{
				result.push_back(unit);
			}
		}
		else if (tmp == 4)
		{
			result.push_back(unit);
			result.push_back(five);
		}
		else if (tmp < 9)
		{
			result.push_back(five);
			for (int i = 5; i < tmp; i++)
			{
				result.push_back(unit);
			}
		}
		else
		{
			result.push_back(unit);
			result.push_back(ten);
		}
	}

	return result;
}

string longestCommonPrefix(vector<string>& strs)
{
	if (strs.empty())
	{
		return "";
	}
	string result = strs[0];

	for (int i = 1; i < strs.size(); i++)
	{
		while (strs[i].substr(0, result.size()) != result)
		{
			result = result.substr(0, result.size() - 1);
		}
	}

	return result;
}
#include <algorithm>    // std::sort
vector<vector<int>> twoSum(vector<int>& nums) {
	vector<vector<int>> result;	
	std::sort(nums.begin(), nums.begin()+nums.size()); 

	for (int i = 0; i < nums.size(); i++)
	{
		int end = nums.size() - 1;
		while (nums[i] + nums[end] > 0 && end > i)
		{
			end --;
		}
		if (nums[i] + nums[end] ==0)
		{
			vector<int> tmp;
			tmp.push_back(nums[i]);
			tmp.push_back(nums[end]);
			result.push_back(tmp);
		}
	}

	return result;
}

vector<vector<int>> threeSum(vector<int>& nums) {
	vector<vector<int>> result;	
	std::sort(nums.begin(), nums.begin()+nums.size()); 
	vector<int> tmp;
	for (int i = 0; i < nums.size(); i++)
	{
		if (i > 0 && nums[i] == nums[i - 1])
		{
			continue;
		}
		for (int j = i+1; j < nums.size(); j++)
		{
			if (j > i + 1 && nums[j] == nums[j - 1])
			{
				continue;
			}
			int end = nums.size() - 1;
			vector<int> tmp2;
			tmp2.insert(tmp2.begin(), nums.begin() + j + 1, nums.end());
			vector<int>::iterator third = find( tmp2.begin( ), tmp2.end( ), 0 - (nums[i] + nums[j]) );
			if ( third != tmp2.end( ))
			{
				tmp.clear();
				tmp.push_back(nums[i]);
				tmp.push_back(nums[j]);
				tmp.push_back(*third);
				result.push_back(tmp);	
			}
		}
	}
	return result;
}
#include <map>


void CreateLetterChilds(LetterTreeNode** root, int index, string digits, vector<string>& result, map<int, string> dictionary)
{
	if (index == digits.size())
	{
		if (index > 0)
		{
			result.push_back((*root)->val);
		}
		return;
	}
	string tmpstring = dictionary[digits[index] - '0'];
	for (int j = 0; j < tmpstring.size(); j++)
	{
		(*root)->child[j] = new LetterTreeNode;
		(*root)->child[j]->val = (*root)->val +  tmpstring[j];
		CreateLetterChilds(&(*root)->child[j], index + 1, digits, result, dictionary);
	}
}

vector<string> letterCombinations(string digits) {

	map<int, string> dictionary;
	dictionary[2] = "abc";
	dictionary[3] = "def";
	dictionary[4] = "ghi";
	dictionary[5] = "jkl";
	dictionary[6] = "mno";
	dictionary[7] = "pqrs";
	dictionary[8] = "tuv";
	dictionary[9] = "wxyz";

	vector<string> result;

	LetterTreeNode* root = new LetterTreeNode;

	CreateLetterChilds(&root, 0, digits, result, dictionary);
	return result;
	
// 	stack<string> mainstack;
// 	stack<string> secstack;
// 	for (int i = 0; i < digits.size(); i++)
// 	{
// 		string tmpstring = dictionary[digits[i] - '0'];
// 
// 		if (i == 0)
// 		{
// 			for (int j = 0; j < tmpstring.size(); j++)
// 			{
// 				result.insert(result.begin(), tmpstring.substr(j, 1));
// 			}
// 		}
// 		else
// 		{
// 			for(int j = 0; j < result.size(); j++)
// 			{
// 				result[j].push_back(tmpstring[0]);
// 				for (int k = 1; k < tmpstring.size(); k++)
// 				{
// 					string tmp = result[j];
// 					result.insert(result.begin() + j, tmp);
// 					j++;
// 					result[j][result[k].size() - 1] = tmpstring[k];
// 				}
// 			}
// 		}
// 	}
	return result;
}

bool isApair(char a, char b)
{
	if (a == '(')
	{
		return b == ')';
	}
	else if (a == ')')
	{
		return b == '(';
	}
	else if (a == '[')
	{
		return b == ']';
	}
	else if (a == ']')
	{
		return b == '[';
	}
	else if (a == '{')
	{
		return b == '}';
	}
	else if (a == '}')
	{
		return b == '{';
	}
}
bool isValidParentheses(string s)
{
	stack<char> tmpstack;
	for (int i = 0; i < s.size(); i++)
	{
		if (tmpstack.empty())
		{
			tmpstack.push(s[i]);
		}
		else
		{
			if (isApair(tmpstack.top(), s[i]))
			{
				tmpstack.pop();
			}
			else
			{
				tmpstack.push(s[i]);
			}
		}
	}
	return tmpstack.empty();
}

vector<string> generateParenthesis(int n)
{
	vector<string> result;



	return result;
}