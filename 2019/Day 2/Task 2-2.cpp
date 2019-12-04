#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#define CORRECT_RESULT 19690720

using namespace std;

int execute ( vector < int > data , int input_a, int input_b )
{
	data[1] = input_a;
	data[2] = input_b;
	int pos = 0;
	while( data[pos] != 99 )
	{
		switch( data[pos] ) {
			case 1 : data[data[pos + 3]] = data[data[pos + 1]] + data[data[pos + 2]];
					 break;
			case 2 : data[data[pos + 3]] = data[data[pos + 1]] * data[data[pos + 2]];
					 break;
			default : cout << "There has been a wrong input";
			}
		pos += 4;
	}
	return data[0];
}

vector < int > open()
{
	ifstream fin;
	vector < int > data;
	string x;
	fin.open("Task 2-1.txt");
	if( fin.is_open() )
	{
		while( getline (fin, x, ','))
		{
			data.push_back( stoi(x) );
		}
		fin.close();
	}
	else
		cout << "Can't open the file" << endl;
	return data;
}

int main ()
{
	vector < int > data;
	int noun = 0, verb = 0, result;
	
	data = open();
	result = execute( data, noun, verb );
	data.clear();
	
	while(result != CORRECT_RESULT){
		noun++;
		if( noun == 100 )
		{
			noun = 0;
			verb++;
		}
		data = open();
		result = execute( data, noun, verb );
		data.clear();
		
	}
	
	
	cout << 100 * noun + verb << endl;
}
