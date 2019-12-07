#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//I do realize I should make a library out of this at this point but I'm not in the mood for that right now

class Amplifier
{
public:
	Amplifier(vector < int > data, int pos = 0, int first_input = 0, int second_input = 0 ):
		data(data), pos(pos), first_input(first_input), second_input(second_input) {}

public:
	vector < int > data;
	int pos;
	int first_input;
	int second_input;
};

vector < int > open();
int execute( vector < int > data, vector < Amplifier > amplifier );
vector < int > add( vector < int > data, int pos );
vector < int > mul( vector < int > data, int pos );
int jump_if_true ( vector < int > data, int pos );
int jump_if_false ( vector < int > data, int pos );
vector < int > less_than( vector < int > data, int pos );
vector < int > equals( vector < int > data, int pos );

int main ()
{
	vector < int > data;
	data = open();
	
	vector < Amplifier > amplifier( 5, data );
	
	int phase_table[5] = {5, 6, 7, 8, 9};
	int output = 0;
	int max_output = 0;
	do{
		for( int i = 0; i < 5; i++ )
			amplifier[i].first_input = phase_table[i];
		output = execute( data, amplifier );
		if( output > max_output )
			max_output = output;
	}while(next_permutation(phase_table, phase_table+5));
	data.clear();
	cout << max_output << endl;
	return 0;
}

vector < int > open()
{
	ifstream fin;
	vector < int > data;
	string x;
	fin.open("Task 7-1.txt");
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


int jump_if_true ( vector < int > data, int pos )
{
	int mode = data[pos]/100, check, jump;
	if( mode % 10 == 0 )
		check = data[data[pos + 1]];
	if( mode % 10 == 1 )
		check = data[pos + 1];
	
	mode /= 10;
	if( mode % 10 == 0 )
		jump = data[data[pos + 2]];
	if( mode % 10 == 1 )
		jump = data[pos + 2];
	
	if( check != 0 )
		return jump;
	else
		return pos + 3;
}

int jump_if_false ( vector < int > data, int pos )
{
	int mode = data[pos]/100, check, jump;
	if( mode % 10 == 0 )
		check = data[data[pos + 1]];
	if( mode % 10 == 1 )
		check = data[pos + 1];
	
	mode /= 10;
	if( mode % 10 == 0 )
		jump = data[data[pos + 2]];
	if( mode % 10 == 1 )
		jump = data[pos + 2];
	
	if( check == 0 )
		return jump;
	else
		return pos + 3;
}

vector < int > less_than( vector < int > data, int pos )
{
	int mode = data[pos]/100, comp_1, comp_2;
	if( mode % 10 == 0 )
		comp_1 = data[data[pos + 1]];
	if( mode % 10 == 1 )
		comp_1 = data[pos + 1];
	
	mode /= 10;
	if( mode % 10 == 0 )
		comp_2 = data[data[pos + 2]];
	if( mode % 10 == 1 )
		comp_2 = data[pos + 2];
	
	if(comp_1 < comp_2 )
		data[data[pos + 3]] = 1;
	else
		data[data[pos + 3]] = 0;
	return data;
}

vector < int > equals( vector < int > data, int pos )
{
	int mode = data[pos]/100, comp_1, comp_2;
	if( mode % 10 == 0 )
		comp_1 = data[data[pos + 1]];
	if( mode % 10 == 1 )
		comp_1 = data[pos + 1];
	
	mode /= 10;
	if( mode % 10 == 0 )
		comp_2 = data[data[pos + 2]];
	if( mode % 10 == 1 )
		comp_2 = data[pos + 2];
	
	if(comp_1 == comp_2 )
		data[data[pos + 3]] = 1;
		
	else
		data[data[pos + 3]] = 0;
	return data;
}

int execute( vector < int > data, vector < Amplifier > amplifier )
{
	int pos = 0;
	//a variable to iterate on amplifiers
	int i = 0;
	int output;	
	
	while( data[pos] % 100 != 99 )
	{
		switch( data[pos] % 100 ) {
			case 1 : data = add( data, pos );
					 pos += 4;
					 break;
			case 2 : data = mul( data, pos );
					 pos += 4;
					 break;
			case 3 : data[data[pos + 1]] = amplifier[i].first_input;
					 amplifier[i].first_input = amplifier[i].second_input;
					 pos += 2;
					 break;
			case 4 : output = data[data[pos + 1]];
					 pos += 2;
					 
					 //We have to save current amplifier's state
					 amplifier[i].data = data;
					 amplifier[i].pos = pos;
					 
					 //we have to iterate to next amplifier and load its state
					 i = ++i % 5; 
					 data = amplifier[i].data;
					 pos = amplifier[i].pos;
					 
					 if( amplifier[i].first_input == amplifier[i].second_input )
					 	amplifier[i].first_input = output;
					 	
					 amplifier[i].second_input = output;
					 break;
			case 5 : pos = jump_if_true( data, pos );
					 break;
			case 6 : pos = jump_if_false( data, pos );
					 break;
			case 7 : data = less_than( data, pos );
					 pos += 4;
					 break;
			case 8 : data = equals( data, pos );
					 pos += 4;
					 break;
			default : cout << "There has been a wrong input";
			}
	}
	return output;
}
