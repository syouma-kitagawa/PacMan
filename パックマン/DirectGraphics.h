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
	//2D�O���t�B�b�N�X���
	virtual ~DirectGraphics();
	static void CreateInstance(HWND hWnd);
	//�`��̏������֐�
	void RenderInitialization();
	//�`��J�n�֐�
	void StartRender();
	//�V�[���ɉ摜���Z�b�g����֐�
	void Render(int* textureid, CUSTOMVERTEX vertex[]);
	//�`��I���֐�
	void EndRender();
	//2D�摜�ǂݍ��݊֐�
	//�������t�@�C���p�X
	//�������摜��u���ꏊ
	void InitGraphics(char* fileps,int* Texture);
	void InitGraphicsPermeation(char* fileps, int* Texture);
	//�摜����ɕ����]��
	//������Ɍ��������摜��CUSTOMVERTEX
	void Direction_Up(CUSTOMVERTEX Tmp[]);
	//�摜�����ɕ����]��
	//�������Ɍ��������摜��CUSTOMVERTEX
	void Direction_Down(CUSTOMVERTEX Tmp[]);
	//�摜���E�ɕ����]��
	//�����E�Ɍ��������摜��CUSTOMVERTEX
	void Direction_Right(CUSTOMVERTEX Tmp[]);
	//�摜�����ɕ����]��
	//�������Ɍ��������摜��CUSTOMVERTEX
	void Direction_Left(CUSTOMVERTEX Tmp[]);
	static DirectGraphics* GetpInstance() { return pInstance; }
private:
	//2D�O���t�B�b�N�X����
	DirectGraphics(HWND hWnd);
	static DirectGraphics* pInstance;
	LPDIRECT3D9			m_pDirect3D = NULL;		// DirectX�I�u�W�F�N�g�̃|�C���^
	LPDIRECT3DDEVICE9	m_pDirect3DDevice = NULL;	// DirectX�f�o�C�X�̃|�C���^
	std::vector<LPDIRECT3DTEXTURE9> m_pTexture;
};
#endif 
