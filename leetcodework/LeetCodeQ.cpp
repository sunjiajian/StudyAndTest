#include "leetcodeq.h"

using namespace lc;

ListNode* CLeetCodeQ::addTwoNumbers(ListNode * l1, ListNode * l2)
{
	ListNode* head = new ListNode(0);
	ListNode* temp = head;
	ListNode* l1tmp = l1->next;
	ListNode* l2tmp = l2->next;

	int val = l1->val + l2->val;
	int tt = val / 10;
	temp->val = val % 10;

	while (tt > 0 || l1tmp != NULL || l2tmp != NULL)
	{
		temp->next = new ListNode(0);
		temp = temp->next;

		val = tt;
		if (l1tmp != NULL)
		{
			val += l1tmp->val;
			l1tmp = l1tmp->next;
		}
		if (l2tmp != NULL)
		{
			val += l2tmp->val;
			l2tmp = l2tmp->next;
		}
		tt = val / 10;
		temp->val = val % 10;
	}

	return head;
}

int CLeetCodeQ::lengthOfLongestSubstring(string s)
{
	int len = s.size();
	if (len <= 1)
	{
		return len;
	}

	int mLen = 1;
	int beginSub = 0, newSub = 1, sameSub = -1;
	for (beginSub = 0, newSub = 1; beginSub < len - 1 && newSub < len;)
	{
		sameSub = -1;
		for (int i = beginSub; i < newSub; ++i)
		{
			if (s[newSub] == s[i])
			{
				sameSub = i;
				break;
			}
		}

		if (sameSub >= 0)
		{
			beginSub = sameSub + 1;
		}
		++newSub;
		if (newSub - beginSub > mLen)
		{
			mLen = newSub - beginSub;
		}
	}

	return mLen;
	/*
	int len = s.size();
	if (len <= 1)
	{
	return len;
	}

	int mLen = 1;
	deque<char> cs;
	cs.push_back(s[0]);

	for (int newSub = 1; newSub < len; ++newSub)
	{
	int sameSub = -1;
	for (int i = 0, size = cs.size(); i < size; ++i)
	{
	if (s[newSub] == cs[i])
	{
	sameSub = i;
	break;
	}
	}

	while (sameSub-- >= 0)
	{
	cs.pop_front();
	}
	cs.push_back(s[newSub]);
	if (cs.size() > mLen)
	{
	mLen = cs.size();
	}
	}

	return mLen;
	*/
}

double CLeetCodeQ::findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
{
	int len1 = nums1.size();
	int len2 = nums2.size();
	int mid = (len1 + len2) / 2;
	double midVal1 = 0;
	double midVal2 = 0;

	for (int i = 0, j = 0; (i + j <= mid) && (i < len1 || j < len2); )
	{
		midVal1 = midVal2;
		if (i >= len1)
		{
			midVal2 = nums2[j];
			++j;
		}
		else if (j >= len2)
		{
			midVal2 = nums1[i];
			++i;
		}
		else if (nums1[i] < nums2[j])
		{
			midVal2 = nums1[i];
			++i;
		}
		else
		{
			midVal2 = nums2[j];
			++j;
		}
	}

	if ((len1 + len2) % 2 == 1)
	{
		return midVal2;
	}
	else
	{
		return (midVal1 + midVal2) / 2;
	}
}

string CLeetCodeQ::longestPalindrome(string s)
{	// 中心拓展
	string longest;
	int len = s.length();

	for (int i = 0; i < len; ++i)
	{
		int maxLen = 1;
		for (int j = 1; i - j >= 0 && i + j < len; ++j)
		{
			if (s[i - j] == s[i + j])
			{
				maxLen += 2;
			}
			else
			{
				break;
			}
		}
		if (maxLen > longest.length())
		{
			longest = s.substr(i - maxLen / 2, maxLen);
		}
	}

	for (int i = 0; i < len - 1; ++i)
	{
		if (s[i] == s[i + 1])
		{
			int maxLen = 2;
			for (int j = 1; i - j >= 0 && i + 1 + j < len; ++j)
			{
				if (s[i - j] == s[i + 1 + j])
				{
					maxLen += 2;
				}
				else
				{
					break;
				}
			}
			if (maxLen > longest.length())
			{
				longest = s.substr(i - maxLen / 2 + 1, maxLen);
			}
		}
	}

	return longest;
}

string CLeetCodeQ::convert(string s, int numRows)
{
	return string();
}

int CLeetCodeQ::reverse(int x)
{	/*
	int rev = 0;
	while (x != 0)
	{
	int pop = x % 10;
	x /= 10;
	if (rev > INT_MAX/10 || (rev == INT_MAX / 10 && pop > 7))
	return 0;
	if (rev < INT_MIN/10 || (rev == INT_MIN / 10 && pop < -8))
	return 0;
	rev = rev * 10 + pop;
	}
	return rev;
	*/
	int rx = x;
	int xz = x > 0 ? 1 : -1;
	int lx[10];
	int mx[10] = { 2,1,4,7,4,8,3,6,4,7 };
	mx[9] = x > 0 ? 7 : 8;

	int len = 0;
	for (; rx != 0 && len < 10; ++len, rx /= 10)
	{
		lx[len] = rx % 10 * xz;
	}

	if (len == 10)
	{
		for (int i = 0; i < 10; ++i)
		{
			if (lx[i] > mx[i])
			{
				return 0;
			}
			else if (lx[i] < mx[i])
			{
				break;
			}
		}
	}

	int retX = 0;
	for (int i = 0; i < len; ++i)
	{
		retX = retX * 10 + lx[i];
	}
	return retX * xz;
}

int CLeetCodeQ::myAtoi(string str)
{
	int len = str.length();
	int tag = 0; // 0:寻找第一个字符; 1:寻找数字
	int zf = 1;
	int val = 0;
	for (int i = 0; i < len; ++i)
	{
		if (tag == 0)
		{
			if (str[i] == '+')
			{
				tag = 1;
			}
			else if (str[i] == '-')
			{
				zf = -1;
				tag = 1;
			}
			else if (str[i] >= '0' && str[i] <= '9')
			{
				val = str[i] - '0';
				tag = 1;
			}
			else if (str[i] != ' ')
			{
				return 0;
			}
		}
		else if (str[i] >= '0' && str[i] <= '9')
		{
			if (val > 0)
			{
				val *= zf;
			}
			if (val > INT_MAX / 10 || (val == INT_MAX / 10 && str[i] > '7'))
			{
				return INT_MAX;
			}
			if (val < INT_MIN / 10 || (val == INT_MIN / 10 && str[i] > '8'))
			{
				return INT_MIN;
			}
			val = val * 10 + (str[i] - '0') * zf;
		}
		else
		{
			break;
		}
	}

	return val;
}

bool CLeetCodeQ::isPalindrome(int x)
{
	if (x < 0)
	{
		return false;
	}

	int newX = 0;
	int oldX = x;

	while (oldX > 0)
	{
		if (newX > INT_MAX / 10 || (newX == INT_MAX / 10 && oldX > 7))
		{
			return false;
		}
		newX = newX * 10 + oldX % 10;
		oldX /= 10;
	}

	return newX == x;
}

bool CLeetCodeQ::isMatch10(string s, string p)
{
	return false;
}

int CLeetCodeQ::longestValidParentheses(string s)
{
	int len = s.size();
	vector<int> fn;
	fn.push_back(0);
	int longest = 0;

	for (int i = 1; i < len; ++i)
	{
		if (s[i] != ')')
		{
			fn.push_back(0);
		}
		else if (s[i - 1] == '(')
		{
			if (i >= 2)
			{
				fn.push_back(fn[i - 2] + 2);
			}
			else
			{
				fn.push_back(2);
			}
		}
		else if (fn[i - 1] > 0 && i - fn[i - 1] - 1 >= 0 && s[i - fn[i - 1] - 1] == '(')
		{
			fn.push_back(fn[i - 1] + 2);
			if (i - fn[i - 1] - 2 >= 0)
			{
				fn[i] += fn[i - fn[i - 1] - 2];
			}
		}
		else
		{
			fn.push_back(0);
		}
		longest = max(longest, fn[i]);
	}

	return longest;
}

bool CLeetCodeQ::isMatch44(string s, string p)
{
	int lenS = s.length();
	int lenP = p.length();

	vector<vector<bool>> dp; // dp[i][j]表示，s从1-i与p从1-j是否匹配(下标从1开始)；

	for (int i = 0; i <= lenS; ++i)
	{
		dp.push_back(vector<bool>());
		for (int j = 0; j <= lenP; ++j)
		{
			dp[i].push_back(false);
		}
	}

	dp[0][0] = true;
	for (int j = 1; j <= lenP; ++j)
	{
		if (p[j - 1] == '*')
		{
			dp[0][j] = dp[0][j - 1];
		}
	}

	for (int i = 1; i <= lenS; ++i)
	{
		int si = i - 1;
		for (int j = 1; j <= lenP; ++j)
		{
			int pj = j - 1;
			if (s[si] == p[pj] || p[pj] == '?')
			{
				dp[i][j] = dp[i - 1][j - 1];
			}
			else if (p[pj] == '*')
			{
				dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
			}
		}
	}

	return dp[lenS][lenP];

	// 网站上的回溯法，效率奇高
	/*
	int i = 0;
    int j = 0;
    int star = -1;
    int k = 0; // 记录最后一次匹配的位置  + 1
        
    while (i < s.length()) {
        if (s[i] == p[j] || p[j] == '?') {
            ++i;
            ++j;
            continue;
        }
            
        if (p[j] == '*') {
            star = j++;
            k = i;
            continue;
        }
            
        // 如果失配了，回溯到 k + 1，即让 * 再多吞噬一个字符。
        if (star != -1) {
            i = ++k;
            j = star + 1;
            continue;
        }
        return false;
    }
        
    while (j < p.length() && p[j] == '*') ++j;
        
    return j == p.length();
	*/
}

int CLeetCodeQ::maxSubArray(vector<int>& nums)
{
	int len = nums.size();
	if (len == 0)
	{
		return 0;
	}

	vector<int> sum;
	sum.push_back(nums[0]);

	int maxS = nums[0];
	for (int i = 1; i < len; ++i)
	{
		if (sum[i - 1] >= 0)
		{
			sum.push_back(sum[i - 1] + nums[i]);
		}
		else
		{
			sum.push_back(nums[i]);
		}
		maxS = max(maxS, sum[i]);
	}

	return maxS;
}

int CLeetCodeQ::uniquePaths(int m, int n)
{
	if (m == 0 || n == 0)
	{
		return 0;
	}

	vector<vector<int>> step;
	step.push_back(vector<int>(n, 1));

	for (int i = 1; i < m; ++i)
	{
		step.push_back(vector<int>(n, 0));
		for (int j = 0; j < n; ++j)
		{
			step[i][j] += step[i - 1][j];
			if (j > 0)
			{
				step[i][j] += step[i][j - 1];
			}
		}
	}
	return step[m - 1][n - 1];
}

int CLeetCodeQ::uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid)
{
	if (obstacleGrid.size() == 0 || obstacleGrid[0].size() == 0)
	{
		return 0;
	}

	vector<vector<long long>> step;
	for (int i = 0, size1 = obstacleGrid.size(); i < size1; ++i)
	{
		step.push_back(vector<long long>(obstacleGrid[i].size(), 0));
		step[0][0] = 1;
		for (int j = 0, size2 = step[i].size(); j < size2; ++j)
		{
			if (obstacleGrid[i][j] == 1)
			{
				step[i][j] = 0;
				continue;
			}
			if (i > 0 && obstacleGrid[i - 1][j] == 0)
			{
				step[i][j] += step[i - 1][j];
			}
			if (j > 0 && obstacleGrid[i][j - 1] == 0)
			{
				step[i][j] += step[i][j - 1];
			}
		}
	}

	return step[step.size() - 1][step[0].size() - 1];
}

int CLeetCodeQ::minPathSum(vector<vector<int>>& grid)
{
	if (grid.size() == 0 || grid[0].size() == 0)
	{
		return 0;
	}

	vector<vector<int>> pathSum = grid;
	int size1 = pathSum.size();
	int size2 = pathSum[0].size();

	for (int i = 0; i < size1; ++i)
	{
		for (int j = 0; j < size2; ++j)
		{
			if (i > 0 && j > 0)
			{
				pathSum[i][j] += min(pathSum[i - 1][j], pathSum[i][j - 1]);
			}
			else if (i > 0)
			{
				pathSum[i][j] += pathSum[i - 1][j];
			}
			else if (j > 0)
			{
				pathSum[i][j] += pathSum[i][j - 1];
			}
		}
	}

	return pathSum[size1 - 1][size2 - 1];
}

int CLeetCodeQ::climbStairs(int n)
{
	if (n == 0)
	{
		return 0;
	}

	vector<int> step;
	step.push_back(1);
	step.push_back(2);
	for (int i = 2; i < n; ++i)
	{
		step.push_back(step[i - 1] + step[i - 2]);
	}

	return step[n - 1];
}

int CLeetCodeQ::largestRectangleArea(vector<int>& heights)
{
	heights.push_back(0);
	stack<int> stk;
	int maxArea = 0;
	for (int i = 0; i<heights.size(); i++)
	{
		while (!stk.empty() && heights[i]<heights[stk.top()])
		{
			int top = stk.top();
			stk.pop();
			maxArea = max(maxArea, heights[top] * (stk.empty() ? i : (i - stk.top() - 1)));
		}
		stk.push(i);
	}
	return maxArea;
}

int CLeetCodeQ::maximalRectangle(vector<vector<char>>& matrix)
{
	if (matrix.size() == 0 || matrix[0].size() == 0)
	{
		return 0;
	}

	int size1 = matrix.size();
	int size2 = matrix[0].size();

	return 0;
}

