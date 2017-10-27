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
		{ TEXTUREBACKGROUND_W,0, 1.f, 1.f, 0xFFFFFFFF, 1.f, 0.f },
		{ TEXTUREBACKGROUND_W,  TEXTUREBACKGROUND_H, 1.f, 1.f, 0xFFFFFFFF, 1.f, 1.f },
		{ 0,TEXTUREBACKGROUND_H, 1.f, 1.f, 0xFFFFFFFF, 0.f, 1.f }
	};
	DirectGraphics::GetpInstance()->Render(&m_BackGroundTexture, m_BackGroundVertex);
}