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
	float m_px;	//X�����̈ʒu
	float m_py;	//Y�����̈ʒu
	float m_vx;	//�ړ��x�N�g��X
	float m_vy;	//�ړ��x�N�g��Y
	float m_posture;//�p��

	int m_ani_time;//�A�j���[�V�����t���[������Ԋu
	int m_ani_frame;//�`��t���[��

	float m_speed_power;//�X�s�[�h�p���[
	float m_ani_max_time;//�A�j���[�V��������Ԋu�ő�l


	//block�Ƃ̏Փˏ�Ԋm�F�p
	bool m_hit_up;
	bool m_hit_down;
	bool m_hit_left;
	bool m_hit_right;

	//�ړ��̌�������p
	bool m_move;

	int m_hp;	//HP

};
