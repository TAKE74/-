#pragma once
//�g�p����w�b�_�[
#include "GameL\SceneObjManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g�F����
class CObjSpecialEnemy:public CObj
{
public:
	CObjSpecialEnemy(float x,float y);//�R���g���N�^����������炤
	~CObjSpecialEnemy() {};
	void Init();	//�C�j�V�����C�Y
	void Action();	//�A�N�V����
	void Draw();	//�h���[
private:
	float m_x;	//X�����̈ʒu
	float m_y;	//Y�����̈ʒu
	float m_vx;	//�ړ��x�N�g��X
	float m_vy;	//�ړ��x�N�g��Y

	int m_hp;	//HP

};
