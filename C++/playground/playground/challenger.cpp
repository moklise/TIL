//
//  challenger.cpp
//  playground
//
//  Created by 민석 on 2016. 5. 4..
//  Copyright © 2016년 민석. All rights reserved.
//

#include <iostream>

int DigitOne(int n);

int main(void){
    
    for(int i = 0 ; i < 2016 ; i++ )
    {
         std::cout << DigitOne(i) << " "  << std::endl;
    }

}

int DigitOne(int n) {
    int thing = 1;
    int pastThing = 1;
    int countOfDigits = 0; // count of Thing digits
    int allDigits = 0;

    if(!n){ return 2; }
    
    while( n > thing ){
        pastThing = thing;
        thing = thing * 10 + 1;
        countOfDigits++;
    }
    
    int indicator = n; // value
    int sub, Csub;   // differ btw smaller 1, Csub;  // differ btw bigger 1
    int pastCOD = countOfDigits;
    while( 1 ){
//        std::cout << "[0] indicator / thing / pastThing / allDigits" << std::endl << indicator << " " << thing << " " << pastThing << " " << allDigits << " " << countOfDigits << std::endl;
        
        if( indicator >= pastThing && thing >= indicator  ){
            sub = indicator - pastThing;
            Csub = thing - indicator;
            
            if( Csub < sub ){ // thing is more nearer
//                std:: cout << "PICK t," << thing << std::endl;
                
                indicator = Csub;
                allDigits += pastCOD+1;
                
            }else if( Csub > sub ){ // pastThing is more nearer
//                std::cout << "PICK p," << pastThing << std::endl;

                indicator = sub;
                allDigits += pastCOD;
                
            }else{
//                std::cout << "SAME" << pastThing << std::endl;
                
                if( indicator < 11 ){
                    allDigits += indicator;
                    break;
                }else{
                    allDigits += (pastCOD) * (indicator / pastThing);
                    indicator = indicator % pastThing;
                    
                }
            }
        }
        
//        std::cout << "[1] indicator / thing / pastThing / allDigits" << std::endl << indicator << " " << thing << " " << pastThing << " " << allDigits << " " << countOfDigits << std::endl;
        
        if( indicator < 11 && pastThing == 0 ){
            allDigits+=indicator;
            break;
        }
        
        if( indicator >= pastThing && thing >= indicator  ){
            
        }else{
            pastThing /= 10;
            thing /= 10;
            pastCOD -= 1;
            countOfDigits--;
        }
    }
    return allDigits;
}






