#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#define CORRECT_RESULT 19690720

using namespace std;

vector < int > open();
void execute( vector < int > data );
vector < int > add( vector < int > data, int pos );
vector < int > mul( vector < int > data, int pos );
vector < int > read( vector < int > data, int pos );
void write( vector < int > data, int pos );

int main ()
{
	vector < int > data;
	
	data = open();
	execute( data );
	data.clear();
	return 0;
}

vector < int > open()
{
	ifstream fin;
	vector < int > data;
	string x;
	fin.open("Task 5-1.txt");
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

vector < int > add( vector < int > data, int pos )
{
	int term_1, term_2, mode = data[pos]/100;
	if( mode % 10 == 0 )
		term_1 = data[data[pos + 1]];
	if( mode % 10 == 1 )
		term_1 = data[pos + 1];
		
	mode /= 10;
	
	if( mode % 10 == 0 )
		term_2 = data[data[pos + 2]];
	if( mode % 10 == 1 )
		term_2 = data[pos + 2];
		
	data[data[pos + 3]] = term_1 + term_2;
	return data;
}

vector < int > mul( vector < int > data, int pos )
{
	int factor_1, factor_2, mode = data[pos]/100;
	if( mode % 10 == 0 )
		factor_1 = data[data[pos + 1]];
	if( mode % 10 == 1 )
		factor_1 = data[pos + 1];
		
	mode /= 10;
	
	if( mode % 10 == 0 )
		factor_2 = data[data[pos + 2]];
	if( mode % 10 == 1 )
		factor_2 = data[pos + 2];
		
	data[data[pos + 3]] = factor_1 * factor_2;
	return data;
}

vector < int > read( vector < int > data, int pos )
{
	int mode = data[pos]/100;
	if( mode % 10 == 0 )
		cin >> data[data[pos + 1]];
	if( mode % 10 == 1 )
		cin >> data[pos + 1];
	return data;
}

void write( vector < int > data, int pos )
{
	int mode = data[pos]/100;
	if( mode % 10 == 0 )
		cout << data[data[pos + 1]];
	if( mode % 10 == 1 )
		cout << data[pos + 1];
}

void execute ( vector < int > data )
{
	int pos = 0;
	while( data[pos] % 100 != 99 )
	{
		switch( data[pos] % 100 ) {
			case 1 : data = add( data, pos );
					 pos += 4;
					 break;
			case 2 : data = mul( data, pos );
					 pos += 4;
					 break;
			case 3 : data = read( data, pos );
					 pos += 2;
					 break;
			case 4 : write( data, pos );
					 pos += 2;
					 break;
			default : cout << "There has been a wrong input";
			}
	}
}
