#include "Title.h"
#include "SceneMgr.h"
#include "DxLib.h"
#include "Input.h"

static int mImageHandle;	//タイトル画像
static int mImagecursor;	//カーソル画像
static int MenuNumber = 0;	//メニューカーソル管理用変数

//初期化
void Menu_Initialize() {
	mImageHandle = LoadGraph("images/Title.png");
	mImagecursor = LoadGraph("images/cursol.png");

	//BGM
	PlayMusic("sounds/Help.mp3", DX_PLAYTYPE_LOOP);
}

//終了処理
void Menu_Finalize() {
	DeleteGraph(mImageHandle);
	DeleteGraph(mImagecursor);

	//BGM
}

//更新
void Menu_Update() {
	if (iKeyFlg & PAD_INPUT_DOWN) {
		PlaySound("sounds/Cursor.mp3", DX_PLAYTYPE_BACK);
		if (++MenuNumber > 2) MenuNumber = 0;
	}
	if (iKeyFlg & PAD_INPUT_UP) {
		PlaySound("sounds/Cursor.mp3", DX_PLAYTYPE_BACK);
		if (--MenuNumber < 0) MenuNumber = 2;
	}
	if (iKeyFlg == PAD_INPUT_10 || iKeyFlg == PAD_INPUT_1) { //Zキーが押されていたら
		PlaySound("sounds/Put.mp3", DX_PLAYTYPE_BACK);
		switch (MenuNumber) { //シーンによって処理を分岐
		case 0: //現在の画面がメニューなら
			SceneMgr_ChangeScene(eScene_Mode); //シーンをゲーム画面に変更
			break;
		case 1:
			SceneMgr_ChangeScene(eScene_Help); //シーンをゲーム画面に変更
			break;
		case 2:
			SceneMgr_ChangeScene(eScene_End); //シーンをゲーム画面に変更
			break;
		}
	}
}

//描画
void Menu_Draw() {
	DrawGraph(0, 0, mImageHandle, FALSE);

	//メニューカーソル
	DrawRotaGraph(130, 175 + MenuNumber * 100, 0.1f, 0, mImagecursor, TRUE);
}