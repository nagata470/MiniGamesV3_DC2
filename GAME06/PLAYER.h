#pragma once
#include"GAME_OBJECT.h"
#include"../../libOne/inc/VECTOR2.h"
#include "../../libOne/inc/COLOR.h"
namespace GAME06 
{
	class PLAYER :
		public GAME_OBJECT
	{
	public:
		struct DATA {
			int img = 0;
			int type1 = 0;
			int type2 = 0;
			VECTOR2 pos;
			float angle = 0.0f;
			float scale = 0.0f;
			float advSpeed = 0.0f;
			float limmitH = 0.0f;
			//launchVec
			/*VECTOR2 launchVec;
			float triggerErapsedTime;
			float triggerInterval;*/
		};
	private:
		DATA Player;
	public:
		int& img() { return Player.img; }
		int& type1() { return Player.type1; }
		int& type2() { return Player.type2; }
	public:
		PLAYER(class GAME* game):GAME_OBJECT(game){}
		~PLAYER(){}
		void create();
		void init();
		void update();
		void draw();
	};
}