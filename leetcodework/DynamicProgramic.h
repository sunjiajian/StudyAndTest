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


#define max(a,b) (((a) > (b)) ? (a) : (b))
#define min(a,b) (((a) < (b)) ? (a) : (b))

using namespace std;

// money为金钱面值组合，升序且起始为1，输出凑齐target的最少组合
inline vector<int> getLeastComb(vector<int> money, int target)
{
	if (target == 0 || money.size() == 0)
	{
		return vector<int>();
	}

	int moneyType = money.size();
	vector<vector<int>> allComb;
	allComb.push_back(vector<int>());

	for (int i = 1; i <= target; ++i)
	{
		int minF = INT_MAX;
		int minSub = -1;
		for (int j = 0; j < moneyType; ++j)
		{
			if (i >= money[j] && minF > allComb[i - money[j]].size())
			{
				minF = allComb[i - money[j]].size();
				minSub = j;
			}
		}
		vector<int> temp = allComb[i - money[minSub]];
		temp.push_back(money[minSub]);
		allComb.push_back(temp);
	}

	return allComb[target - 1];
}



struct Node
{
	Node* next;
};

inline Node* fzNode(Node* head)
{
	Node* pT = head;
	Node* pNewHead = head;
	Node* pPre = NULL;

	while (pT != NULL)
	{
		Node* pNext = pT->next;
		if (pNext == NULL)
		{
			pNewHead = pT;
		}

		pT->next = pPre;
		pPre = pT;
		pT = pNext;
	}

	return pNewHead;
}



