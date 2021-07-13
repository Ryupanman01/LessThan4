#include "Title.h"
#include "SceneMgr.h"
#include "DxLib.h"
#include "Input.h"

static int mImageHandle;	//�^�C�g���摜
static int mImagecursor;	//�J�[�\���摜
static int MenuNumber = 0;	//���j���[�J�[�\���Ǘ��p�ϐ�

//������
void Menu_Initialize() {
	mImageHandle = LoadGraph("images/Title.png");
	mImagecursor = LoadGraph("images/cursol.png");

	//BGM
	PlayMusic("sounds/Help.mp3", DX_PLAYTYPE_LOOP);
}

//�I������
void Menu_Finalize() {
	DeleteGraph(mImageHandle);
	DeleteGraph(mImagecursor);

	//BGM
}

//�X�V
void Menu_Update() {
	if (iKeyFlg & PAD_INPUT_DOWN) {
		PlaySound("sounds/Cursor.mp3", DX_PLAYTYPE_BACK);
		if (++MenuNumber > 2) MenuNumber = 0;
	}
	if (iKeyFlg & PAD_INPUT_UP) {
		PlaySound("sounds/Cursor.mp3", DX_PLAYTYPE_BACK);
		if (--MenuNumber < 0) MenuNumber = 2;
	}
	if (iKeyFlg == PAD_INPUT_10 || iKeyFlg == PAD_INPUT_1) { //Z�L�[��������Ă�����
		PlaySound("sounds/Put.mp3", DX_PLAYTYPE_BACK);
		switch (MenuNumber) { //�V�[���ɂ���ď����𕪊�
		case 0: //���݂̉�ʂ����j���[�Ȃ�
			SceneMgr_ChangeScene(eScene_Mode); //�V�[�����Q�[����ʂɕύX
			break;
		case 1:
			SceneMgr_ChangeScene(eScene_Help); //�V�[�����Q�[����ʂɕύX
			break;
		case 2:
			SceneMgr_ChangeScene(eScene_End); //�V�[�����Q�[����ʂɕύX
			break;
		}
	}
}

//�`��
void Menu_Draw() {
	DrawGraph(0, 0, mImageHandle, FALSE);

	//���j���[�J�[�\��
	DrawRotaGraph(130, 175 + MenuNumber * 100, 0.1f, 0, mImagecursor, TRUE);
}