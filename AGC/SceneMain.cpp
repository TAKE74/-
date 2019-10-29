//STL�f�o�b�N�@�\��OFF�ɂ���
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameL�Ŏg�p����w�b�_�[
#include "GameL\SceneObjManager.h"
#include "GameL\DrawTexture.h"
#include "GameL\DrawFont.h"
#include "GameL\UserData.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�g�p�w�b�_�[
#include "SceneMain.h"
#include "GameHead.h"

//�R���g���N�^
CSceneMain::CSceneMain()
{





}

//�f�X�g���N�^
CSceneMain::~CSceneMain()
{




}

//���������\�b�h
void CSceneMain::InitScene()
{
	//�O���f�[�^�̓ǂݍ��݁i�X�e�[�W���j
	unique_ptr<wchar_t>p;//�X�e�[�W���|�C���^�[
	int size;
	p = Save::ExternalDataOpen(L"�}�b�vEasy.csv", &size);//�O���f�[�^�̓ǂݍ���

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

	//Font�쐬
	Font::SetStrTex(L"0123456789���b");

	//�O���t�B�b�N�ǂݍ���
	Draw::LoadImageW(L"�w�i.png", 0, TEX_SIZE_512);
	Draw::LoadImageW(L"image.png", 1,TEX_SIZE_512);
	

	//��l���I�u�W�F�N�g�쐬
	CObjHero* obj = new CObjHero();
	Objs::InsertObj(obj, OBJ_HERO,12);

	//�u���b�N�I�u�W�F�N�g�쐬
	CObjBlock* objb = new CObjBlock(map);
	Objs::InsertObj(objb, OBJ_BLOCK, 13);

	//�^�C���I�u�W�F�N�g�쐬
	CObjTime* objt = new CObjTime();
	Objs::InsertObj(objt, OBJ_TIME, 11);

	//�X�e�[�W�I�u�W�F�N�g�쐬
	CObjStage* objs = new CObjStage();
	Objs::InsertObj(objs, OBJ_STAGE, 10);

	

}

//���s�����\�b�h
void CSceneMain::Scene()
{




}