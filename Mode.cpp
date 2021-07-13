#include "DxLib.h"
#include "Mode.h"
#include "Input.h"
#include "SceneMgr.h"

//�摜
static int mImageMode;
static int mImageCursor;

static int MenuNumber = 0;

//������
void Mode_Initialize() {
	mImageMode = LoadGraph("images/Mode.png");
	mImageCursor = LoadGraph("images/cursol.png");
}

//�I������
void Mode_Finalize() {
	DeleteGraph(mImageMode);
	DeleteGraph(mImageCursor);
}

//�X�V
void Mode_Update() {
	if (iKeyFlg & PAD_INPUT_DOWN) {
		PlaySound("sounds/Cursor.mp3", DX_PLAYTYPE_BACK);
		if (++MenuNumber > 1) MenuNumber = 0;
	}
	if (iKeyFlg & PAD_INPUT_UP) {
		PlaySound("sounds/Cursor.mp3", DX_PLAYTYPE_BACK);
		if (--MenuNumber < 0) MenuNumber = 1;
	}
	if (iKeyFlg == PAD_INPUT_10 || iKeyFlg == PAD_INPUT_1) { //Z�L�[��������Ă�����
		PlaySound("sounds/Put.mp3", DX_PLAYTYPE_BACK);
		switch (MenuNumber) { //�V�[���ɂ���ď����𕪊�
		case 0: //���݂̉�ʂ����j���[�Ȃ�
			SceneMgr_ChangeScene(eScene_Stage); //Nomal�̎�
			break;
		case 1:
			SceneMgr_ChangeScene(eScene_Stage1); //LessThan�̎�
			break;
		}
	}
	if (iKeyFlg == PAD_INPUT_B || iKeyFlg == PAD_INPUT_9/*CheckHitKey(KEY_INPUT_ESCAPE) != 0*/) {//Esc�L�[��������Ă�����
		PlaySound("sounds/Back.mp3", DX_PLAYTYPE_BACK);
		SceneMgr_ChangeScene(eScene_Title);//�V�[�������j���[�ɕύX
	}
}

//�`��
void Mode_Draw() {
	DrawGraph(0, 0, mImageMode, false);
	DrawRotaGraph(125, 200 + MenuNumber * 78, 0.1f, 0, mImageCursor, TRUE);
}