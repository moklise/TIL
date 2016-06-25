//
//  floydAlgorithm.cpp
//  Modern Cpp
//
//  Created by 민석 on 2016. 6. 16..
//  Copyright © 2016년 민석. All rights reserved.
//

#include <iostream>
#include <vector>

int main(void)
{
    std::vector<std::vector<int>> d; // Cost Table.
    std::vector<std::vector<int>> via; // Via Table.
    
    for(int i = 0 ; i < d.size() ; i++)
        for(int j = 0 ; j < d.size() ; j++)
            d[i][j] = via[i][j];
    
    
    for(int k = 0 ; k < d.size() ; k++)
        for(int i = 0 ; i < d.size() ; i++)
            for(int j = 0 ; j < d.size() ; j++)
                if(d[i][j] > d[i][k] + d[k][j])
                {
                    d[i][j] = d[i][k] + d[k][j];
                    via[i][j] = k;
                }
    
}
