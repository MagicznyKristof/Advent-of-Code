#include <iostream>
#include <fstream>

using namespace std;

int main ()
{
	ifstream fin;
	int sum = 0, x;
	fin.open("Task 1-1.txt");
	if(fin.is_open() )
	{
		while( fin >> x )
		{
			sum += x / 3 - 2;
		}
		cout << sum << endl;
		fin.close();
	}
	else
		cout << "Can't open the file";
	return 0;
}
	
