#include "CookieCreate.h"
#include "DirectGraphics.h"
#include <fstream>
Cookie::Cookie() 
{
	FILE *fp = NULL;
	char FileName[] = "CSV/cookie.csv";

	fopen_s(&fp, "cookie.csv", "r");

	m_CookieDate = new int*[COOKIE_HEIGHT];
	for (int x = 0; x < COOKIE_HEIGHT; x++) {
		m_CookieDate[x] = new int[COOKIE_WHIDE];
	}

	for (int i = 0; i < COOKIE_HEIGHT; i++) {
		for (int j = 0; j < COOKIE_WHIDE; j++) {
			m_CookieDate[i][j] = 0;
			fscanf_s(fp, "%d,", &m_CookieDate[i][j]);
		}
	}
	fclose(fp);
}
Cookie::~Cookie()
{
	for (int x = 0; x < 26; x++) {
		delete[] m_CookieDate[x];
	}
	delete[] m_CookieDate;
}

void Cookie::CookieDateLoad()
{
}
void Cookie::Draw()
{

	static CUSTOMVERTEX  CookieVertex[4]
	{
		{ -COOKIE_W, -COOKIE_H, 1.f, 1.f, 0xFFFFFFFF, 0.f, 0.f },
		{ COOKIE_W, -COOKIE_H, 1.f, 1.f, 0xFFFFFFFF, COOKIE_TU, 0.f },
		{ COOKIE_W,  COOKIE_H, 1.f, 1.f, 0xFFFFFFFF, COOKIE_TU, COOKIE_TV },
		{ -COOKIE_W, COOKIE_H, 1.f, 1.f, 0xFFFFFFFF, 0.f,COOKIE_TV }
	};

	int offset_x = 20;
	int offset_y = 20;
	for (int i = 0; i < COOKIE_HEIGHT; i++) {
		for (int j = 0; j < COOKIE_WHIDE; j++) {
			if (m_CookieDate[i][j] == 1) {
				CUSTOMVERTEX  CookieDraw[4]
				{
					{ COOKIE_W*j*2 + offset_x,+ COOKIE_H*i*2 + offset_y, 1.f, 1.f, 0xFFFFFFFF, 0.1875f, 0.f },
					{ 2*COOKIE_W + COOKIE_W*j*2 + offset_x,COOKIE_H*i*2 + offset_y, 1.f, 1.f, 0xFFFFFFFF, 0.25f, 0.f },
					{ 2*COOKIE_W + COOKIE_W*j*2 + offset_x, 2*COOKIE_H + COOKIE_H*i*2 + offset_y, 1.f, 1.f, 0xFFFFFFFF, 0.25, 0.0625 },
					{ COOKIE_W*j*2 + offset_x, 2*COOKIE_H + COOKIE_H*i*2 + offset_y, 1.f, 1.f, 0xFFFFFFFF, 0.1875f,0.0625 }
				};
				DirectGraphics::GetpInstance()->Render(&m_Cookie, CookieDraw);
			}
		}
	}
}