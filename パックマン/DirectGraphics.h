#ifndef DIRECTOBJECT_H
#define DIRECTOBJECT_H
#include <d3d9.h>
#include <d3dx9.h>
#include <vector>

#define D3DFVF_CUSTOMVERTEX (D3DFVF_XYZRHW | D3DFVF_DIFFUSE | D3DFVF_TEX1)

struct CUSTOMVERTEX
{
	FLOAT	x, y, z, rhw;
	DWORD	color;
	FLOAT	tu, tv;
};

class DirectGraphics {
public:
	
	//2Dグラフィックス生成
	DirectGraphics(HWND hWnd);
	//2Dグラフィックス解放
	virtual ~DirectGraphics();

	static void CreateInstance(HWND hWnd);
	//描画の初期化関数
	void RenderInitialization();
	//描画開始関数
	void StartRender();
	////シーンに画像をセットする関数
	void Render(int* textureid, CUSTOMVERTEX vertex[]);
	//描画終了関数
	void EndRender();
	//2D画像読み込み関数
	//第一引数ファイルパス
	//第二引数画像を置く場所
	void InitGraphics(char* fileps,int* Texture);

	static DirectGraphics* pInstance;
	
private:
	LPDIRECT3D9			m_pDirect3D = NULL;		// DirectXオブジェクトのポインタ
	LPDIRECT3DDEVICE9	m_pDirect3DDevice = NULL;	// DirectXデバイスのポインタ
	std::vector<LPDIRECT3DTEXTURE9> m_pTexture;
};
#endif 
