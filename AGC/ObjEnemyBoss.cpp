//使用するヘッダーファイル
#include "GameL\DrawTexture.h"
#include "GameL\HitBoxManager.h"

#include "GameHead.h"
#include "ObjEnemyBoss.h"


//使用するネームスペース
using namespace GameL;

//コントラクタ
CObjBoss::CObjBoss(float x, float y)
{
	B_x = x;
	B_y = y;
}

//イニシャライズ
void CObjBoss::Init()
{
	B_vx = 0.0f;
	B_vy = 0.0f;

	//当たり判定用HitBoxを作成
	Hits::SetHitBox(this, B_x, B_y, 32, 32, ELEMENT_ENEMY, OBJ_BOOS_ENEMY, 1);
}

//アクション
void CObjBoss::Action()
{
	//移動方向
	B_vx = -1.0f;
	B_vy = 0.0f;

	//移動ベクトルの正規化


	//速度を付ける
	B_vx *= 1.5f;
	B_vy *= 1.5f;

	//移動ベクトルを座標に加算する
	B_x += B_vx;
	B_y += B_vy;

	//HitBoxの内容を更新
	CHitBox*hit = Hits::GetHitBox(this);
	hit->SetPos(B_x, B_y);

	//ボスが完全に領域外に出たらボスを破壊する
	bool check=
	
}