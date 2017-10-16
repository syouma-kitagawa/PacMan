#include "Player.h"
#include "DirectGraphics.h"
#include "Game.h"
#include "DirectInput.h"

Player::Player()
{
	m_Pos.x = INNTIAL_POSX;
	m_Pos.y = INNTIAL_POSY;

}
Player::~Player()
{

}

void Player::SetUp()
{
	CUSTOMVERTEX DrawPacMan[4];
	static CUSTOMVERTEX  PacManVertex[4]
	{
		{ -PACMAN_W / 2, -PACMAN_H / 2, 1.f, 1.f, 0xFFFFFFFF, 0.f, 0.f },
		{ PACMAN_W / 2, -PACMAN_H / 2, 1.f, 1.f, 0xFFFFFFFF, 1.f, 0.f },
		{ PACMAN_W / 2,  PACMAN_H / 2, 1.f, 1.f, 0xFFFFFFFF, 1.f, 1.f },
		{ -PACMAN_W / 2, PACMAN_H / 2, 1.f, 1.f, 0xFFFFFFFF, 0.f, 1.f }
	};
	//Ç‡ÇµWÇ™âüÇ≥ÇÍÇΩÇÁè„Ç…å¸Ç≠
	if (m_Key[KEY_W] == KEY_ON)
	{
		CUSTOMVERTEX TmpPacManVertex[4]
		{
			{ -PACMAN_W / 2, -PACMAN_H / 2, 1.f, 1.f, 0xFFFFFFFF, -1.f, 0.f },
			{ PACMAN_W / 2, -PACMAN_H / 2, 1.f, 1.f, 0xFFFFFFFF, -1.f, 1.f },
			{ PACMAN_W / 2,  PACMAN_H / 2, 1.f, 1.f, 0xFFFFFFFF, 0.f, 1.f },
			{ -PACMAN_W / 2, PACMAN_H / 2, 1.f, 1.f, 0xFFFFFFFF, 0.f, 0.f }
		};
		for (int i = 0; i < 4; i++)
		{
			PacManVertex[i] = TmpPacManVertex[i];
		}
	}
	//Ç‡ÇµAÇ™âüÇ≥ÇÍÇΩÇÁç∂Ç…å¸Ç≠
	if (m_Key[KEY_A] == KEY_ON)
	{
		CUSTOMVERTEX TmpPacManVertex[4]
		{
			{ -PACMAN_W / 2, -PACMAN_H / 2, 1.f, 1.f, 0xFFFFFFFF, 0.f, 0.f },
			{ PACMAN_W / 2, -PACMAN_H / 2, 1.f, 1.f, 0xFFFFFFFF, 1.f, 0.f },
			{ PACMAN_W / 2,  PACMAN_H / 2, 1.f, 1.f, 0xFFFFFFFF, 1.f, 1.f },
			{ -PACMAN_W / 2, PACMAN_H / 2, 1.f, 1.f, 0xFFFFFFFF, 0.f, 1.f }
		};
		for (int i = 0; i < 4; i++)
		{
			PacManVertex[i] = TmpPacManVertex[i];
		}
	}
	//Ç‡ÇµSÇ™âüÇ≥ÇÍÇΩÇÁâ∫Ç…å¸Ç≠
	if (m_Key[KEY_S] == KEY_ON)
	{
		CUSTOMVERTEX TmpPacManVertex[4]
		{
			{ -PACMAN_W / 2, -PACMAN_H / 2, 1.f, 1.f, 0xFFFFFFFF, 1.f, 0.f },
			{ PACMAN_W / 2, -PACMAN_H / 2, 1.f, 1.f, 0xFFFFFFFF, 1.f, -1.f },
			{ PACMAN_W / 2,  PACMAN_H / 2, 1.f, 1.f, 0xFFFFFFFF, 0.f, -1.f },
			{ -PACMAN_W / 2, PACMAN_H / 2, 1.f, 1.f, 0xFFFFFFFF, 0.f, 0.f }
		};
		for (int i = 0; i < 4; i++)
		{
			PacManVertex[i] = TmpPacManVertex[i];
		}
	}
	//Ç‡ÇµDÇ™âüÇ≥ÇÍÇΩÇÁâEÇ…å¸Ç≠
	if (m_Key[KEY_D] == KEY_ON)
	{
		CUSTOMVERTEX TmpPacManVertex[4]
		{
			{ -PACMAN_W / 2, -PACMAN_H / 2, 1.f, 1.f, 0xFFFFFFFF, 0.f, 0.f },
			{ PACMAN_W / 2, -PACMAN_H / 2, 1.f, 1.f, 0xFFFFFFFF, -1.f, 0.f },
			{ PACMAN_W / 2,  PACMAN_H / 2, 1.f, 1.f, 0xFFFFFFFF, -1.f, 1.f },
			{ -PACMAN_W / 2, PACMAN_H / 2, 1.f, 1.f, 0xFFFFFFFF, 0.f, 1.f }
		};
		for (int i = 0; i < 4; i++)
		{
			PacManVertex[i] = TmpPacManVertex[i];
		}
	}
	//à íuÇ∆í∏ì_èÓïÒÇë„ì¸
	for (int i = 0; i < 4; i++)
	{
		DrawPacMan[i] = PacManVertex[i];
		DrawPacMan[i].x += m_Pos.x;
		DrawPacMan[i].y += m_Pos.y;
		DrawPacMan[i].tu = PacManVertex[i].tu;
	}
	static int Fcount = 0;
	if (Fcount <= 5 ||
		Fcount >= 21 && Fcount <= 25 ||
		Fcount >= 36 && Fcount <= 40 ||
		Fcount >= 51 && Fcount <= 55)
	{
		DirectGraphics::pInstance->Render(&m_PlayerTextureOne, DrawPacMan);
	}
	if (Fcount >= 6 && Fcount <= 15 ||
		Fcount >= 26 && Fcount <= 30 ||
		Fcount >= 41 && Fcount <= 45 ||
		Fcount >= 56 && Fcount <= 60)
	{
		DirectGraphics::pInstance->Render(&m_PlayerTextureTwo, DrawPacMan);
	}
	if (Fcount >= 16 && Fcount <= 20 ||
		Fcount >= 31 && Fcount <= 35 || 
		Fcount >= 46 && Fcount <= 50)
	{
		DirectGraphics::pInstance->Render(&m_PlayerTextureThree, DrawPacMan);
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
	if (m_Key[KEY_W] == KEY_ON)
	{
		m_Pos.y -= MOVESPEED;
	}
	if (m_Key[KEY_A] == KEY_ON)
	{
		m_Pos.x -= MOVESPEED;
	}
	if (m_Key[KEY_S] == KEY_ON)
	{
		m_Pos.y += MOVESPEED;
	}
	if (m_Key[KEY_D] == KEY_ON)
	{
		m_Pos.x += MOVESPEED;
	}
}


void Player::Draw()
{
	Player::SetUp();
}
