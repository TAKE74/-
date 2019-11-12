//�g�p����w�b�_�[�t�@�C��
#include "GameHead.h"
#include "CobjBullet.h"
#include "GameL\DrawTexture.h"
#include "GameL\HitBoxManager.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�R���g���N�^
CObjBullet::CObjBullet(float x, float y)
{
	b_x = x;
	b_y = y;
}
//�C�j�V�����C�Y
void CObjBullet::Init()
{
	b_vx = 0.0f;

	//�����蔻��pHitBox���쐬
	Hits::SetHitBox(this, b_x, b_y, 32, 32, ELEMENT_PLAYER, OBJ_BULLET, 1);
}

//�A�N�V����
void CObjBullet::Action()
{
	b_vx + 1.0f;
	b_x += b_vx;

	//�e�ۂ�HitBox�X�V�p�|�C���^�[�擾
	CHitBox*hit = Hits::GetHitBox(this);
	hit->SetPos(b_x, b_y);

	//�̈�O�ɏo����e�ۂ�j�󂷂�
	if (b_x > 800.0f)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
	}
	//�����蔻����s���I�u�W�F�N�g���Q
	int data_base[4] =
	{
		OBJ_ENEMY,
		OBJ_SPECIAL_ENEMY,
		OBJ_MEDIUM_BOSS,
		OBJ_BOSS_ENEMY,
	};

	//�I�u�W�F�N�g���Q�Ɠ����蔻����s���A�������Ă���΍폜
	for (int i = 0; i < 2; i++)
	{
		if (hit->CheckObjNameHit(data_base[i]) != nullptr)
		{
			this->SetStatus(false);
			Hits::DeleteHitBox(this);
		}
	}
}

//�h���[
void CObjBullet::Draw()
{
	//�`��J���[���
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;	//�`�挳�؂���ʒu
	RECT_F dst;	//�`���\���ʒu

	//�؂���ʒu�̐ݒ�
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 64.0f;
	src.m_bottom = 64.0f;

	//�\���ʒu�̐ݒ�
	dst.m_top = 0.0f+b_y;
	dst.m_left = 0.0f+b_x;
	dst.m_right = 32.0f+b_x;
	dst.m_bottom = 64.0f + b_y;

	//�`��
	Draw::Draw(0, &src, &dst, c, 0.0f);
}

