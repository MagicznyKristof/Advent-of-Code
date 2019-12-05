#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

int main ()
{
	ifstream fin;
	fin.open("Task 3-1.txt");

	//a variable that I'll be checking the position of the wire with while reading the input
	int pos[2] = {0, 0};
	string line, move;
	vector < int[3] > hor_1, hor_2;
	vector < int[3] > ver_1, ver_2;

	if( fin.is_open() )
	{
		getline( fin, line );
		cout << move << "\n";
		while( getline( line, move, ',' ) ){
			switch(move[0]){
				case 'R' : ver_1.push_back( {pos[0], pos[1], pos[1] + stoi( move.substr(1) ) } );
							pos[1] += stoi( move.substr(1) ); 
							break;
				case 'L' : ver_1.push_back( {pos[0], pos[1], pos[1] - stoi( move.substr(1) ) } ); 
							pos[1] -= stoi( move.substr(2) ); 
							break;
				case 'U' : hor_1.push_back( {pos[0], pos[1], pos[0] + stoi( move.substr(1) ) } ); 
							pos[0] += stoi( move.substr(2) ); 
							break;
				case 'D' : hor_1.push_back( {pos[0], pos[1], pos[0] - stoi( move.substr(1) ) } ); 
							pos[0] -= stoi( move.substr(2) ); 
							break;
		}
		
//		getline( fin, move );
	}
	else
		cout << "Couldn't open the file" << endl;
	cout << endl;
	
	 
//posortować po poziomych i pionowych liniach, sprawdzić przeciecia

}







