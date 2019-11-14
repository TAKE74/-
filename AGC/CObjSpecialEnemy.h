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
	float m_posture;//姿勢

	int m_ani_time;//アニメーションフレーム動作間隔
	int m_ani_frame;//描画フレーム

	float m_speed_power;//スピードパワー
	float m_ani_max_time;//アニメーション動作間隔最大値


	//blockとの衝突状態確認用
	bool m_hit_up;
	bool m_hit_down;
	bool m_hit_left;
	bool m_hit_right;

	int m_hp;	//HP

};
