//
//  FrozenSpel.cpp
//  TowerDefense
//
//  Created by 康恩婷 on 2022/5/28.
//

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
FrozenSpel::FrozenSpel(float x, float y) :
    Army("play/ice.png", x,y, 20, 0, 0, 0, 3, 0) {
    // Move center downward, since Awe the army head is slightly biased upward.
    Anchor.y += 8.0f / GetBitmapHeight();
}
void FrozenSpel::Update(float time){
    PlayScene* scene = getPlayScene();
    //int x = static_cast<int>(floor(Position.x / PlayScene::BlockSize));
    //int y = static_cast<int>(floor(Position.y / PlayScene::BlockSize));
    if ( isPreview ) return ;
    Engine::Point size = Engine::Point(PlayScene :: BlockSize * 3 , PlayScene :: BlockSize * 3);
    Engine::Point temp = Engine::Point(this->Position.x - PlayScene::BlockSize ,this->Position.y- PlayScene::BlockSize);
    timeTicks += time ;
    if ( timeTicks >= timeSpan ){
        for ( auto & it : scene-> DefenseGroup->GetObjects( ) ){
            Defense* defense = dynamic_cast <Defense*> (it) ;
            if ( Engine::Collider::IsPointInRect(it->Position,temp,size))
                defense->Enabled = true ;
        }
        scene-> ArmyGroup-> RemoveObject(objectIterator) ;
    }else{
        for ( auto & it : scene-> DefenseGroup->GetObjects( ) ){
            Defense* defense = dynamic_cast <Defense*> (it) ;
            if ( Engine::Collider::IsPointInRect(it->Position,temp,size))
                defense->Enabled =false ;
        }
    }
    //for( auto& it : scene->DefenseGroup->GetObjects()){
        
        getPlayScene()->EffectGroup->AddNewObject(new Snoweffect(Position.x - PlayScene::BlockSize, Position.y - PlayScene::BlockSize));
        getPlayScene()->EffectGroup->AddNewObject(new Snoweffect(Position.x - PlayScene:: BlockSize, Position.y));
        getPlayScene()->EffectGroup->AddNewObject(new Snoweffect(Position.x - PlayScene:: BlockSize, Position.y + PlayScene::BlockSize));
        getPlayScene()->EffectGroup->AddNewObject(new Snoweffect(Position.x, Position.y - PlayScene::BlockSize));
        getPlayScene()->EffectGroup->AddNewObject(new Snoweffect(Position.x, Position.y + PlayScene::BlockSize));
        getPlayScene()->EffectGroup->AddNewObject(new Snoweffect(Position.x + PlayScene:: BlockSize, Position.y - PlayScene::BlockSize));
        getPlayScene()->EffectGroup->AddNewObject(new Snoweffect(Position.x + PlayScene:: BlockSize, Position.y));
        getPlayScene()->EffectGroup->AddNewObject(new Snoweffect(Position.x + PlayScene:: BlockSize, Position.y + PlayScene::BlockSize));
    //}
}
void FrozenSpel:: CreateBullet(Engine::Point pt){}
