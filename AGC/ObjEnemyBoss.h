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
	float m_px;	//�{�X��X�����̈ʒu
	float m_py;	//�{�X��Y�����̈ʒu
	float m_vx;	//�{�X�ړ��x�N�g��X
	float m_vy;	//�{�X�ړ��x�N�g��Y
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

	int m_hp;	//�{�X��HP
};

