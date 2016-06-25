//
//  jy.cpp
//  2yeon
//
//  Created by 민석 on 2016. 6. 25..
//  Copyright © 2016년 민석. All rights reserved.
//

#include <iostream>
#include <stdlib.h>
#include <time.h>


int main(void)
{
    int com,user;

    srand((unsigned)time(NULL));
    com=rand()%2;
    
    printf("가위바위보입력 0가위,1주먹,2보");
    scanf("%d",&user);
    
    if(com==0)
    {
        if(user==0)
            printf("draw");
        else if(user==1)
            printf("win");
        else
            printf("lose");
    }else if(com==1)
    {
        if(user==1)
            printf("draw");
        else if(user==0)
            printf("lose");
        else
            printf("win");
    }else if(com==2)
    {
        if(user==1)
            printf("lose");
        else if(user==2)
            printf("draw");
        else
            printf("win");
    }
}