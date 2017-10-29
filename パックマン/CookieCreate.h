#ifndef COOKIECREATE_H
#define COOKIECREATE_H

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <vector>
#include "Collision.h"
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
	void UpDate();
	int* GetCookie()
	{
		return &m_Cookie;
	}

private:
	std::vector<Collision*> m_Collision;
	int m_Cookie;
	int** m_CookieDate;
};

#endif 
