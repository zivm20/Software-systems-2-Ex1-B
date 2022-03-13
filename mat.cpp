#include "mat.hpp"
#include  <iostream>
using namespace std;

namespace ariel{
	const int MAX_CHAR_VAL = 126, MIN_CHAR_VAL = 33;
	string mat(int w, int h, char c1, char c2){
		//throw error messages for invalid input
		if(w<=0 || h<=0){
			throw std::invalid_argument("Width and height must be > 0");
		}
		if(w%2==0 || h%2==0){
			throw std::invalid_argument("Width and height must be odd");
		}	
		if(c1 < MIN_CHAR_VAL || c1 > MAX_CHAR_VAL || c2 < MIN_CHAR_VAL || c2 > MAX_CHAR_VAL  ){
			throw std::invalid_argument("Invalid character input");
		}
		
		//make a string of that represents a single line in an WxH matrix of all the chars c1 and 
		//a single line in an WxH matrix of all the chars c2
		string str1;
		string str2;
		for(int i = 0; i<w; i++){
			str1 += c1;
			str2 += c2;
		}
		string top;
		string bot;
		
		//choose desired line from matrix 1 or 2
		bool line = true;
		
		//add a line from mat1 then from mat2 alternating between the 2
		//notice the desired mat is mirrored so we make the top and bottom at the same time
		for(int i = 0; i<(h-1)/2; i++){
			string s;
			if(line){
				s = str1;
			}
			else{
				s = str2;
			}
			top += s;
			top += "\n";
			if(i != 0){
				s+="\n";
				s += bot;
				bot = s;	
			}
			else{
				bot = s;
			}

			//this step changes the 2 mats from fully made out of 1 char to something like this:
			/*
			$$$$$ <- 1st line in mat
			$-$-$
			$-$-$ <- 3rd line in mat
			$-$-$
			$$$$$ <- 5th line in mat

			and 

			$---$
			$---$ <- 2nd line in mat
			$-$-$
			$---$ <- 4th line in mat
			$---$

			we then take lines from each mat alternating between the 2
			*/

			if(i<(w+1)/2){
				if(line){
					str2[i] = c1;
					str2[w-1-i] = c1;
				}
				else{
					str1[i] = c2;
					str1[w-1-i] = c2;
				}
			}
			line = !line;
		}
		
		//we have an odd number of rows so we just add the middle row
		string s;
		if(line){
			s = str1;
			
		}
		else{
			s = str2;
		}
		s+="\n";
		top += s;
		
	//combine the 2 together
	top+=bot;
	return top;
	
	}

}




