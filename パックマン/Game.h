#ifndef GAME_H
#define GAME_H

#include "CharObject.h"

class Cookie;
class Player;
class Scene;

class Game : public CharObjectBase{
public:
	Game();
	virtual ~Game();
	virtual void Draw();
	virtual void Update();
	void RunGame();
	//後でプライベートにする
	Cookie* m_pCookie;
	Player* m_pPlayer;
	Scene* m_pScene;
};

#endif // !GAME_H



