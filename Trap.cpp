//
//  Trap.cpp
//  TowerDefense
//
//  Created by 康恩婷 on 2022/5/28.
//
#include "AudioHelper.hpp"
#include "Army.hpp"
#include "GameEngine.hpp"
#include "Group.hpp"
#include "IObject.hpp"
#include "IScene.hpp"
#include "Point.hpp"
#include "Defense.hpp"
#include "Trap.hpp"
#include <allegro5/base.h>
#include <random>
#include <string>

#include "DirtyEffect.hpp"
#include "CannonBullet.hpp"
#include "Group.hpp"
#include "PlayScene.hpp"
#include "Collider.hpp"
#include "Point.hpp"
#include "LowerCannon.hpp"
class Defense;
Trap::Trap(float x, float y) :
    Defense("play/bomb.png", x, y, 20, 1, 50, 4, 100) {
    // Move center downward, since we the turret head is slightly biased upward.
    Anchor.y += 8.0f / GetBitmapHeight();
}
void Trap:: Update ( float deltaTime ) {
    Sprite :: Update ( deltaTime ) ;
    PlayScene * scene = getPlayScene ( ) ;
    if ( ! Enabled )
       return ;
    int ey;
    for ( auto & it : scene-> ArmyGroup-> GetObjects ( ) ) {
        ey = static_cast < int > ( floor ( it-> Position.y / PlayScene :: BlockSize));
        if ( InShootingRange( it-> Position ) ) {
            Target = dynamic_cast < Army* > ( it ) ;
            Target->Hit( INFINITY ) ;
            Hit ( INFINITY ) ;
            break ;
        }
    }
}
                 
void Trap::CreateBullet(Engine::Point pt){ }

