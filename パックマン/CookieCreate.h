#ifndef COOKIECREATE_H
#define COOKIECREATE_H

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

#define COOKIE_WHIDE 26
#define COOKIE_HEIGHT 29
#define COOKIE_W 10
#define COOKIE_H 10
#define COOKIE_TU 0.1875
#define COOKIE_TV 0.1875

class Cookie {
public:
	Cookie();
	~Cookie();
	void CookieDateLoad();
	void Draw();
	int* GetCookie()
	{
		return &m_Cookie;
	}
private:
	int m_Cookie;
	int** m_CookieDate;
};

#endif 
