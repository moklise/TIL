//
//  Battle.cpp
//  C++ Study
//
//  Created by 민석 on 2016. 6. 15..
//  Copyright © 2016년 민석. All rights reserved.
//

#include "Battle.hpp"


Battle::Battle(PlayerManager& one, PlayerManager& two)
{
//    setFirst(std::move(one), std::move(two));
    setFirst(one, two);
}

void Battle::start(PlayerManager& one, PlayerManager& two)
{
    bool result = battle(one, two);
    
    if(!result)
    {
        std::cout << "player 1 wins" << std::endl;
    }else
    {
        std::cout << "player 2 winds" << std::endl;
    }
    
}

bool Battle::battle(PlayerManager& one, PlayerManager& two)
{
    // Do Battle
    // 서로 상태 받고 판단 - 행동 반복
    int i = 0;
    while(i++ > 10)
    {
        // event
        jugde(one, one.selectAction(two), two, two.selectAction(one));
    }
    
    //    std::cout << one.getName() << " attacks " << two.getName() << " with " << damage << " damage(s)." << std::endl;
    
    return 1;
}


void Battle::jugde(PlayerManager& one, Action one_status, PlayerManager& two, Action two_status)
{
    // 대상의 행동
    switch (one_status) {
        case Action::Attack :
            // 나 공격
            
            switch (two_status) {
                case Action::Attack:
                    // 상대 공격
                    std::cout << "나는 공격했지만 상대도 공격했다." << std::endl;
                    break;
            
                case Action::Defense:
                    // 상대 방어
                    std::cout << "나는 공격했지만 상대는 막았다." << std::endl;
                    break;
                    
                case Action::Rest:
                    // 상대 휴식
                    std::cout << "나는 공격했지만 상대은 휴식을 취했다." << std::endl;
                    break;
            }
            break;
            
        case Action::Defense :
            // 나 방어
            
            switch (two_status) {
                case Action::Attack:
                    // 상대 공격
                    std::cout << "나는 방어했지만 상대는 공격했다." << std::endl;
                    break;
                    
                case Action::Defense:
                    // 상대 방어
                    std::cout << "나는 막았고 상대도 막았다." << std::endl;
                    break;
                    
                case Action::Rest:
                    // 상대 휴식
                    std::cout << "나는 막았지만 상대은 휴식을 취했다." << std::endl;
                    break;
            }
            break;
            
        case Action::Rest :
            // 나 휴식
            switch (two_status) {
                case Action::Attack:
                    // 상대 공격
                    std::cout << "나는 휴식을 취했지만 상대는 공격했다." << std::endl;
                    break;
                    
                case Action::Defense:
                    // 상대 방어
                    std::cout << "나는 휴식을 취했지만 상대는 막았다." << std::endl;
                    break;
                    
                case Action::Rest:
                    // 상대 휴식
                    std::cout << "나는 휴식을 취했지만 상대은 휴식을 취했다." << std::endl;
                    break;
            }
            break;
            
        default:
            
            // 상대방의 행동
            break;
    }
}

void Battle::setFirst(PlayerManager& one, PlayerManager& two)
{
    int one_coin = rand() % 100;
    int two_coin  = rand() % 100;

    if(one_coin > two_coin)
    {
//        player_1 = std::move(one);
//        player_2 = std::move(two);
        player_1 = one;
        player_2 = two;
    }else{
//        player_1 = std::move(two);
//        player_2 = std::move(one);
        player_1 = two;
        player_2 = one;
    }
}