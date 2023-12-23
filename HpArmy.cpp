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
#include "HpArmy.hpp"
#include "Defense.hpp"


//Army(std::string img, float x, float y, float radius, float coolDown, float speed, float hp, int id, float shootRadius);
HpArmy::HpArmy(float x, float y) :
    Army("play/HpArmy.png", x, y, 20, 0, 0, 100, 2, 0) {
    // Move center downward, since Awe the army head is slightly biased upward.
    Anchor.y += 8.0f / GetBitmapHeight();
}
void HpArmy:: CreateBullet(Engine::Point pt){}
//void Update(float deltaTime){
//    
//}
