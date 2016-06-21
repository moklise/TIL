//
//  Event.cpp
//  C++ Study
//
//  Created by 민석 on 2016. 6. 15..
//  Copyright © 2016년 민석. All rights reserved.
//

#include "Event.hpp"

void Event::ConsoleDelay()
{

#ifdef _WIN32
	Sleep(800);
#else
	usleep(1000 * 800);
#endif

}

bool Event::isDead(int _HP)
{
    if(_HP > 0) return true;
    else        return false;
}