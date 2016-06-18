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
    
    PlayerManager myPlayer("minseok", 100, 5, 3, 3);
    PlayerManager yourPlayer("mm", 100, 10, 1, 3);
    
    customPlayer A;
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

