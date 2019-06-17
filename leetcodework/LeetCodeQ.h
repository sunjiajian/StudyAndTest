#pragma once

#include <algorithm>
#include <map>
#include <math.h>
#include <numeric>
#include <queue>
#include <deque>
#include <set>
#include <string>
#include <utility>
#include <vector>
#include <iostream> 
#include <fstream>
#include <hash_map>
#include <stack>
#include <algorithm>
#include <functional>

#define max(a,b) (((a) > (b)) ? (a) : (b))
#define min(a,b) (((a) < (b)) ? (a) : (b))


using namespace std;


#define __NameSpace_lc__ namespace lc{
#define __NameSpaceEnd__ }

__NameSpace_lc__

// 2
struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
}; 


class CLeetCodeQ
{
public:
	// 2
	static ListNode* addTwoNumbers(ListNode* l1, ListNode* l2);

	// 3
	static int lengthOfLongestSubstring(string s);

	// 4
	static double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2);

	// 5
	static string longestPalindrome(string s);

	// 6 todo
	static string convert(string s, int numRows);

	// 7
	static int reverse(int x);

	// 8 
	static int myAtoi(string str);

	// 9
	static bool isPalindrome(int x);

	// 10 todo
	static bool isMatch10(string s, string p);

	// 32 
	static int longestValidParentheses(string s);

	// 44
	static bool isMatch44(string s, string p);

	// 53
	static int maxSubArray(vector<int>& nums);
	
	// 62
	static int uniquePaths(int m, int n);

	// 63
	static int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid);

	// 64
	static int minPathSum(vector<vector<int>>& grid);

	// 70
	static int climbStairs(int n);

	// 84
	static int largestRectangleArea(vector<int>& heights);

	// 85 
	static int maximalRectangle(vector<vector<char>>& matrix);

	int good1;
	int good2;
	int good3;

	CLeetCodeQ() {}
	~CLeetCodeQ() {}
};

__NameSpaceEnd__