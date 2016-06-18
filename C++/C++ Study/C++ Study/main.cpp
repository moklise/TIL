//
//  main.cpp
//  C++ Study
//
//  Created by 민석 on 2016. 6. 15..
//  Copyright © 2016년 민석. All rights reserved.
//

#include <iostream>
#include "Battle.hpp"
#include "PlayerManager.hpp"

int main(int argc, const char * argv[]) {
    
    PlayerManager myPlayer("Player1", 100, 8, 1, 1);
    PlayerManager yourPlayer("Player2", 100, 2, 7, 1);
    
    CustomPlayer A;
    PlayerManager((PlayerManager)A);
    
    myPlayer.getInfo();
    yourPlayer.getInfo();
    
    std::cout << std::endl;
    
    std::cout << "########### Battle Start ###########" << std::endl;
    
    Battle newBattle(myPlayer, yourPlayer);
    newBattle.start(myPlayer, yourPlayer);
    
    std::cout << "########### Battle end ###########" << std::endl;
//    myPlayer.getInfo();
    return 0;
}


//
// 개인의 알고리즘은 class 형태로 받는다.
// PlayerManager 의 자식을 이용한다.
//

