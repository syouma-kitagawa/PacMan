#ifndef SCENE_H
#define SCENE_H
class BackGround;

class Scene {
public:
	Scene();
	~Scene();

	void Draw();
	BackGround* GetBackGround()
	{
		return m_BackGround;
	}
	BackGround* m_BackGround;

};


#endif // !SCENE_H
