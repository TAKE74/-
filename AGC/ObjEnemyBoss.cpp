//�g�p����w�b�_�[�t�@�C��
#include "GameL\DrawTexture.h"
#include "GameL\HitBoxManager.h"

#include "GameHead.h"
#include "ObjEnemyBoss.h"


//�g�p����l�[���X�y�[�X
using namespace GameL;

//�R���g���N�^
CObjBoss::CObjBoss(float x, float y)
{
	B_x = x;
	B_y = y;
}

//�C�j�V�����C�Y
void CObjBoss::Init()
{
	B_vx = 0.0f;
	B_vy = 0.0f;

	//�����蔻��pHitBox���쐬
	Hits::SetHitBox(this, B_x, B_y, 32, 32, ELEMENT_ENEMY, OBJ_BOOS_ENEMY, 1);
}

//�A�N�V����
void CObjBoss::Action()
{
	//�ړ�����
	B_vx = -1.0f;
	B_vy = 0.0f;

	//�ړ��x�N�g���̐��K��


	//���x��t����
	B_vx *= 1.5f;
	B_vy *= 1.5f;

	//�ړ��x�N�g�������W�ɉ��Z����
	B_x += B_vx;
	B_y += B_vy;

	//HitBox�̓��e���X�V
	CHitBox*hit = Hits::GetHitBox(this);
	hit->SetPos(B_x, B_y);

	//�{�X�����S�ɗ̈�O�ɏo����{�X��j�󂷂�
	bool check=
	
}