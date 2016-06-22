//
//  Event.cpp
//  C++ Study
//
//  Created by 민석 on 2016. 6. 15..
//  Copyright © 2016년 민석. All rights reserved.
//

#include "Event.hpp"

CharacterSender::CharacterSender(std::string _name, int _HP, int _MP)
{
	name = _name;
	HP = _HP;
	MP = _MP;
}

void CharacterSender::renewal(int _HP, int _MP)
{
	HP = _HP;
	MP = _MP;
}

std::string CharacterSender::getName()
{
	return name;
}

int CharacterSender::getHP()
{
	return HP;
}

int CharacterSender::getMP()
{
	return MP;
}

void Event::ConsoleDelay()
{

#ifdef _WIN32
	Sleep(800);
#else
	usleep(1000 * 800);
#endif

}

void Event::MakeScreen(CharacterSender& subjectOne, CharacterSender& subjectTwo)
{
	std::cout << "\t\t\t\t 1 " << std::endl;
	std::cout << "\t\t\t\t 1 " << std::endl;
	std::cout << "\t\t\t\t  " << subjectOne.getHP() << "\t" << subjectTwo.getHP() << std::endl;
	std::cout << "\t\t\t\t 1 " << std::endl;
	std::cout << "\t\t\t\t 1 " << std::endl;
	std::cout << "\t\t\t\t 1 " << std::endl;
	std::cout << "\t\t\t\t 1 " << std::endl;
	std::cout << "\t\t\t\t 1 " << std::endl;
}