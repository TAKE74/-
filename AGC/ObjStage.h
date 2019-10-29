
#pragma once
//使用するヘッダーファイル
#include"GameL\SceneObjManager.h"

//使用するネームスペース
using namespace GameL;

//シーン：メイン
class CObjStage :public CObj
{
public:
	CObjStage() {};
	~CObjStage() {};
	void Init();//イニシャライズ
	void Action();//アクション
	void Draw();//ドロー
private:
	
};