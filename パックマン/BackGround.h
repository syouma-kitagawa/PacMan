#ifndef BACKGROUND_H
#define BACKGROUND_H
#include "SceneObject.h"

#define BACKGROUND_W 560
#define BACKGROUND_H 620


class BackGround : public SceneObject{
public:
	BackGround();
	~BackGround();
	void Draw();
	int* GetBackGroundTexture()
	{
		return&m_BackGroundTexture;
	}
private:
	int m_BackGroundTexture;
};

#endif // !BACKGROUND_H
