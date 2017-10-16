#ifndef DIRECTINPUT_H
#define DIRECTINPUT_H

#include <dinput.h>

enum KEYSTATE {
	KEY_PUSH,
	KEY_RELEASE,
	KEY_ON,
	KEY_OFF
};

enum KEYKIND
{
	KEY_LEFT,
	KEY_RIGHT,
	KEY_UP,
	KEY_DOWN,
	KEY_A,
	KEY_B,
	KEY_C,
	KEY_D,
	KEY_E,
	KEY_F,
	KEY_G,
	KEY_H,
	KEY_I,
	KEY_J,
	KEY_K,
	KEY_L,
	KEY_M,
	KEY_N,
	KEY_O,
	KEY_P,
	KEY_Q,
	KEY_R,
	KEY_S,
	KEY_T,
	KEY_U,
	KEY_V,
	KEY_W,
	KEY_X,
	KEY_Y,
	KEY_Z,
	KEY_SPACE,
	KEY_ESC,
	KEYMAX
};

class DirectInput {
public:
	DirectInput(HWND hWnd);
	~DirectInput();
	static void CreateDirectInput(HWND hWnd);
	void KeyCheck(KEYSTATE* Key, int DIK);

	static DirectInput* pInstance;

private:
	LPDIRECTINPUT8 m_pDInput = NULL;
	LPDIRECTINPUTDEVICE8 m_pKeyDevice = NULL;

};


#endif 
