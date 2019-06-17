#include "LeetCodeQ.h"
#include "DynamicProgramic.h"
#include "CppTest.h"

using namespace lc;

void leetCodeTest()
{
	// 2
	/*
	ListNode* l1 = new ListNode(2);
	l1->next = new ListNode(4);
	l1->next->next = new ListNode(3);
	ListNode* l2 = new ListNode(5);
	l2->next = new ListNode(6);
	l2->next->next = new ListNode(4);
	ListNode* l3 = addTwoNumbers(l1, l2);
	*/

	// 3
	/*
	string s = { "amqpcsrumjjufpu" };
	int ret = lengthOfLongestSubstring(s);
	return 0;
	*/

	// 4
	/*
	vector<int> nums1 = { 1,3,4 };
	vector<int> nums2;
	double ret = findMedianSortedArrays(nums1, nums2);
	*/

	// 5
	/*
	string s = { "abcda" };
	longestPalindrome(s);
	*/

	// 6
	/*
	string s = { "LEETCODEISHIRING" };
	convert(s, 4);
	*/

	// 8
	/*
	string s = { "  -42" };
	myAtoi(s);
	*/

	// 9
	// isPalindrome(12321);

	// 32
	/*
	string s = { "()(())" };
	CLeetCodeQ::longestValidParentheses(s);
	*/

	// 44
	/*
	string s = { "aa" };
	string p = { "*" };
	CLeetCodeQ::isMatch44(s, p);
	*/

	// 53
	/*
	vector<int> nums = { -2,1,-3,4,-1,2,1,-5,4 };
	CLeetCodeQ::maxSubArray(nums);
	*/

	// 63
	/*
	vector<vector<int>> obs = { { 0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0 },
		{ 0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
		{ 0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0 },
		{ 1,1,1,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,1,1,0,0,0,0,0,0,0,0,1,0,0,1 },
		{ 0,0,1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0 },
		{ 0,0,0,1,0,1,0,0,0,0,1,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,1,0 },
		{ 1,0,1,1,1,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0 },
		{ 0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,0,1,0,0,0,1,0,1,0,0,0,0,0,0 },
		{ 0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,1,0 },
		{ 0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,1,0,0,0,0,0 },
		{ 0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0 },
		{ 1,0,1,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,1,0,1,0,0,0,1,0,1,0,0,0,0,1 },
		{ 0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,1,0,0,0,0,0,0,1,1,0,0,0,0,0 },
		{ 0,1,0,1,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1,0,0,0,0,0 },
		{ 0,1,0,0,0,0,0,0,1,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,1,0,1 },
		{ 1,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
		{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,1,1,0,0,1,0,0,0,0,0,0 },
		{ 0,0,1,0,0,0,0,0,0,0,1,0,0,1,0,0,1,0,0,0,0,0,0,1,1,0,1,0,0,0,0,1,1 },
		{ 0,1,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,1,1,0,1,0,1 },
		{ 1,1,1,0,1,0,0,0,0,1,0,0,0,0,0,0,1,0,1,0,1,1,0,0,0,0,0,0,0,0,0,0,0 },
		{ 0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,1,1 },
		{ 0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,1,0,0,0,1,0,0,0 } 
	};
	CLeetCodeQ::uniquePathsWithObstacles(obs);
	*/

	// 84
	vector<int> heights = { 2,1,5,6,2,3 };
	CLeetCodeQ::largestRectangleArea(heights);

	// 85
	/*
	vector<vector<char>> matrix = {
		{ '0','1','1','0','1' },
		{ '1','1','0','1','0' },
		{ '0','1','1','1','0' },
		{ '1','1','1','1','0' },
		{ '1','1','1','1','1' } 
	};
	CLeetCodeQ::maximalRectangle(matrix);
	*/

}

void dynamicTest()
{
	vector<int> money = { 1,5,11 };
	getLeastComb(money, 15);
}

int main()
{
	ct::testVector2();

	vector<int> money = { 1,5,11 };
	cout << count_if(money.begin(), money.end(), not1(bind2nd(less<int>(), 40))) << endl;

	for (auto mn : money)
	{
		cout << mn << endl;
	}

	CLeetCodeQ clq;
	CLeetCodeQ* pclq = new CLeetCodeQ();
	int aaa = sizeof(CLeetCodeQ);
	int bbb = sizeof(clq);
	int ccc = sizeof(pclq);
	CLeetCodeQ* pclqar = new CLeetCodeQ[5];
	int ddd = sizeof(pclqar);

	char str1[] = { 'H', 'e', 'l', 'l', 'o' };
	char str2[] = "Hello";
	int a = sizeof(str1);
	int b = sizeof(str2);
	int c = strlen(str1);
	int d = strlen(str2);

	char *pch;
	int e = sizeof(pch);

	int aa = 999;
	int bb = 0;
	while (aa)
	{
		bb++;
		aa = aa & (aa - 1);
	}


	leetCodeTest();
	dynamicTest();
	return 0;
}