//
//  Battle.hpp
//  C++ Study
//
//  Created by 민석 on 2016. 6. 15..
//  Copyright © 2016년 민석. All rights reserved.
//

#ifndef Battle_hpp
#define Battle_hpp
#include <iostream>
#include "PlayerManager.hpp"

class Battle{
    PlayerManager player_1;
    PlayerManager player_2;
    
    
public:
    Battle(PlayerManager&& one, PlayerManager&& two);
    void setFirst(PlayerManager&& one, PlayerManager&& two);
    static void battle(PlayerManager& one, PlayerManager& two);
};

#endif /* Battle_hpp */
