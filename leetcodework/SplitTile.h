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
	//����
	void split(MELD_GROUP& meldGroup,bool& judge,int pre,int& now);
	
	//�ӷֶ�������ķ���
	void findJiang(vector<MELD_GROUP>& meldGroup);

	//��ʼ��MELD_GROUP
	MELD_GROUP initGroup();
};
