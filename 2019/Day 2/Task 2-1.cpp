#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main ()
{
	ifstream fin;
	fin.open("Task 2-1.txt");
	vector < int > data;
	string x;
	int pos = 0;
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
		
	data[1] = 12;
	data[2] = 2;
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
	cout << data[ 0 ] << endl;
}
