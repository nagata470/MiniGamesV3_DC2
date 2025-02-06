#pragma once
#include"SCENE.h"
#include"../../libOne/inc/COLOR.h"
#include"../../libOne/inc/VECTOR2.h"
namespace GAME06 
{
	class TITLE :
		public SCENE
	{
	public:
		struct DATA {
			COLOR backScreenColor;
			COLOR textColor1;
			float textSize1 = 0.0f;
			VECTOR2 textPos1;
			const char* str1 = nullptr;
			COLOR textColor2;
			float textSize2 = 0.0f;
			VECTOR2 textPos2;
			const char* str2 = nullptr;
		};
	private:
		DATA Title;
	private:
		float Size = 40;
	public:
		TITLE(class GAME* game):SCENE(game){}
		~TITLE(){}
		void create();
		void draw();
		void nextScene();
	};
}