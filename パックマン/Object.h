#ifndef OBJECT_H
#define OBJECT_H

#include<d3dx9.h>



class ObjectBase {
public:
	ObjectBase() {};
	virtual ~ObjectBase() {};
	virtual void Update() = 0;
	virtual void Draw() = 0;
protected:
	D3DXVECTOR2 m_Pos;
};

#endif // !OBJECT_H
