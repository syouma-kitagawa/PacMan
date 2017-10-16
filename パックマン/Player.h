#ifndef PLAYER_H
#define PLAYER_H
#include "Object.h"
#include "DirectInput.h"

#define PACMAN_W 50
#define PACMAN_H 50
#define MOVESPEED 5.f

#define INNTIAL_POSX 50.f
#define INNTIAL_POSY 50.f

class Player : public ObjectBase{
public:
	Player();
	~Player();
	void SetUp();
	virtual void Draw();
	virtual void Update();
	//����
	//����
	//�h�b�g��H�ׂ�
	//�A�C�e�����Ƃ������̋���
	//�G�ɓ����������̔���
	//�ǂɓ����������̔���
	//�ǂ��Ȃ���Ƃ��̑����i�p�b�N�}���̂ق��������j
	//���񂾂Ƃ��̋���
	/*int GetPlayerTexture()
	{
		return m_PlayerTexture;
	}*/
	int* GetPlayerTextureOne()
	{
		return &m_PlayerTextureOne;
	}
	int* GetPlayerTextureTwo()
	{
		return &m_PlayerTextureTwo;
	}
	int *GetPlayerTextureThree()
	{
		return &m_PlayerTextureThree;
	}
private:
	int m_PlayerTextureOne;
	int m_PlayerTextureTwo;
	int m_PlayerTextureThree;
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
