#pragma once
//使用するヘッダーファイル
#include"GameL\SceneObjManager.h"

//使用するネームスペース
using namespace GameL;

//シーン：メイン
class CObjTime :public CObj
{
public:
	CObjTime() {};
	~CObjTime() {};
	void Init();//イニシャライズ
	void Action();//アクション
	void Draw();//ドロー
private:
	int m_time;//時間
	bool m_flag_time;//時間計測スタートフラグ
};