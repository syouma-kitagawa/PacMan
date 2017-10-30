#ifndef SCENE_H
#define SCENE_H
class BackGround;
class Start;

class Scene {
public:
	Scene();
	~Scene();

	void Draw();
	void StartDraw();
	BackGround* GetBackGround()
	{
		return m_BackGround;
	}
	Start* GetStart()
	{
		return m_Start;
	}
private:
	BackGround* m_BackGround;
	Start* m_Start;

};


#endif // !SCENE_H
