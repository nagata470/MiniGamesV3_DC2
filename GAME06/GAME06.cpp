#include "../../libOne/inc/input.h"
#include "../MAIN//MAIN.h"
#include "TITLE.h"
#include "STAGE.h"
#include "RANK_C.h"
#include "RANK_B.h"
#include "RANK_A.h"
#include "RANK_S.h"
#include "JUDGE_LIST.h"
#include "CONTAINER.h"
#include "PLAYER.h"
#include "TARGET.h"
#include "GAME06.h"
//仕様
//タイトル「スナイパー」
//ステージ
//　プレイヤー　「上下の移動」と「弾の発射」弾は一発発射したらその弾が消えるまで発射不可能にする　発射された弾は的に当たるか画面外に出たら消す
//　敵(的) 　「上下の移動」と「速度の変化」
//　制限時間　30秒
//リザルト　的に当たった数に応じてC〜Sランクと記録を表示する　C〜Sランクの判定表を左上に表示する

namespace GAME06
{
	int GAME::create()
	{
		Container = new CONTAINER;
		Scenes[TITLE_ID] = new TITLE(this);
		Scenes[STAGE_ID] = new STAGE(this);
		Scenes[RANK_C_ID] = new RANK_C(this);
		Scenes[RANK_B_ID] = new RANK_B(this);
		Scenes[RANK_A_ID] = new RANK_A(this);
		Scenes[RANK_S_ID] = new RANK_S(this);
		JudgeList = new JUDGE_LIST(this);
		CurSceneId = TITLE_ID;
		Player = new PLAYER(this);
		Target = new TARGET(this);
		Container->load();
		Scenes[TITLE_ID]->create();
		Scenes[STAGE_ID]->create();
		Scenes[RANK_C_ID]->create();
		Scenes[RANK_B_ID]->create();
		Scenes[RANK_A_ID]->create();
		Scenes[RANK_S_ID]->create();
		JudgeList->create();
		Player->create();
		Target->create();
		return 0;
	}

	void GAME::destroy()
	{
		delete Target;
		delete Player;
		delete JudgeList;
		for (int i = 0; i < TOTAL_SCENES_ID; ++i) {
			delete Scenes[i];
		}
		delete Container;
	}

	void GAME::changeScene(SCENE_ID nextSceneId) {
		CurSceneId = nextSceneId;
	}

	void GAME::setRecode(int recode) {
		Recode = recode;
	}

	void GAME::proc()
	{
		Scenes[CurSceneId]->proc();
		if (isTrigger(KEY_ENTER)) {
			main()->backToMenu();
		}
	}
}
