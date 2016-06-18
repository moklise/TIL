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
        
        Event::ConsoleDelay();
        std::cout << "[" << one.getName() << "] " << one.getHP() << " ";
        std::cout << "[" << two.getName() << "] " << two.getHP() << std::endl;
        
        Event::ConsoleDelay();
        std::cout << " ##### NEXT TURN #### " << std::endl;
        
        if( one.getHP() < 1 ) return true;
        else if( two.getHP() < 1) return false;
    }
}

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
                    two.getDamage(one.hit(),one.getName());
                    one.getDamage(two.hit(), two.getName());
                    break;
            
                case Action::Defense:
                    // 상대 방어
                    std::cout << two.getName() << " 방어 " << std::endl;
                    
                    if(two.getAvoidance())
                        std::cout << two.getName() << "이(가) 회피했다!" << std::endl;
                    else
                        two.getDamage(one.hit(), two.getName());
                    
                    Event::ConsoleDelay();
                    break;
                    
                case Action::Rest:
                    // 상대 휴식
                    std::cout << two.getName() << " 휴식 " << std::endl;
                    Event::ConsoleDelay();
                    
                    two.getDamage(one.hit(), one.getName());
                    
                    two.getRest();
                    
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
                        one.getDamage(two.hit(), two.getName());
                    
                    break;
                    
                case Action::Defense:
                    // 상대 방어
                    std::cout << two.getName() << " 방어 " << std::endl;
                    Event::ConsoleDelay();
                    
                    std::cout << "아무일도 일어나지않았다. " << std::endl;
                    Event::ConsoleDelay();
                    
                    break;
                    
                case Action::Rest:
                    // 상대 휴식
                    std::cout << two.getName() << " 휴식 " << std::endl;
                    Event::ConsoleDelay();
                    
                    std::cout << "아무일도 일어나지않았다. " << std::endl;
                    Event::ConsoleDelay();
                    
                    two.getRest();
                    
                    break;
            }
            break;
            
        case Action::Rest :
            // 나 휴식
            std::cout << one.getName() << " 휴식 " << std::endl;
            switch (two_status) {
                case Action::Attack:
                    // 상대 공격
                    std::cout << two.getName() << " 공격 " << std::endl;
                    Event::ConsoleDelay();
                    
                    one.getRest();
                    
                    one.getDamage(two.hit(), two.getName());
                    Event::ConsoleDelay();
                    break;
                    
                case Action::Defense:
                    // 상대 방어
                    std::cout << two.getName() << " 방어 " << std::endl;
                    Event::ConsoleDelay();
                    
                    one.getRest();
                    
                    std::cout << "아무일도 일어나지않았다. " << std::endl;
                    Event::ConsoleDelay();
                    
                    break;
                    
                case Action::Rest:
                    // 상대 휴식
                    std::cout << two.getName() << " 휴식 " << std::endl;
                    Event::ConsoleDelay();
                    
                    one.getRest();
                    two.getRest();
                    
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