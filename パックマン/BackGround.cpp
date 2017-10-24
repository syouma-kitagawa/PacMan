#include "BackGround.h"
#include "DirectGraphics.h"

BackGround::BackGround()
{

}

BackGround::~BackGround()
{

}

void BackGround::Draw()
{
	CUSTOMVERTEX  m_BackGroundVertex[4]
	{
		{ 0,0, 1.f, 1.f, 0xFFFFFFFF, 0.f, 0.f },
		{ BACKGROUND_W,0, 1.f, 1.f, 0xFFFFFFFF, 1.f, 0.f },
		{ BACKGROUND_W,  BACKGROUND_H, 1.f, 1.f, 0xFFFFFFFF, 1.f, 1.f },
		{ 0,  BACKGROUND_H, 1.f, 1.f, 0xFFFFFFFF, 0.f, 1.f }
	};
	DirectGraphics::pInstance->Render(&m_BackGroundTexture, m_BackGroundVertex);
}