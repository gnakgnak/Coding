//
//  FrozenSpel.hpp
//  TowerDefense
//
//  Created by 康恩婷 on 2022/5/28.
//

#ifndef FrozenSpel_hpp
#define FrozenSpel_hpp
#include "Army.hpp"
class FrozenSpel: public Army {
public:
    float timeSpan = 2;
    float timeTicks = 0;
    FrozenSpel(float x, float y);
    void CreateBullet(Engine::Point pt) override;
    void Update(float deltaTime) override;
//    void Hit(float damage) override;
    
};



#endif /* FrozenSpel_hpp */
