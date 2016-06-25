//
//  array.cpp
//  2yeon
//
//  Created by 민석 on 2016. 6. 25..
//  Copyright © 2016년 민석. All rights reserved.
//

#include <stdio.h>

int main()
{
    int array[5],i,max;
    
    for(i=0;i<10;i++)
    {
        array[i]=i;
        
        if(i>max)
        {
            max=i;
        }
    }
    
        
    printf("최댓값은%d\n",max);
    
}