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

void Screen::MakeScreen(std::string subjectOneName, int subjectOneHP, int subjectOneMP, std::string subjectTwoName, int subjectTwoHP, int subjectTwoMP)
{

	// Graphic
#ifdef _WIN32
	system("cls");
	std::cout << "\t\t\t  " << std::endl;
	std::cout << "\t\t\t  " << std::endl;
	std::cout << "\t\t\t " << subjectOneName << "\t\t" << subjectTwoName << std::endl;
	std::cout << "\t\t\t  " << std::endl;
	std::cout << "\t\t\t " << subjectOneHP << "\t\t" << subjectTwoHP << std::endl;
	std::cout << "\t\t\t " << subjectOneMP << "\t" << subjectTwoMP << std::endl;
	std::cout << "\t\t\t  " << std::endl;
	std::cout << "\t\t\t  " << std::endl;
	std::cout << "\t\t\t  " << std::endl;
	std::cout << "\t\t\t  " << std::endl;
#endif

	// Text Status


}