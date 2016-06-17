//
//  Event.hpp
//  C++ Study
//
//  Created by 민석 on 2016. 6. 15..
//  Copyright © 2016년 민석. All rights reserved.
//

#ifndef Event_hpp
#define Event_hpp
#include <iostream>

// Ability : 능력치에 대한 Enum
// STR : Damage
// INT : Skill Damage
// DEX : Rate of hit, avoidance
enum class Ability { STR = 0, INT, DEX };
enum class Action { Attack = 0, Defense, Rest };

#endif /* Event_hpp */
