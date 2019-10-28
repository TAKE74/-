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

	//領域外に出たら弾丸を破壊する
	if (b_x > 800.0f)
	{
		this->SetStatus(false);
	}
	//弾丸のHitBox更新用ポインター取得
	CHitBox*hit = Hits::GetHitBox(this);
	hit->SetPos(b_x, b_y);	//HitBoxの位置を弾丸の位置に更新

	//敵オブジェクトと接触したら削除
	if (hit->CheckObjNameHit(OBJ_ENEMY) != nullptr)
	{
		this->SetStatus(false);		//自身に削除命令を出す。
		Hits::DeleteHitBox(this);	//弾丸が取得するHitBoxに削除する。
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

