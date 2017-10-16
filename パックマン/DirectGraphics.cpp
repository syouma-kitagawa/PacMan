#include "DirectGraphics.h"
#include "Player.h"
#include <stdio.h>

DirectGraphics* DirectGraphics::pInstance;

void DirectGraphics::CreateInstance(HWND hWnd)
{
	pInstance = new DirectGraphics(hWnd);
}


DirectGraphics::DirectGraphics(HWND hWnd)
{
	// DirectXオブジェクト生成
	m_pDirect3D = Direct3DCreate9(D3D_SDK_VERSION);

	D3DDISPLAYMODE		D3DdisplayMode;
	// DisplayModeの取得
	m_pDirect3D->GetAdapterDisplayMode(
		D3DADAPTER_DEFAULT,
		&D3DdisplayMode);

	// DirectXのデバイスを生成する際に必要な情報を用意
	D3DPRESENT_PARAMETERS d3dpp;
	ZeroMemory(&d3dpp, sizeof(D3DPRESENT_PARAMETERS));

	d3dpp.BackBufferFormat = D3DdisplayMode.Format;
	d3dpp.BackBufferCount = 1;
	d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
	d3dpp.Windowed = TRUE;

	// DirectXのデバイス生成
	m_pDirect3D->CreateDevice(
		D3DADAPTER_DEFAULT,
		D3DDEVTYPE_HAL,
		hWnd,
		D3DCREATE_HARDWARE_VERTEXPROCESSING,
		&d3dpp,
		&m_pDirect3DDevice);
	//描画の初期化
	RenderInitialization();
}

DirectGraphics::~DirectGraphics()
{
	m_pDirect3D->Release();			// DirectXオブジェクトの解放
	m_pDirect3DDevice->Release();	// DirectXのデバイスの解放

	m_pDirect3D = NULL;
	m_pDirect3DDevice = NULL;
}

//描画の初期化関数
void DirectGraphics::RenderInitialization()
{
	// 描画の設定
	m_pDirect3DDevice->SetRenderState(D3DRS_ALPHABLENDENABLE, true);
	m_pDirect3DDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);  //SRCの設定
	m_pDirect3DDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);
	m_pDirect3DDevice->SetRenderState(D3DRS_DIFFUSEMATERIALSOURCE, D3DMCS_COLOR1);

	m_pDirect3DDevice->SetTextureStageState(0, D3DTSS_COLORARG1, D3DTA_TEXTURE);
	m_pDirect3DDevice->SetTextureStageState(0, D3DTSS_COLORARG2, D3DTA_DIFFUSE);

	m_pDirect3DDevice->SetTextureStageState(0, D3DTSS_COLOROP, D3DTOP_MODULATE);

	m_pDirect3DDevice->SetTextureStageState(0, D3DTSS_ALPHAARG1, D3DTA_TEXTURE);
	m_pDirect3DDevice->SetTextureStageState(0, D3DTSS_ALPHAARG2, D3DTA_DIFFUSE);

	m_pDirect3DDevice->SetTextureStageState(0, D3DTSS_ALPHAOP, D3DTOP_MODULATE);
}
//描画開始関数
void DirectGraphics::StartRender()
{
	// 頂点情報の指定
	m_pDirect3DDevice->SetFVF(D3DFVF_CUSTOMVERTEX);

	// 画面の消去
	m_pDirect3DDevice->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(0x00, 0x00, 0x00), 1.0, 0);
	// 描画を開始
	m_pDirect3DDevice->BeginScene();
}
void DirectGraphics::Render(int* textureid, CUSTOMVERTEX vertex[])
{
	// テクスチャをステージに割り当てる
	m_pDirect3DDevice->SetTexture(0, m_pTexture[*textureid]);
	// 描画
	m_pDirect3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, vertex, sizeof(CUSTOMVERTEX));
}
//描画終了関数
void DirectGraphics::EndRender()
{
	// 描画を終了
	m_pDirect3DDevice->EndScene();
	// 画面に表示
	m_pDirect3DDevice->Present(NULL, NULL, NULL, NULL);
}

//画像読み込み関数
void DirectGraphics::InitGraphics(char* fileps,int* Texture)
{
	LPDIRECT3DTEXTURE9 tmp;
	//画像の読み込み
	D3DXCreateTextureFromFile(
		m_pDirect3DDevice,
		fileps,
		&tmp);
	*Texture = m_pTexture.size();
	m_pTexture.push_back(tmp);
}
