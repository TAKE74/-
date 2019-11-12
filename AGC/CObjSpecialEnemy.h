#pragma once
//使用するヘッダー
#include "GameL\SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト：特殊
class CObjSpecialEnemy:public CObj
{
public:
	CObjSpecialEnemy(float x,float y);//コントラクタから情報をもらう
	~CObjSpecialEnemy() {};
	void Init();	//イニシャライズ
	void Action();	//アクション
	void Draw();	//ドロー
private:
	float m_x;	//X方向の位置
	float m_y;	//Y方向の位置
	float m_vx;	//移動ベクトルX
	float m_vy;	//移動ベクトルY

	int m_hp;	//HP

};
