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
        std::cout << "player 2 wins" << std::endl;
    }
    
}

bool Battle::battle(PlayerManager& one, PlayerManager& two)
{
    // Do Battle
    // 판단 - 행동 반복
    while(1)
    {
        // 선공
        jugde(one, one.selectAction(two), two, two.selectAction(one));
        std::cout << "[" << one.getName() << "] " << one.getHP() << std::endl;
        std::cout << "[" << two.getName() << "] " << two.getHP() << std::endl << std::endl;
        std::cout << std::endl;
        std::cout << "##########################" << std::endl << std::endl;
        
        if( one.getHP() < 1 ) return true;
        else if( two.getHP() < 1) return false;
    }
    //    std::cout << one.getName() << " attacks " << two.getName() << " with " << damage << " damage(s)." << std::endl;
}

// 이제 Avoidance를 추가해줄 차례

void Battle::jugde(PlayerManager& one, Action one_status, PlayerManager& two, Action two_status)
{
    // 대상의 행동
    switch (one_status) {
        case Action::Attack :
            // 나 공격
            std::cout << one.getName() << " 공격 "<< std::endl;
            Event::ConsoleDelay();
            switch (two_status) {
                case Action::Attack:
                    // 상대 공격
                    std::cout << two.getName() << " 공격 " << std::endl;
                    Event::ConsoleDelay();
                    two.getDamage(one.hit());
                    one.getDamage(two.hit());
                    break;
            
                case Action::Defense:
                    // 상대 방어
                    std::cout << two.getName() << " 방어 " << std::endl;
                    
                    if(two.getAvoidance())
                        std::cout << two.getName() << "이(가) 회피했다!" << std::endl;
                    else
                        two.getDamage(one.hit());
                    
                    Event::ConsoleDelay();
                    break;
                    
                case Action::Rest:
                    // 상대 휴식
                    std::cout << two.getName() << " 휴식 " << std::endl;
                    Event::ConsoleDelay();
                    two.getDamage(one.hit());
                    break;
            }
            break;
            
        case Action::Defense :
            // 나 방어
            std::cout << one.getName() << " 방어 "<< std::endl;
            Event::ConsoleDelay();
            switch (two_status) {
                case Action::Attack:
                    // 상대 공격
                    std::cout << two.getName() << " 공격 " << std::endl;
                    Event::ConsoleDelay();
                    
                    if(one.getAvoidance())
                        std::cout << one.getName() << "이(가) 회피했다!" << std::endl;
                    else
                        one.getDamage(two.hit());
                    
                    break;
                    
                case Action::Defense:
                    // 상대 방어
                    std::cout << two.getName() << " 방어 " << std::endl;
                    Event::ConsoleDelay();
                    break;
                    
                case Action::Rest:
                    // 상대 휴식
                    std::cout << two.getName() << " 휴식 " << std::endl;
                    Event::ConsoleDelay();
                    break;
            }
            break;
            
        case Action::Rest :
            // 나 휴식
            switch (two_status) {
                case Action::Attack:
                    // 상대 공격
                    std::cout << " 휴식 : 공격 " << std::endl;
                    Event::ConsoleDelay();
                    break;
                    
                case Action::Defense:
                    // 상대 방어
                    std::cout << " 휴식 : 방어 " << std::endl;
                    Event::ConsoleDelay();
                    break;
                    
                case Action::Rest:
                    // 상대 휴식
                    std::cout << " 휴식 : 휴식 " << std::endl;
                    Event::ConsoleDelay();
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