#pragma once
#include <vector>

/*   牌型定义
			wan           bing                      tiao
		0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33
		1,2,3,4,5,6,7,8,9,1, 2, 3, 4, 5, 6, 7, 8, 9, 1, 2, 3, 4, 5, 6, 7, 8, 9,中,发,白,东,南,西,北
		*/

#define TILE_TYPE_COUNT 34 //牌种类数，共三类牌1~9 东南西北中发白
#define HANDS_COUNT 14 //最大手牌数
#define TYPE_COUNT 9   //每门最大张数
#define MAX_TILE_VALUE 100 //牌的最大价值 
#define TOTAL_TILE_COUNT 136 //总共有的牌数

#define WAN     0  //万类的起始从0起
#define BING    9 //饼类的起始
#define TIAO   18  //条类的起始
#define EAST   27
#define SOUTH  28
#define WEST   29
#define NORTH  30
#define ZHONG  31
#define FA     32
#define BAI    33


enum MELD_TYPE{
	QUARTETTE, //杠
	TRIPLET, //刻
	SEQUENCE, //顺
	PAIR,  //对
	JIANG, //将
	CONNECTOR1, //连张
	CONNECTOR2, //隔张
	SINGLE, //单牌
} ;

struct MELD 
{
	MELD_TYPE type;
	int tile; //牌型中最小的一张
};

struct MELD_GROUP
{
	int tiles[TILE_TYPE_COUNT]; //未拆分手牌
	MELD melds[HANDS_COUNT]; //已拆分出的牌组

	int meldCount; //已拆分出的牌组数
	int singleCount; //单数量
	int pairCount; //对数量
	int connectorCount; //搭数量
	int fuCount; //副的数量
	int jiangCount;   //有无将牌

	double meldsValue[HANDS_COUNT];
	double values[TILE_TYPE_COUNT]; //分值
	int fuValueKey[TILE_TYPE_COUNT]; //组副算牌价值的key

	int winDistance; //该拆分的和牌距离  
};

enum ACTION_TYPE 
{
	DISCARD, //打
	CHOW, //吃
	PUNG, //碰
	KONG, //杠
	MINGGANG,
	ANGANG,
	BUGANG,
	READY, //听0
	WIN, //和
	PASS //表示无动作
};

struct ACTION 
{
	ACTION_TYPE type; //动作类型
	int tiles[2]; //如果是吃，标出用哪两张吃,一张牌的动作取第一张
};
