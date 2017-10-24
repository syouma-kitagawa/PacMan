#ifndef CHAROBJECT_H
#define CHAROBJECT_H

#include<d3dx9.h>



class CharObjectBase {
public:
	CharObjectBase() {};
	virtual ~CharObjectBase() {};
	virtual void Update() = 0;
	virtual void Draw() = 0;
protected:
	D3DXVECTOR2 m_Pos;
};

#endif // !OBJECT_H
