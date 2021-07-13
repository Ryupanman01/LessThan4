#include "DxLib.h"
#include "Input.h"
#include "Stage1.h"
#include "SceneMgr.h"

//画像
static int mImageStage;
static int mImageCursor;

//カーソル
static int MenuNumber = 0;

//カーソル位置
static int x = 0;

//初期化
void Stage1_Initialize() {
	mImageStage = LoadGraph("images/Stage.png");
	mImageCursor = LoadGraph("images/cursol.png");
}

//終了処理
void Stage1_Finalize() {
	DeleteGraph(mImageStage);
	DeleteGraph(mImageCursor);
}

//更新
void Stage1_Update() {
	if (iKeyFlg & PAD_INPUT_LEFT) {
		PlaySound("sounds/Cursor.mp3", DX_PLAYTYPE_BACK);
		if (++MenuNumber > 1) MenuNumber = 0;
		if (x == 0) {
			x = 230;
		}
		else {
			x = 0;
		}
	}
	if (iKeyFlg & PAD_INPUT_RIGHT) {
		PlaySound("sounds/Cursor.mp3", DX_PLAYTYPE_BACK);
		if (--MenuNumber < 0) MenuNumber = 1;
		if (x == 230) {
			x = 0;
		}
		else {
			x = 230;
		}
	}
	if (iKeyFlg == PAD_INPUT_10 || iKeyFlg == PAD_INPUT_1) { //Zキーが押されていたら
		PlaySound("sounds/Put.mp3", DX_PLAYTYPE_BACK);
		switch (MenuNumber) { //シーンによって処理を分岐
		case 0: //現在の画面がメニューなら
			SceneMgr_ChangeScene(eScene_Game1); //四角形盤
			break;
		case 1:
			SceneMgr_ChangeScene(eScene_Game3); //ひし形盤
			break;
		}
	}
	if (iKeyFlg == PAD_INPUT_B || iKeyFlg == PAD_INPUT_9/*CheckHitKey(KEY_INPUT_ESCAPE) != 0*/) {//Escキーが押されていたら
		PlaySound("sounds/Back.mp3", DX_PLAYTYPE_BACK);
		SceneMgr_ChangeScene(eScene_Mode);//シーンをメニューに変更
	}
}

//描画
void Stage1_Draw() {
	DrawGraph(0, 0, mImageStage, false);
	DrawRotaGraph(30 + x, 372, 0.1f, 0, mImageCursor, true);
}