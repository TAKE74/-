#pragma once
//使用するヘッダー
#include "GameL\SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト：ボス戦
class CObjBoss:public CObj
{
public:
	CObjBoss(float x, float y);//コントラクタ位置情報をもらう
	~CObjBoss() {};
	void Init();	//イニシャライズ
	void Action();	//アクション
	void Draw();	//ドロー
private:
	float m_x;	//ボスのX方向の位置
	float m_y;	//ボスのY方向の位置
	float m_vx;	//ボス移動ベクトルX
	float m_vy;	//ボス移動ベクトルY

	int m_hp;	//ボスのHP
};

