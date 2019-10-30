//GameLで使用するヘッダー
#include "GameL\SceneManager.h"
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\DrawFont.h"
#include "ObjStage.h"

//使用するネームスペース
using namespace GameL;

//イニシャライズ
void CObjStage::Init()
{
	
}
//アクション
void CObjStage::Action()
{
	
}
//ドロー
void CObjStage::Draw()
{
	

	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	RECT_F src;//描画元切り取り位置
	RECT_F dst;//描画先表示位置

	//切り取り位置の設定
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 1920.0f;
	src.m_bottom = 1080.0f;

	
	//表示位置の設定
	dst.m_top = 0.0f;
	dst.m_left =0.0f;
	dst.m_right = 800.0f;
	dst.m_bottom = 600.0f;

	//描画
	Draw::Draw(0, &src, &dst, c, 0.0f);

	
}