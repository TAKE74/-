//STL�f�o�b�N�@�\��OFF�ɂ���
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameL�Ŏg�p����w�b�_�[
#include "GameL\SceneObjManager.h"
#include "GameL\DrawTexture.h"

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
	p = Save::ExternalDataOpen(L"�}�b�vEasy(��).csv", &size);//�O���f�[�^�̓ǂݍ���

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

	//�O���t�B�b�N�ǂݍ���
	Draw::LoadImageW(L"image.png", 0,TEX_SIZE_512);
	


	//��l���I�u�W�F�N�g�쐬
	CObjHero* obj = new CObjHero();
	Objs::InsertObj(obj, OBJ_HERO,12);

	//�u���b�N�I�u�W�F�N�g�쐬
	CObjBlock* objb = new CObjBlock(map);
	Objs::InsertObj(objb, OBJ_BLOCK, 9);

	//�{�X�I�u�W�F�N�g�쐬
	CObjBoss*obj_boss_enemy = new CObjBoss(300, 300);	//�{�X�I�u�W�F�N�g
	Objs::InsertObj(obj_boss_enemy, OBJ_BOSS_ENEMY, 1);	//�{�X�I�u�W�F�N�g


}

//���s�����\�b�h
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