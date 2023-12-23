//
//  Snoweffect.cpp
//  TowerDefense
//
//  Created by 康恩婷 on 2022/5/31.
//

#include "Snoweffect.hpp"
#include <allegro5/base.h>
#include <allegro5/color.h>
#include <allegro5/allegro_primitives.h>
#include <cmath>
#include <string>

#include "AudioHelper.hpp"
#include "Collider.hpp"
#include "Army.hpp"
#include "Group.hpp"
#include "PlayScene.hpp"
#include "Point.hpp"
#include "BombArmy.hpp"
#include "Defense.hpp"
#include "FrozenSpel.hpp"
#include "Point.hpp"
#include "Snoweffect.hpp"
//Army(std::string img, float x, float y, float radius, float coolDown, float speed, float hp, int id, float shootRadius) :
Snoweffect::Snoweffect(float x, float y) :Army("play/snowflake.png", x,y, 20, 0, 0,0,4, 0){
    // Move center downward, since Awe the army head is slightly biased upward.
    Anchor.y += 8.0f / GetBitmapHeight();
}
void Snoweffect::CreateBullet(Engine::Point pt){}
void Snoweffect::Update(float deltaTime) {
    timeTicks += 10*deltaTime;
    if (timeTicks >= timeSpan) {
        getPlayScene()->EffectGroup->RemoveObject(objectIterator);
        return;
    }
   
}
