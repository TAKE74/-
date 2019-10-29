//STLデバック機能をOFFにする
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameLで使用するヘッダー
#include "GameL\SceneObjManager.h"
#include "GameL\DrawTexture.h"
#include "GameL\DrawFont.h"
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
	p = Save::ExternalDataOpen(L"マップEasy.csv", &size);//外部データの読み込み

	int map[10][35];
	int count = 1;
	for (int i = 0; i < 10; i++)
	{

		for (int j = 0; j < 35; j++)
		{
			int w = 0;
			swscanf_s(&p.get()[count], L"%d", &w);

			map[i][j] = w;
			count += 2;
		}
	}

	//Font作成
	Font::SetStrTex(L"0123456789分秒");

	//グラフィック読み込み
	Draw::LoadImageW(L"背景.png", 0, TEX_SIZE_512);
	Draw::LoadImageW(L"image.png", 1,TEX_SIZE_512);
	

	//主人公オブジェクト作成
	CObjHero* obj = new CObjHero();
	Objs::InsertObj(obj, OBJ_HERO,12);

	//ブロックオブジェクト作成
	CObjBlock* objb = new CObjBlock(map);
	Objs::InsertObj(objb, OBJ_BLOCK, 13);

	//タイムオブジェクト作成
	CObjTime* objt = new CObjTime();
	Objs::InsertObj(objt, OBJ_TIME, 11);

	//ステージオブジェクト作成
	CObjStage* objs = new CObjStage();
	Objs::InsertObj(objs, OBJ_STAGE, 10);

	

}

//実行中メソッド
void CSceneMain::Scene()
{




}