#include "DxLib.h"
#include "GameScene.h"
#include "GameData.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPSTR lpCmdLine, int nCmdShow)
{
	//------------------------------------------------------
	// �E�C���h�E�ݒ��DX���C�u�����̏�����
	//------------------------------------------------------
	// Windows���[�h�ɂ���
	ChangeWindowMode(TRUE);
	// ��ʃT�C�Y�̐ݒ�
	SetGraphMode(Data::kDisplayWidth, Data::kDisplayHeight, Data::kColorData);

	// DX���C�u����������
	if (DxLib_Init() == -1)
	{
		//�������Ɏ��s
		return -1;
	}
	// �_�u���o�b�t�@���[�h
	SetDrawScreen(DX_SCREEN_BACK);

	GameScene game;

	//------------------------------------------------------
	// �Q�[������
	//------------------------------------------------------
	// ���C�����[�v����
	while (ProcessMessage() == 0)
	{
		//����ʏ���
		ClearDrawScreen();

		game.Update();
		game.Draw();

		//����ʂ�\��ʂ����ւ���
		ScreenFlip();

		//ESCAPE����������I������
		if (CheckHitKey(KEY_INPUT_ESCAPE))
		{
			break;
		}
	}

	//------------------------------------------------------
	// DX���C�u�����I���ƃv���O�����I��
	//------------------------------------------------------
	DxLib_End();
	return 0;
}