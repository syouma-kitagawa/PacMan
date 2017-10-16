#ifndef GAME_H
#define GAME_H

#include "Player.h"
#include "Object.h"


class Game : public ObjectBase{
public:
	Game();
	~Game();
	virtual void Draw();
	virtual void Update();
	void RunGame();
	//後でプライベートにする
	Player* m_pPlayer;
};

#endif // !GAME_H



