#include "SplitTile.h"


void SplitTile::Operation()
{
	int pre = -1;
	int now = 0;
	bool judge = false;
	MELD_GROUP meldGroup = initGroup();

	split(meldGroup, judge, pre, now);
}

void SplitTile::split(MELD_GROUP& meldGroup, bool& judge, int pre, int& now)   //pre 和 now 是记位的，用于去重复 如：77、78与78、77
{
	bool finish = true;
	for (int i = 0; i<TILE_TYPE_COUNT; i++)
	{
		if (meldGroup.tiles[i] > 0)
		{
			finish = false;
			bool nextJudge = false;

			//对  1
			if (meldGroup.tiles[i] >= 2)
			{
				if (now == 1)
				{
					nextJudge = true;
				}
				if (!judge || pre != 1)
				{
					MELD_GROUP copy = meldGroup;
					copy.tiles[i] = copy.tiles[i] - 2;
					MELD meld;
					if (copy.jiangCount == 0)
					{
						meld.type = MELD_TYPE(JIANG);
						meld.tile = i;
						copy.jiangCount = 1;
					}
					else
					{
						meld.type = MELD_TYPE(PAIR);
						meld.tile = i;
						copy.pairCount++;
					}
					copy.melds[copy.meldCount] = meld;
					copy.meldCount++;
					now = 1;
					pre = 1;  //递归之前更改，保存给子调用的记录
					split(copy, nextJudge, pre, now);
					pre = 1;  //递归之后更改，提供给下一个分支使用
				}
			}
			// 刻 2
			if (meldGroup.tiles[i] >= 3)
			{
				if (now == 2)
				{
					nextJudge = true;
				}
				if (!judge || pre != 2)
				{
					MELD_GROUP copy = meldGroup;
					copy.tiles[i] = copy.tiles[i] - 3;
					MELD meld = { MELD_TYPE(TRIPLET), i };
					copy.melds[copy.meldCount] = meld;
					copy.meldCount++;
					copy.fuCount++;
					//copy.isSevenPair = false;
					now = 2;
					pre = 2;
					split(copy, nextJudge, pre, now);
					pre = 2;
				}
			}
			//顺 3
			if (((i >= WAN && i < WAN + TYPE_COUNT - 2)
				|| (i >= TIAO && i<TIAO + TYPE_COUNT - 2)
				|| (i >= BING && i<BING + TYPE_COUNT - 2))
				&& meldGroup.tiles[i + 1] > 0 && meldGroup.tiles[i + 2] > 0)
			{
				if (now == 3)
				{
					nextJudge = true;
				}
				if (!judge || pre != 3)
				{
					MELD_GROUP copy = meldGroup;
					copy.tiles[i]--;
					copy.tiles[i + 1]--;
					copy.tiles[i + 2]--;
					MELD meld = { MELD_TYPE(SEQUENCE), i };
					copy.melds[copy.meldCount] = meld;
					copy.meldCount++;
					copy.fuCount++;
					//copy.isSevenPair = false;
					now = 3;
					pre = 3;
					split(copy, nextJudge, pre, now);
					pre = 3;
				}
			}

			//连张 4
			if (((i >= WAN && i < WAN + TYPE_COUNT - 1)
				|| (i >= TIAO && i < TIAO + TYPE_COUNT - 1)
				|| (i >= BING && i<BING + TYPE_COUNT - 1))
				&& meldGroup.tiles[i + 1] > 0)
			{
				if (now == 4)
				{
					nextJudge = true;
				}
				if (!judge || pre != 4)  //pre == 6
				{
					MELD_GROUP copy = meldGroup;
					copy.tiles[i]--;
					copy.tiles[i + 1]--;
					MELD meld = { MELD_TYPE(CONNECTOR1), i };
					copy.melds[copy.meldCount] = meld;
					copy.meldCount++;
					copy.connectorCount++;
					//copy.isSevenPair = false;
					now = 4;
					pre = 4;
					split(copy, nextJudge, pre, now);
					pre = 4;
				}
			}
			//隔张 5
			if (((i >= WAN && i < WAN + TYPE_COUNT - 2)
				|| (i >= TIAO && i < TIAO + TYPE_COUNT - 2)
				|| (i >= BING && i<BING + TYPE_COUNT - 2))
				&& meldGroup.tiles[i + 2] > 0)
			{
				if (now == 5)
				{
					nextJudge = true;
				}
				if (!judge || pre != 5)
				{
					MELD_GROUP copy = meldGroup;
					copy.tiles[i]--;
					copy.tiles[i + 2]--;
					MELD meld = { MELD_TYPE(CONNECTOR2), i };
					copy.melds[copy.meldCount] = meld;
					copy.meldCount++;
					copy.connectorCount++;
					//copy.isSevenPair = false;
					now = 5;
					pre = 5;
					split(copy, nextJudge, pre, now);
					pre = 5;
				}
			}
			//单张 6
			if (now == 6)
			{
				nextJudge = true;
			}
			if (!judge || pre != 6)
			{
				meldGroup.tiles[i]--;
				MELD meld = { MELD_TYPE(SINGLE), { (char)i } };
				meldGroup.melds[meldGroup.meldCount] = meld;
				meldGroup.meldCount++;
				meldGroup.singleCount++;
				now = 6;
				pre = 6;
				split(meldGroup, nextJudge, pre, now);
				pre = 6;
			}

		}
	}
	if (finish)
	{
		allGroup.push_back(meldGroup);
		if (meldGroup.fuCount == 3)
		{
			int iiii = 0;
		}
		//print_meld_group(meldGroup);
	}
}

void SplitTile::findJiang(vector<MELD_GROUP>& meldGroup)
{
	int size = meldGroup.size();
	for (int i = 0; i<size; ++i)
	{
		if (meldGroup.at(i).jiangCount == 1 && meldGroup.at(i).pairCount>0)
		{
			int pos = 0;
			int jiang = 0;
			for (int m = 0; m < meldGroup.at(i).meldCount; m++)
			{
				if (meldGroup.at(i).melds[m].type == JIANG)
				{
					jiang = m;
					break;
				}
			}
			for (int n = 0; n < meldGroup.at(i).pairCount; n++)
			{
				MELD_GROUP newMeld = meldGroup.at(i);
				for (pos; pos < newMeld.meldCount; pos++)
				{
					if (newMeld.melds[pos].type == PAIR)
					{
						newMeld.melds[pos].type = JIANG;
						pos++; //break之后pos不增加了
						break;
					}
				}
				newMeld.melds[jiang].type = PAIR;
				meldGroup.push_back(newMeld);
			}
		}
	}
}

MELD_GROUP SplitTile::initGroup()
{
	MELD_GROUP initGroup;

	for (int i = 0; i < TILE_TYPE_COUNT; i++)
	{
		initGroup.tiles[i] = 0;
	}
	initGroup.tiles[0] = 3;
	initGroup.tiles[1] = 1;

	//initGroup.isSevenPair = false;
	initGroup.jiangCount = 0;
	//initGroup.is131 = false;
	initGroup.meldCount = 0;
	initGroup.pairCount = 0;
	initGroup.singleCount = 0;
	initGroup.connectorCount = 0;
	initGroup.fuCount = 0;

	return initGroup;
}