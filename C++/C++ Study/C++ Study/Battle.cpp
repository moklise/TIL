//
//  Battle.cpp
//  C++ Study
//
//  Created by 민석 on 2016. 6. 15..
//  Copyright © 2016년 민석. All rights reserved.
//

#include "Battle.hpp"

Battle::Battle(PlayerManager&& one, PlayerManager&& two)
{}
    
void Battle::setFirst(PlayerManager&& one, PlayerManager&& two)
{
    int one_coin = rand() % 100;
    int two_coin  = rand() % 100;

    if(one_coin > two_coin)
    {
        player_1 = std::move(one);
        player_2 = std::move(two);
    }else{
        player_1 = std::move(two);
        player_2 = std::move(one);
    }
}

void Battle::battle(PlayerManager& one, PlayerManager& two)
{
    // Do Battle
    int damage = one.getDamage();
    
    std::cout << one.getName() << " attacks " << two.getName() << " with " << damage << " damage(s)." << std::endl;
    
    // 서로 상태 받고 행동 - 판단 반복
    
    // 행동
    
    
    two.selectAction(one);
    // 반복
}