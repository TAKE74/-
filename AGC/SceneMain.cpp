//STLデバック機能をOFFにする
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameLで使用するヘッダー
#include "GameL\SceneObjManager.h"
#include "GameL\DrawTexture.h"

#include "GameL\UserData.h"

//使用するネームスペース
using namespace GameL;

//使用ヘッダー
#include "SceneMain.h"
#include "GameHead.h"

//コントラクタ
CSceneMain::CSceneMain()
{





}

//デストラクタ
CSceneMain::~CSceneMain()
{




}

//初期化メソッド
void CSceneMain::InitScene()
{
	//外部データの読み込み（ステージ情報）
	unique_ptr<wchar_t>p;//ステージ情報ポインター
	int size;
	p = Save::ExternalDataOpen(L"マップEasy(仮).csv", &size);//外部データの読み込み

	int map[10][101];
	int count = 1;
	for (int i = 0; i < 10; i++)
	{

		for (int j = 0; j < 100; j++)
		{
			int w = 0;
			swscanf_s(&p.get()[count], L"%d", &w);

			map[i][j] = w;
			count += 2;
		}
	}

	//グラフィック読み込み
	Draw::LoadImageW(L"image.png", 0,TEX_SIZE_512);
	


	//主人公オブジェクト作成
	CObjHero* obj = new CObjHero();
	Objs::InsertObj(obj, OBJ_HERO,12);

	//ブロックオブジェクト作成
	CObjBlock* objb = new CObjBlock(map);
	Objs::InsertObj(objb, OBJ_BLOCK, 9);

	//ボスオブジェクト作成
	CObjBoss*obj_boss_enemy = new CObjBoss(300, 300);	//ボスオブジェクト
	Objs::InsertObj(obj_boss_enemy, OBJ_BOSS_ENEMY, 1);	//ボスオブジェクト


}

//実行中メソッド
void CSceneMain::Scene()
{
	m_time++;
	if (m_time == 1)
	{
		CObjEnemy*obj = new CObjEnemy(799.0f, 400);
		Objs::InsertObj(obj,OBJ_ENEMY, 50);
	}

	else if (m_time == 2)
	{
		CObjEnemy*obj = new CObjEnemy(799.0f, 300);
		Objs::InsertObj(obj, OBJ_ENEMY, 50);
	}

	else if (m_time == 3)
	{
		CObjEnemy*obj = new CObjEnemy(799.0f, 300);
		Objs::InsertObj(obj, OBJ_ENEMY, 50);
	}

	else if (m_time == 4)
	{
		CObjEnemy*obj = new CObjEnemy(799.0f, 300);
		Objs::InsertObj(obj, OBJ_ENEMY, 50);
	}



}