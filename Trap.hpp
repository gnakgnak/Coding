//
//  Trap.hpp
//  TowerDefense
//
//  Created by 康恩婷 on 2022/5/28.
//

#ifndef Trap_hpp
#define Trap_hpp

#include <stdio.h>
#include "Defense.hpp"
class Trap: public Defense {
public:
    Trap(float x, float y);
    void Update(float deltaTime)override;
    void CreateBullet(Engine::Point pt) override;
    
};
#endif /* Trap_hpp */
