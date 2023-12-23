//
//  LowerCannon.hpp
//  TowerDefense
//
//  Created by 康恩婷 on 2022/5/28.
//

#ifndef LowerCannon_hpp
#define LowerCannon_hpp


#include "Defense.hpp"

class LowerCannon: public Defense {
public:
    LowerCannon(float x, float y);
    void CreateBullet(Engine::Point pt) override;
};

#endif /* LowerCannon_hpp */
