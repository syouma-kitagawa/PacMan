#include "Player.h"
#include "DirectGraphics.h"
#include "Game.h"
#include "DirectInput.h"


Player::Player():m_Pos(INNTIAL_POSX, INNTIAL_POSY)
{
	m_Collision = new Collision();
	m_Collision->SetPosition(m_Pos);
	m_Collision->SetSize(D3DXVECTOR2(PACMAN_W * 2, PACMAN_H * 2));
	m_Collision->SetCoolisionId(Collision::PLAYER);
}

Player::~Player()
{
	delete m_Collision;
}

void Player::Draw()
{
	CUSTOMVERTEX DrawPacMan[4];
	static CUSTOMVERTEX  PacManVertex[4]
	{
		{ -PACMAN_W, -PACMAN_H, 1.f, 1.f, 0xFFFFFFFF, 0.f, 0.f },
		{  PACMAN_W, -PACMAN_H, 1.f, 1.f, 0xFFFFFFFF, PACMAN_TU, 0.f },
		{  PACMAN_W,  PACMAN_H, 1.f, 1.f, 0xFFFFFFFF, PACMAN_TU, PACMAN_TV },
		{ -PACMAN_W,  PACMAN_H, 1.f, 1.f, 0xFFFFFFFF, 0.f,PACMAN_TV }
	};
	//�ʒu�ƒ��_������
	for (int i = 0; i < 4; i++)
	{
		DrawPacMan[i] = PacManVertex[i];
		DrawPacMan[i].x += m_Pos.x;
		DrawPacMan[i].y += m_Pos.y;
	}
	//���̉摜����ɕ����]������
	switch (m_Directon)
	{
	case Player::UP:
		DirectGraphics::GetpInstance()->Direction_Up(DrawPacMan);
		break;
	case Player::DOWN:
		DirectGraphics::GetpInstance()->Direction_Down(DrawPacMan);
		break;
	case Player::RIGHT:
		DirectGraphics::GetpInstance()->Direction_Right(DrawPacMan);
		break;
	case Player::LEFT:
		break;
	}
	static int Fcount = 0;
	int remainder = Fcount % 15;
	if (remainder <= 4)
	{
		DirectGraphics::GetpInstance()->Render(&m_PlayerTexture, DrawPacMan);
	}
	else if(remainder <= 9)
	{
		DrawPacMan[0].tu += PACMAN_TU;
		DrawPacMan[1].tu += PACMAN_TU;
		DrawPacMan[2].tu += PACMAN_TU;
		DrawPacMan[3].tu += PACMAN_TU;
		DirectGraphics::GetpInstance()->Render(&m_PlayerTexture, DrawPacMan);
	}
	else if(remainder <= 14)
	{
		DrawPacMan[0].tu += PACMAN_TU*2;
		DrawPacMan[1].tu += PACMAN_TU*2;
		DrawPacMan[2].tu += PACMAN_TU*2;
		DrawPacMan[3].tu += PACMAN_TU*2;
		DirectGraphics::GetpInstance()->Render(&m_PlayerTexture, DrawPacMan);
	}
	if (Fcount != 60)
	{
		Fcount++;
	}
	else
	{
		Fcount = 0;
	}
}

void Player::Update()
{
	DirectInput::pInstance->KeyCheck(&m_Key[KEY_W], DIK_W);
	DirectInput::pInstance->KeyCheck(&m_Key[KEY_A], DIK_A);
	DirectInput::pInstance->KeyCheck(&m_Key[KEY_S], DIK_S);
	DirectInput::pInstance->KeyCheck(&m_Key[KEY_D], DIK_D);
	switch (m_Directon)
	{
	case Player::UP:
		m_Pos.y -= MOVESPEED;
		break;
	case Player::DOWN:
		m_Pos.y += MOVESPEED;
		break;
	case Player::RIGHT:
		m_Pos.x += MOVESPEED;
		break;
	case Player::LEFT:
		m_Pos.x -= MOVESPEED;
		break;
	default:
		break;
	}
	
	if (m_Key[KEY_W] == KEY_ON)
	{
		m_Directon = UP;//����W�������ꂽ���Ɍ���
	}
	else if (m_Key[KEY_S] == KEY_ON)
	{
		m_Directon = DOWN;//����S�������ꂽ�牺�Ɍ���
	}
	if (m_Key[KEY_A] == KEY_ON)
	{
		m_Directon = LEFT;//����A�������ꂽ�獶�Ɍ���
	}
	else if (m_Key[KEY_D] == KEY_ON)
	{
		m_Directon = RIGHT;	//����D�������ꂽ��E�Ɍ���
	}
	m_Collision->SetPosition(m_Pos);
}



