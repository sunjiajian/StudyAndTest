#pragma once
#include <vector>
#include "MajongType.h"

using std::vector;

class SplitTile
{
public:
	void Operation();
	vector<MELD_GROUP> allGroup;

private:
	//分牌
	void split(MELD_GROUP& meldGroup,bool& judge,int pre,int& now);
	
	//加分多对做将的分牌
	void findJiang(vector<MELD_GROUP>& meldGroup);

	//初始化MELD_GROUP
	MELD_GROUP initGroup();
};
