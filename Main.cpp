/**
 * Main program for mat exercise.
 * 
 * Author: Ziv Morgan
 */

#include "mat.hpp"
#include <vector>

#include <iostream>
#include <stdexcept>
using namespace std;
/**
 * Takes string and splits it by the deliminator 
 *
 */
vector<string> split(string str, string deliminator){
	int start = 0;
	int end = 0;
	vector<string> out;
	int i = 0;
	while(end<str.length()){
		end = str.find(deliminator, start);
		out.push_back(str.substr(start,end-start));
		start = end+deliminator.length();
		
		
	}
	return out;
}


int main() {

	cout << "Enter desired values (seperated by spaces) for all mats (split by 2 spaces) and then press enter"<<endl<<"format: width height char1 char2  width height char1 char2"<<endl;
	//get entire line input
	string line;
	getline(cin,line,'\n');

	//each mat is seperated by "  "
	vector<string> mats = split(line,"  ");
	for(string s: mats){
		//get the 4 args in each mat
		vector<string> args = split(s," ");
		//if more than 4 args were given, only use the first 4 and continue
		if(args.size() >= 4){
			int width, height;
			char c1, c2;
			//if the user gave us invalid args, we continue to the next mat
			try{
				width = stoi(args[0]);
				height = stoi(args[1]);
				c1 = args[2].at(0);
				c2 = args[3].at(0);
				cout << ariel::mat(width, height, c1, c2) << endl;
			}
			catch(exception &e){
				continue;
			}
		}
	}
	return 0;
}









