#include "Start.h"
#include "DirectGraphics.h"


Start::Start()
{
}


Start::~Start()
{
}
void Start::Draw()
{
	CUSTOMVERTEX  StartVertex[4]
	{
		{ 0,0, 1.f, 1.f, 0xFFFFFFFF, 0.f, 0.f },
		{ TEXTURESTART_W,0, 1.f, 1.f, 0xFFFFFFFF, 1.f, 0.f },
		{ TEXTURESTART_W,TEXTURESTART_H, 1.f, 1.f, 0xFFFFFFFF, 1.f, 1.f },
		{ 0,TEXTURESTART_H, 1.f, 1.f, 0xFFFFFFFF, 0.f, 1.f }
	};
	DirectGraphics::GetpInstance()->Render(&m_StartTexture, StartVertex);
}