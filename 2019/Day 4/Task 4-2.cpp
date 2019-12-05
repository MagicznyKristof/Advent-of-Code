#include <iostream>

using namespace std;

bool check ( int number );
int * split( int number );
bool check_for_doubles( int *number );
bool check_if_not_decreases ( int *number );
bool check_for_groups( int *number, int pos );

int main ()
{
	int count = 0;
	for( int i = 264793; i < 803935; i++ )
		if( check(i) )
			count++;
	cout << count << endl;
			
}

bool check_for_doubles( int *number )
{
	for(int i = 0; i < 5; i++ )
		if( number[i] == number[i+1] )
			if( check_for_groups(number, i) )
				return true;
	return false;
}

bool check_if_not_decreases ( int *number )
{
	for(int i = 0; i < 5; i++ )
		if( number[i] > number[i+1] )
			return false;
	return true;
}

bool check_for_groups( int *number, int pos )
{
	switch(pos){
		case 0: if( number[pos+1] == number[pos+2] ) return false;
				else return true;
		case 5: if( number[pos] == number[pos-1] ) return false;
				else return true;
		default: if( number[pos+1] == number[pos+2] || number[pos] == number[pos-1]) return false;
				else return true;
	}
}

bool check ( int number )
{
	int *tab = split( number );
	for (int i = 0; i < 6; i++ )
		if( check_for_doubles( tab ) && check_if_not_decreases( tab ) )
			return true;
	return false;
}

int * split( int number )
{
	static int r[6];
	for( int i = 0; i < 6; i++ )
	{
		r[5-i] = number % 10;
		number /= 10;
	} 
	return r;
}
