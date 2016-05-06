
#include "stdafx.h"
#include <iostream>
using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{
	for (int i = 0; i < 3; i++){
		int numOfStone, maxLength;
		int count = 0;
		int* arr;

		cin >> numOfStone;

		numOfStone++;

		arr = new int[numOfStone];

		arr[0] = 0;

		int maxDiff = 0;
		for (int j = 1; j < numOfStone; j++){
			cin >> arr[j];
			if (maxDiff < (arr[j] - arr[j - 1])){
				maxDiff = arr[j] - arr[j - 1];
			}
		}

		cin >> maxLength;

		if (maxDiff > maxLength){
			count = -1;
		}
		else{
			int temp = arr[0];
			while (temp != arr[numOfStone - 1]){
				temp += maxLength;

				int j = numOfStone - 1;
				while (1){
					if (arr[j] <= temp){
						temp = arr[j];

						count++;
						break;
					}
					j--;
				}
			}
		}


		cout << count << endl;

		delete[] arr;
	}
}
