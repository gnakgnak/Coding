//
//  Snoweffect.hpp
//  TowerDefense
//
//  Created by 康恩婷 on 2022/5/31.
//

#ifndef Snoweffect_hpp
#define Snoweffect_hpp

#include <stdio.h>

#include "FrozenSpel.hpp"
class Snoweffect: public Army{
public:
    Snoweffect(float x, float y);
//    bool Visible = false;
    float timeSpan = 2;
    float timeTicks = 0;
    void Update(float deltaTime)override;
    void CreateBullet(Engine::Point pt) override;

};


#endif /* Snoweffect_hpp */
