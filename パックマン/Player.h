#ifndef PLAYER_H
#define PLAYER_H
#include "CharObject.h"
#include "DirectInput.h"
#include "Game.h"

#define PACMAN_W 10
#define PACMAN_H 10
#define PACMAN_TU 0.0625
#define PACMAN_TV 0.0625
#define MOVESPEED 5.f

#define INNTIAL_POSX 50.f
#define INNTIAL_POSY 50.f

class Player : public CharObjectBase{
public:
	Player();
	virtual ~Player();
	virtual void Draw();
	virtual void Update();

	enum Direction {
		UP,
		DOWN,
		RIGHT,
		LEFT
	};
	//����
	//����
	//�h�b�g��H�ׂ�
	//�A�C�e�����Ƃ������̋���
	//�G�ɓ����������̔���
	//�ǂɓ����������̔���
	//�ǂ��Ȃ���Ƃ��̑����i�p�b�N�}���̂ق��������j
	//���񂾂Ƃ��̋���
	int* GetPlayerTexture()
	{
		return &m_PlayerTexture;
	}
private:
	int m_PlayerTexture;
	Direction m_Directon;
	float m_Tu;
	float m_Tv;
	D3DXVECTOR2 m_Pos;
	KEYSTATE m_Key[KEYMAX] = { KEY_OFF };
};

class Enemy {
public:
	//����
	//����(�G�̂ق�����������)
	//�A�C�e�����Ƃ�ꂽ���̋���
	//�v���C���[�ɓ����������̋���
	//�ǂɓ����������̔���
	//�ǂ��Ȃ���Ƃ��̑����i�p�b�N�}���̂ق��������j
	//�v���C���[�ɐH�ׂ�ꂽ���̋���
	//�w�肳�ꂽ���[�g�ɍs��
};
#endif 
