#pragma once
#include "SceneObject.h"

#define TEXTURESTART_W 585
#define TEXTURESTART_H 645

class Start : public SceneObject{
public:
	Start();
	~Start();
	void Draw();
	int* GetStartTexture()
	{
		return&m_StartTexture;
	}
private:
	int m_StartTexture;
};

