#pragma once
//�g�p����w�b�_�[
#include "GameL\SceneObjManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g�F���{�X
class CObjMediumBoss:public CObj
{
public:
	CObjMediumBoss(float x, float y);//�R���g���N�^����������炤
	~CObjMediumBoss() {};
	void Init();	//�C�j�V�����C�Y
	void Action();	//�A�N�V����
	void Draw();	//�h���[
private:
	float m_x;	//�{�X��X�����̈ʒu
	float m_y;	//�{�X��Y�����̈ʒu
	float m_vx;	//�{�X�ړ��x�N�g��X
	float m_vy;	//�{�X�ړ��x�N�g��Y

	int m_hp;	//�{�X��HP

};
