
//GameLで使用するヘッダー
#include "GameL\SceneManager.h"
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\DrawFont.h"
#include "GameHead.h"
#include "ObjTime.h"

//使用するネームスペース
using namespace GameL;

//イニシャライズ
void CObjTime::Init()
{
	m_time = 0;
	m_flag_time = false;
}
//アクション
void CObjTime::Action()
{
	//主人公の位置を取得
	CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	//スタートブロックを踏んでいるならフラグをオンにする
	if (hero->GetBT() == 2)
	{

		m_flag_time = true;

	}
	else if (hero->GetBT() == 3)
	{

		m_flag_time = false;

	}
	//フラグがオンの時、時間を進める
	if (m_flag_time == true)
	{
		m_time++;
	}
}
//ドロー
void CObjTime::Draw()
{
	//m_timeから秒分を求める
	int minute;//分
	int second;//秒

	second = (m_time / 60) % 60;
	minute = (m_time / 60) / 60;

	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	wchar_t str[128];
	//分：秒の値を文字列化
	if(second<10)
		swprintf_s(str, L"%d分0%d秒", minute, second);//秒の1桁目に0を用意
	else
		swprintf_s(str,L"%d分:%d秒",minute,second);//分：秒の値を文字列化
    
	Font::StrDraw(str, 10, 10, 20, c);
}