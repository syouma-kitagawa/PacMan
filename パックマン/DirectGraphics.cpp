#include "DirectGraphics.h"
#include "Player.h"
#include <stdio.h>

DirectGraphics* DirectGraphics::pInstance;

void DirectGraphics::CreateInstance(HWND hWnd)
{
	pInstance = new DirectGraphics(hWnd);
}
//2D�O���t�B�b�N�X����
DirectGraphics::DirectGraphics(HWND hWnd)
{
	// DirectX�I�u�W�F�N�g����
	if (FAILED(m_pDirect3D = Direct3DCreate9(D3D_SDK_VERSION)))
	{
		MessageBox(0, "DirectX�I�u�W�F�N�g�̐����Ɏ��s���܂���", NULL, MB_OK);
	}
	D3DDISPLAYMODE		D3DdisplayMode;
	// DisplayMode�̎擾
	if (FAILED(m_pDirect3D->GetAdapterDisplayMode(
		D3DADAPTER_DEFAULT,
		&D3DdisplayMode)))
	{
		MessageBox(0, "DisplayMode�̎擾�Ɏ��s���܂���", NULL, MB_OK);
	}
	// DirectX�̃f�o�C�X�𐶐�����ۂɕK�v�ȏ���p��
	D3DPRESENT_PARAMETERS d3dpp;
	ZeroMemory(&d3dpp, sizeof(D3DPRESENT_PARAMETERS));

	d3dpp.BackBufferFormat = D3DdisplayMode.Format;
	d3dpp.BackBufferCount = 1;
	d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
	d3dpp.Windowed = TRUE;

	// DirectX�̃f�o�C�X����
	if (FAILED(m_pDirect3D->CreateDevice(
		D3DADAPTER_DEFAULT,
		D3DDEVTYPE_HAL,
		hWnd,
		D3DCREATE_HARDWARE_VERTEXPROCESSING,
		&d3dpp,
		&m_pDirect3DDevice)))
	{
		MessageBox(0, "DirectX�̃f�o�C�X�����Ɏ��s���܂���", NULL, MB_OK);
	}
	//�`��̏�����
	RenderInitialization();
}

DirectGraphics::~DirectGraphics()
{
	m_pDirect3D->Release();			// DirectX�I�u�W�F�N�g�̉��
	m_pDirect3DDevice->Release();	// DirectX�̃f�o�C�X�̉��
	m_pDirect3D = NULL;
	m_pDirect3DDevice = NULL;
}

//�`��̏������֐�
void DirectGraphics::RenderInitialization()
{
	// �`��̐ݒ�
	m_pDirect3DDevice->SetRenderState(D3DRS_ALPHABLENDENABLE, true);
	m_pDirect3DDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);  //SRC�̐ݒ�
	m_pDirect3DDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);
	m_pDirect3DDevice->SetRenderState(D3DRS_DIFFUSEMATERIALSOURCE, D3DMCS_COLOR1);

	m_pDirect3DDevice->SetTextureStageState(0, D3DTSS_COLORARG1, D3DTA_TEXTURE);
	m_pDirect3DDevice->SetTextureStageState(0, D3DTSS_COLORARG2, D3DTA_DIFFUSE);

	m_pDirect3DDevice->SetTextureStageState(0, D3DTSS_COLOROP, D3DTOP_MODULATE);

	m_pDirect3DDevice->SetTextureStageState(0, D3DTSS_ALPHAARG1, D3DTA_TEXTURE);
	m_pDirect3DDevice->SetTextureStageState(0, D3DTSS_ALPHAARG2, D3DTA_DIFFUSE);

	m_pDirect3DDevice->SetTextureStageState(0, D3DTSS_ALPHAOP, D3DTOP_MODULATE);
}
//�`��J�n�֐�
void DirectGraphics::StartRender()
{
	// ���_���̎w��
	m_pDirect3DDevice->SetFVF(D3DFVF_CUSTOMVERTEX);

	// ��ʂ̏���
	m_pDirect3DDevice->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(0x00, 0x00, 0x00), 1.0, 0);
	// �`����J�n%
	m_pDirect3DDevice->BeginScene();
}
//�V�[���ɉ摜���Z�b�g����֐�
void DirectGraphics::Render(int* textureid, CUSTOMVERTEX vertex[])
{
	// �e�N�X�`�����X�e�[�W�Ɋ��蓖�Ă�
	m_pDirect3DDevice->SetTexture(0, m_pTexture[*textureid]);
	// �`��
	m_pDirect3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, vertex, sizeof(CUSTOMVERTEX));
}
//�`��I���֐�
void DirectGraphics::EndRender()
{
	// �`����I��
	m_pDirect3DDevice->EndScene();
	// ��ʂɕ\��
	m_pDirect3DDevice->Present(NULL, NULL, NULL, NULL);
}

//�摜�ǂݍ��݊֐�
void DirectGraphics::InitGraphics(char* fileps,int* Texture)
{
	LPDIRECT3DTEXTURE9 tmp = NULL;
	//�摜�̓ǂݍ���
	D3DXCreateTextureFromFile(
		m_pDirect3DDevice,
		fileps,
		&tmp);
	*Texture = m_pTexture.size();
	m_pTexture.push_back(tmp);
}
//�摜���ߓǂݍ��݊֐�
void DirectGraphics::InitGraphicsPermeation(char*fileps, int* Texture)
{
	LPDIRECT3DTEXTURE9 tmp = NULL;
	D3DXCreateTextureFromFileEx(
		m_pDirect3DDevice,
		fileps,              // �t�@�C����
		0,
		0,
		0,
		0,
		D3DFMT_A1R5G5B5,                // �F�������\��
		D3DPOOL_MANAGED,
		D3DX_FILTER_LINEAR,
		D3DX_FILTER_LINEAR,
		D3DCOLOR_ARGB(255, 0, 255, 0),  //�΂𓧉�
		NULL,
		NULL,
		&tmp);
		*Texture = m_pTexture.size();
	    m_pTexture.push_back(tmp);// �e�N�X�`����
}
void DirectGraphics::Direction_Up(CUSTOMVERTEX Tmp[])
{
	float TmpTu;
	float TmpTv;
	TmpTu = Tmp[0].tu;
	TmpTv = Tmp[0].tv;
	Tmp[0].tu = Tmp[3].tu;
	Tmp[0].tv = Tmp[3].tv;
	Tmp[3].tu = Tmp[2].tu;
	Tmp[3].tv = Tmp[2].tv;
	Tmp[2].tu = Tmp[1].tu;
	Tmp[2].tv = Tmp[1].tv;
	Tmp[1].tu = TmpTu;
	Tmp[1].tv = TmpTv;
}
void DirectGraphics::Direction_Down(CUSTOMVERTEX Tmp[])
{
	float TmpTu;
	float TmpTv;
	TmpTu = Tmp[0].tu;
	TmpTv = Tmp[0].tv;
	Tmp[0].tu = Tmp[1].tu;
	Tmp[0].tv = Tmp[1].tv;
	Tmp[1].tu = Tmp[2].tu;
	Tmp[1].tv = Tmp[2].tv;
	Tmp[2].tu = Tmp[3].tu;
	Tmp[2].tv = Tmp[3].tv;
	Tmp[3].tu = TmpTu;
	Tmp[3].tv = TmpTv;
}
void DirectGraphics::Direction_Right(CUSTOMVERTEX Tmp[])
{
	float TmpTu;
	TmpTu = Tmp[0].tu;
	Tmp[0].tu = Tmp[1].tu;
	Tmp[1].tu = TmpTu;
	TmpTu = Tmp[3].tu;
	Tmp[3].tu = Tmp[2].tu;
	Tmp[2].tu = TmpTu;
}
void DirectGraphics::Direction_Left(CUSTOMVERTEX Tmp[])
{
	float TmpTv;
	TmpTv = Tmp[1].tv;
	Tmp[1].tu = Tmp[0].tu;
	Tmp[0].tu = TmpTv;
	TmpTv = Tmp[2].tv;
	Tmp[2].tu = Tmp[3].tu;
	Tmp[3].tu = TmpTv;
}
