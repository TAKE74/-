#pragma once
//使用するヘッダーファイル
#include"GameL\SceneObjManager.h"

//使用するネームスペース
using namespace GameL;

//シーン：メイン
class CObjStag :public CObj
{
public:
	CObjStag() {};
	~CObjStag() {};
	void Init();//イニシャライズ
	void Action();//アクション
	void Draw();//ドロー
private:

};
