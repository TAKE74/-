#pragma once
//�g�p����w�b�_�[
#include "GameL\SceneObjManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g�F�{�X��
class CObjBoss:public CObj
{
public:
	CObjBoss(float x, float y);//�R���g���N�^�ʒu�������炤
	~CObjBoss() {};
	void Init();	//�C�j�V�����C�Y
	void Action();	//�A�N�V����
	void Draw();	//�h���[
private:
	float B_x;	//�{�X��X�����̈ʒu
	float B_y;	//�{�X��Y�����̈ʒu
	float B_vx;	//�{�X�ړ��x�N�g��X
	float B_vy;	//�{�X�ړ��x�N�g��Y
};

CObjBoss::CObjBoss()
{
}

CObjBoss::~CObjBoss()
{
}