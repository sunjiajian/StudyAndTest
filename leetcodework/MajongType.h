#pragma once
#include <vector>

/*   ���Ͷ���
			wan           bing                      tiao
		0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33
		1,2,3,4,5,6,7,8,9,1, 2, 3, 4, 5, 6, 7, 8, 9, 1, 2, 3, 4, 5, 6, 7, 8, 9,��,��,��,��,��,��,��
		*/

#define TILE_TYPE_COUNT 34 //������������������1~9 ���������з���
#define HANDS_COUNT 14 //���������
#define TYPE_COUNT 9   //ÿ���������
#define MAX_TILE_VALUE 100 //�Ƶ�����ֵ 
#define TOTAL_TILE_COUNT 136 //�ܹ��е�����

#define WAN     0  //�������ʼ��0��
#define BING    9 //�������ʼ
#define TIAO   18  //�������ʼ
#define EAST   27
#define SOUTH  28
#define WEST   29
#define NORTH  30
#define ZHONG  31
#define FA     32
#define BAI    33


enum MELD_TYPE{
	QUARTETTE, //��
	TRIPLET, //��
	SEQUENCE, //˳
	PAIR,  //��
	JIANG, //��
	CONNECTOR1, //����
	CONNECTOR2, //����
	SINGLE, //����
} ;

struct MELD 
{
	MELD_TYPE type;
	int tile; //��������С��һ��
};

struct MELD_GROUP
{
	int tiles[TILE_TYPE_COUNT]; //δ�������
	MELD melds[HANDS_COUNT]; //�Ѳ�ֳ�������

	int meldCount; //�Ѳ�ֳ���������
	int singleCount; //������
	int pairCount; //������
	int connectorCount; //������
	int fuCount; //��������
	int jiangCount;   //���޽���

	double meldsValue[HANDS_COUNT];
	double values[TILE_TYPE_COUNT]; //��ֵ
	int fuValueKey[TILE_TYPE_COUNT]; //�鸱���Ƽ�ֵ��key

	int winDistance; //�ò�ֵĺ��ƾ���  
};

enum ACTION_TYPE 
{
	DISCARD, //��
	CHOW, //��
	PUNG, //��
	KONG, //��
	MINGGANG,
	ANGANG,
	BUGANG,
	READY, //��0
	WIN, //��
	PASS //��ʾ�޶���
};

struct ACTION 
{
	ACTION_TYPE type; //��������
	int tiles[2]; //����ǳԣ�����������ų�,һ���ƵĶ���ȡ��һ��
};
