#pragma once
#include "SCENE.h"
#include"../../libOne/inc/COLOR.h"
#include"../../libOne/inc/VECTOR2.h"
namespace GAME06
{
    class RANK_B :
        public SCENE
    {
    public:
        struct DATA {
            COLOR backScreenColor;
            float size1 = 0.0f;
            COLOR color1;
            VECTOR2 pos1;
            const char* str1 = nullptr;
            float size2 = 0.0f;
            COLOR color2;
            VECTOR2 pos2;
            const char* str2 = nullptr;
            float size3 = 0.0f;
            COLOR color3;
            VECTOR2 pos3;
        };
    private:
        DATA RankB;
    public:
        RANK_B(class GAME* game) :SCENE(game) {}
        ~RANK_B() {}
        void create();
        void draw();
        void nextScene();
    };
}

