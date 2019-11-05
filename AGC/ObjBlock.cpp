
//GameL�Ŏg�p����w�b�_�[
#include "GameL\SceneObjManager.h"
#include "GameL\SceneManager.h"
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameHead.h"
#include "ObjBlock.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

CObjBlock::CObjBlock(int map[10][101])
{
	//�}�b�v�f�[�^���R�s�[
	memcpy(m_map, map, sizeof(int)*(10 * 101));

}

//�C�j�V�����C�Y
void CObjBlock::Init()
{
	m_scroll = 0.0f;

}
//�A�N�V����
void CObjBlock::Action()
{    //��l���̈ʒu���擾
	CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	float hx = 0;
	float hy = 0;
	if (hero != nullptr)
	{
		hx = hero->GetX();
		hy = hero->GetY();
	}
	//����X�N���[��
	if (hx < 80)
	{

		hero->SetX(80);//��l���̓��C���𒴂��Ȃ��悤�ɂ���
		m_scroll -= hero->GetVX();//��l�����{�������ׂ����̒l��m_scroll�ɉ�����

	}

	//�O���X�N���[��
	if (hx > 300)
	{

		hero->SetX(300);//��l���̓��C���𒴂��Ȃ��悤�ɂ���B
		m_scroll -= hero->GetVX();//��l�����{�������ׂ����̒l��m_scroll�ɉ�����

	}

	//�G�o�����C��
	//��l���̈ʒu+500��G�o�����C���ɂ���
	float line = hx + (-m_scroll) + 500;

	//�G�o�����C����v�f�ԍ�
	int ex = ((int)line) / 64;

	//�G�o�����C���̗������
	for (int i = 0; i < 10; i++)
	{
		//��̒�����4��T��
	    if(m_map[i][ex]==4)
		{
	        //4������΁A�G�o��
			CObjEnemy* obje = new CObjEnemy(ex * 64.0f, i*64.0f);
			Objs::InsertObj(obje, OBJ_ENEMY, 10);

	                //�G�o���ꏊ�̒l��0�ɂ���
			m_map[i][ex] = 0;

	    }
	}
	
}

//�h���[
void CObjBlock::Draw()
{
	//�`��J���[���
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;//�`�挳�؂���ʒu
	RECT_F dst;//�`���\���ʒu
	
	//�w�i�\��

	src.m_top = 256.0f;
	src.m_left = 0.0f;
	src.m_right = 512.0;
	src.m_bottom = 512.0f;

	
	dst.m_top = 0.0f;
	dst.m_left = 0.0f;
	dst.m_right = 800.0f;
	dst.m_bottom = 600.0f;
	Draw::Draw(0, &src, &dst, c, 0.0f);





	//�}�b�v�`�b�v�ɂ��block�ݒu
	//�؂���ʒu�̐ݒ�

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			if (m_map[i][j] > 0)
			{

				//�\���ʒu�̐ݒ�
				dst.m_top = i * 64.0f;
				dst.m_left = j * 64.0f + m_scroll;
				dst.m_right = dst.m_left + 64.0;
				dst.m_bottom = dst.m_top + 64.0;

				if (m_map[i][j] == 2)
				{
					//�X�^�[�g�u���b�N
					BlockDraw(320.0f, 0.0f, &dst, c);
				}
				else if (m_map[i][j] == 3)
				{
					//�S�[���u���b�N
					BlockDraw(320.0f, 0.0f, &dst, c);

				}
				else if (m_map[i][j] == 4)
				{

					;//�G�z�u�p�̔ԍ��̂��߉������Ȃ�
				}
				else
				{
					BlockDraw(320.0f, 0.0f, &dst, c);
				}
			}
		}
	}

}
//BlockDrawMethod�֐�
//����1 flost    x      :���\�[�X�؂���ʒuX
//����2 float    y      :���\�[�X�؂���ʒuY
//����3 RECT_F*  dst    :�`��ʒu
//����4 float    c[]    :�J���[���
//�u���b�N��64�~64����`��p�B���\�[�X�؂���ʒu�݂̂�.y��
//�ݒ�ł���
void CObjBlock::BlockDraw(float x, float y, RECT_F* dst, float c[])
{
	RECT_F src;
	src.m_top = y;
	src.m_left = x;
	src.m_right = src.m_left + 64.0f;
	src.m_bottom = src.m_top + 64.0f;
	//�`��
	Draw::Draw(0, &src,  dst, c, 0.0f);


}


//BlocHit�֐�
//����1�@�@flost* x           :������s��object��X�ʒu
//����2�@�@float* y           :������s��object��Y�ʒu
//����3�@�@bool   scroll_on   :������s��object�̓X�N���[���̉e���^���Ă��邩�ǂ����itrue=�^����@false=�^���Ȃ��j
//����4    bool*  up          :�㉺���E����̏㕔���ɓ������Ă��邩�ǂ�����Ԃ�
//����5    bool*  down        :�㉺���E����̉������ɓ������Ă��邩�ǂ�����Ԃ�
//����6    bool*  left        :�㉺���E����̍������ɓ������Ă��邩�ǂ�����Ԃ�
//����7    bool*  right       :�㉺���E����̉E�����ɓ������Ă��邩�ǂ�����Ԃ�
//����8    float* vx          :���E���莞�̔����ɂ��ړ�����.�͂̒l��ς��ĕԂ�
//����9    float* vy          :�㉺����ɂ�鎩�R�����^���̈ړ�����.�͂̒l��ς��ĕԂ�
//����10   int*   bt          :���������莞�A����ȃu���b�N�̃^�C�v��Ԃ�
//������s��object�ƃu���b�N64�~64����ŁA�����蔻��ƍ��E������s��
//���̌��ʂ͈���4�`10�ɕԂ�
void CObjBlock::BlockHit(
	float *x, float *y, bool scroll_on,
	bool*up, bool*down, bool*left, bool*right,
	float* vx, float*vy, int*bt
)

{

	//�Փˏ�Ԋm�F�p�t���O�̏�����

	*up = false;
	*down = false;
	*left = false;
	*right = false;

	//����ł���block�̎�ނ̏�����
	*bt = 0;

	//m_map�̑S�v�f�ɃA�N�Z�X
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			if (m_map[i][j] > 0&&m_map[i][j]!=4)
			{
				//�v�f�ԍ������W�ɕύX
				float bx = j * 64.0f;
				float by = i * 64.0f;

				//�X�N���[���̉e��
				float scroll = scroll_on ? m_scroll : 0;

				//��l���ƃu���b�N�̂����蔻��
				if ((*x + (-scroll) + 64.0f > bx) && (*x + (-scroll) < bx + 64.0f) && (*y + 64.0f > by) && (*y < by + 64.0f))
				{
					//�㉺���E����

					//vector�̍쐬
					float rvx = (*x + (-scroll)) - bx;
					float rvy = *y - by;
					//��������zz�߂�
					float len = sqrt(rvx*rvx + rvy * rvy);
					//�p�x�����߂�
					float r = atan2(rvy, rvx);
					r = r * 180.0f / 3.14f;

					if (r <= 0.0f)
						r = abs(r);
					else
						r = 360.0f - abs(r);
					if (len < 88.0f)
					{
						//�p�x�ŏ㉺���E�𔻒�
						if ((r < 45 && r>0) || r > 315)
						{
							//�E
							*right = true;//��l���̍��̕������Փ˂��Ă���
							*x = bx + 64.0f + (scroll);//�u���b�N�̈ʒu+��l���̕�
							*vx = -(*vx)*0.1f;;//�|vx*�����W��


						}
						if (r > 45 && r < 135)
						{
							//��
							*down = true;//��l���̉��̕������Փ˂��Ă���
							*y = by - 64.0f;//�u���b�N�̈ʒu-��l���̕�
						   //��ނ�n���̃X�^�[�g�ƃS�[���̂ݕύX����
							if (m_map[i][j] >= 2)
								*bt = m_map[i][j];//�u���b�N�̗v�f�itype�j����l���ɓn��
							*vy = 0.0f;
						}
						if (r > 135 && r < 225)
						{
							//��
							*left = true;//��l���̉��̕������Փ˂��Ă���
							*x = bx - 64.0f + (scroll);//�u���b�N�̈ʒu+��l���̕�
							*vx = -(*vx)* 0.1f;//�|vx*�����W��
						}
						if (r > 225 && r < 315)
						{
							//��
							*up = true;//��l���̏�̕������Փ˂��Ă���B
							*y = by + 64.0f;;//�u���b�N�̈ʒu+��l���̕�
							if (*vy < 0)
							{

								*vy = (0.0f);

							}


						}
					}



				}

			}

		}

	}







}
//���ϊ֐�
//����1,2�@float   ax , ay   :A�x�N�g��  
//����3,4  float   bx , by   :B�x�N�g��
//�߂�l�@ float   :�ˉe
//���e�@�@A�x�N�g����B�x�N�g���œ��ς��s���ˉe�����߂�
float  CObjBlock::Dot(float ax, float ay, float bx, float by)
{
	float t = 0.0f;

	t = ax * bx + ay * by;

	return t;
}

//�O�ϊ֐�
//����1,2�@float   ax , ay  :A�x�N�g��
//����3,4�@float   bx , by  :B�x�N�g��
//�߂�l�@ float   :�ˉe
//���e�@�@A�x�N�g����B�x�N�g���œ��ς��s���ˉe�����߂�
float CObjBlock::Cross(float ax, float ay, float bx, float by)
{
	float t = 0.0f;

	t = ax * by - ay * bx;

	return t;
}

//���������߂�}�N��
#define   SGN(x)   1 - (x <= 0 )-(x < 0 )

//���Ɛ��ƌ�������
//�����@�@flost  1,2   a1x , a1y�@    :���x�N�g��A�̎n�_
//�����@�@flost  3,4   a2x , a2y�@    :���x�N�g��A�̎n�_
//�����@�@flost  5,6   b1x , b1y�@�@�@:�x�N�g��A�̎n�_
//�����@�@flost  7,8   b2x , b2y�@  �@:�x�N�g��A�̎n�_
//�����@�@flost  9,10  a1x�@�@�@�@    :��������x�N�g���̌����_�ʒu
//�߂�l�@bool   :true=�����_�L��@false=�����_�����@
//�����@�@���e�F������A.B�x�N�g���̌����_�������@out_px1��out_py�ɖ߂�
bool CObjBlock::LineCrossPoint(

	float a1x, float a1y, float  a2x, float a2y,
	float b1x, float b1y, float  b2x, float b2y,
	float*out_px, float*out_py
)

{
	//�G���[�R�[�h
	*out_px = -99999.0f;  *out_py = -99999.0f;

	//A�x�N�g���쐬�ia2��al�j
	float ax = a2x - a1x;  float ay = a2y - a1y;

	//B�x�N�g���쐬�ib2��b1)
	float bx = b1x - a1x;  float by = b2y - b1y;

	//C�x�N�g���쐬(b1��a1)
	float cx = b1x - a1x; float cy = b1y - a1y;

	//D�x�N�g���쐬�i��2��a1�j
	float dx = b2x - a1x; float dy = b2x - a1y;

	//A�~C�̎ˉe��A�~B�̎ˉe�����߂�
	float  t1 = Cross(ax, ay, cx, cy);
	float  t2 = Cross(ax, ay, dx, dy);

	//���������������ɂȂ��Ă��邩�ǂ������`�F�b�N
	if (SGN(t1) == SGN(t2))
		return false;  //��_�Ȃ�
	//�ˉe���Βl��
	t1 = abs(t1);   t2 = abs(t2);
	//��_�����߂�
	float px = bx * t1 + b1x;  float py = by * t1 + b1y;

	//AP�x�N�g���ip��a1�j
	float apx = px - a1x;     float apy = py - a1y;

	//BP�x�N�g���ip��a2�j
	float bpx = px - a2x;     float bpy = py - a2y;

	//A.AP�̎ˉe��A.BP�̎ˉe�����߂�
	float w1 = Dot(ax, ay, apx, apy);
	float w2 = Dot(ax, ay, bpx, bpy);

	//�����`�F�b�N
	if (SGN(w1) == SGN(w2))
		return false;//��_���O

	//��_��Ԃ�
	*out_px = px; *out_py = py;

	return true;


}

//��l���ƕǂ̌�������֐�
//����1,2�@float x,y           ;��l���̈ʒu
//����3,4�@float*out_px,out_y  ;��l���̈ړ��x�N�g��
//����5,6�@float*out           ;Bloc�Ƃ̌����_
//�����V�@�@float*out          ;�ʒu��������_�܂ł̋���
//��l���̈ʒu+�ړ��x�N�g���Ɗe�u���b�N�̕ӂŌ����_������s��
//�ł��߂���_�̈ʒu�Ƌ�����߂�
bool CObjBlock::HeroBlckCrossPoint(
	float x, float y, float vx, float vy,
	float *out_px, float *out_py, float*out_len
)
{
	bool pb = false;       //��_�m�F�p
	float len = 99999.0f; //��_�Ƃ̋���
	//�u���b�N�̕Ӄx�N�g��
	float edge[4][4] =
	{

		{0,0,64,0 },//��
		{64,0,64,64},//��
		{64,64,0,64},//	��
		{0,64,0,0  },//��

	};
	//m_map�̑S�v�f�ɃA�N�Z�X
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 101; j++)
		{
			if (m_map[i][j] > 0 && m_map[i][j] != 4)
			{
				//�u���b�N��4�ӂ����_��T��
				for (int k = 0; k < 4; k++)
				{
					//��_��T��
					float px, py;
					bool b;
					float l = 0.0f;
					b = LineCrossPoint(x, y, x + vx, y + vy,
						j * 64 + edge[k][0], i * 64 + edge[k][1], j * 64 + edge[k][2], i * 64 + edge[k][3],
						&px, &py);
					//��_�`�F�b�N
					if (b == true)
					{
						//��_�Ƃ̋��������߂�
						l = sqrt((px - x)*(px - x) + (py - y)*(py - y));
						//��������_�̒��ōł��������Z�����m��T��
						if (len > l)
						{
							len = l;
							*out_px = px;
							*out_py = py;
							pb = true;
						}


					}

				}


			}

		}

	}

	*out_len = len;
	return pb;


}











