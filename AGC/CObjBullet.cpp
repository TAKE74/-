//使用するヘッダーファイル
#include "GameHead.h"
#include "CobjBullet.h"
#include "GameL\DrawTexture.h"
#include "GameL\HitBoxManager.h"

//使用するネームスペース
using namespace GameL;

//コントラクタ
CObjBullet::CObjBullet(float x, float y)
{
	b_x = x;
	b_y = y;
}
//イニシャライズ
void CObjBullet::Init()
{
	b_vx = 0.0f;

	//当たり判定用HitBoxを作成
	Hits::SetHitBox(this, b_x, b_y, 32, 32, ELEMENT_PLAYER, OBJ_BULLET, 1);
}

//アクション
void CObjBullet::Action()
{
	b_vx + 1.0f;
	b_x += b_vx;

	//弾丸のHitBox更新用ポインター取得
	CHitBox*hit = Hits::GetHitBox(this);
	hit->SetPos(b_x, b_y);

	//領域外に出たら弾丸を破壊する
	if (b_x > 800.0f)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
	}
	//当たり判定を行うオブジェクト情報群
	int data_base[4] =
	{
		OBJ_ENEMY,
		OBJ_SPECIAL_ENEMY,
		OBJ_MEDIUM_BOSS,
		OBJ_BOSS_ENEMY,
	};

	//オブジェクト情報群と当たり判定を行い、当たっていれば削除
	for (int i = 0; i < 2; i++)
	{
		if (hit->CheckObjNameHit(data_base[i]) != nullptr)
		{
			this->SetStatus(false);
			Hits::DeleteHitBox(this);
		}
	}
}

//ドロー
void CObjBullet::Draw()
{
	//描画カラー情報
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;	//描画元切り取り位置
	RECT_F dst;	//描画先表示位置

	//切り取り位置の設定
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 64.0f;
	src.m_bottom = 64.0f;

	//表示位置の設定
	dst.m_top = 0.0f+b_y;
	dst.m_left = 0.0f+b_x;
	dst.m_right = 32.0f+b_x;
	dst.m_bottom = 64.0f + b_y;

	//描画
	Draw::Draw(0, &src, &dst, c, 0.0f);
}

