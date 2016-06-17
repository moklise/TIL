//
//  PlayerManager.hpp
//  C++ Study
//
//  Created by 민석 on 2016. 6. 15..
//  Copyright © 2016년 민석. All rights reserved.
//

#ifndef PlayerManager_hpp
#define PlayerManager_hpp

#include <stdio.h>
#include "Event.hpp"

class customPlayer;
class PlayerManager
{
private:
    std::string name;
    int HP;
    int STR;
    int DEX;
    int INT;
    
public:
    PlayerManager();
    PlayerManager(std::string _name, int _HP, int _STR, int _DEX, int _INT);
        PlayerManager(const customPlayer& _man);
    PlayerManager& operator=(const PlayerManager& _subject);
    
    std::string getName() const;
    int getHP() const;
    int getSTR() const;
    int getDEX() const;
    int getINT() const;
    
    int getDamage() const;
    int getAvoidance() const;
    void getInfo() const;
    virtual Action selectAction(const PlayerManager& opponent);
};

class customPlayer : public PlayerManager
{
    Action selectAction(const PlayerManager& opponent);
};


#endif /* PlayerManager_hpp */
