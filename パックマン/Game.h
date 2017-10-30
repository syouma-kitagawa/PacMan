#ifndef GAME_H
#define GAME_H

#include "CharObject.h"
#include "DirectInput.h"

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
private:
	KEYSTATE m_Key[KEYMAX] = { KEY_OFF };
};

#endif // !GAME_H



