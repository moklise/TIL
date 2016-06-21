//
//  Event.hpp
//  C++ Study
//
//  Created by 민석 on 2016. 6. 15..
//  Copyright © 2016년 민석. All rights reserved.
//

#ifndef Event_hpp
#define Event_hpp

#ifdef _WIN32
#include <Windows.h>
#else// For Mac
#include <unistd.h> 
#endif
#include <iostream>
//
//#include "PlayerManager.hpp"
// Event.hpp에서 include 하면 PlayerManager.hpp 를 두번 Include 하는 문제 발생.
//
enum class Ability { STR = 0, INT, DEX };
enum class Action { Attack = 0, Defense, Skill, Rest, Dead };

typedef struct{
    static void ConsoleDelay();
    static bool isDead(int _HP);
}Event;

#endif /* Event_hpp */

// Ability : 능력치에 대한 Enum
// STR : Damage
// INT : Skill Damage
// DEX : Rate of hit, avoidance