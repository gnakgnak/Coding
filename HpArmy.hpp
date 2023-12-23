//
//  HpArmy.hpp
//  TowerDefense
//
//  Created by 康恩婷 on 2022/5/28.
//

#ifndef HpArmy_hpp
#define HpArmy_hpp

#include "Army.hpp"

class HpArmy: public Army {
public:
    HpArmy(float x, float y);
    void CreateBullet(Engine::Point pt) override;
//    void Update(float deltaTime) override;

};


#endif /* HpArmy_hpp */
