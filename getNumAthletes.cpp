#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
using namespace std;

// Noah McGinley

/*------------------------------
# getNumAthletes accepts no arguments
# It opens the athletes files and counts
# line by line the amount of athletes
# It then returns the int num of athletes
--------------------------------*/
int getNumAthletes()
{
	// Opens nd validates the file
	ifstream inFile("C:\\track_data\\raw-athletes.txt");

	if (!inFile)
	{
		cout << "File not found.\n";
		return 0;

	}
	else
	{
		// Variables
		string line;
		int numAthletes = 0;

		// Loops through the file to count the number of lines
		while (getline(inFile, line))
		{
			numAthletes++;
		}

		// Closes file and returns num of athletes
		inFile.close();
		return numAthletes;
	}
}