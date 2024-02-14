#include <iostream>
#include "Athletes.h"
#include <string>
#include <fstream>
#include <sstream>
using namespace std;
//Cloven Lo

// Uses getNumAthletes
void output(Athletes[], int);
void scoreSort(int&);
void populateStructure(Athletes[], int);

// Uses numAthlete from getNumAthletes.cpp

void scoreSort(int& numAthletes)
{
    Athletes* athletes = nullptr;
    athletes = new Athletes[numAthletes];

    // Populate and output the array of structs
    cout << "Populating the structure from a file...\n\n";
    populateStructure(athletes, numAthletes);
    cout << "\nOutputting Athletes from the structure...\n\n";
    output(athletes, numAthletes);

}

void populateStructure(Athletes athletes[], int totalAthletes)
{

    // Declare Variables
    string name, school, score, line;
    double feet, inches;
    int numAthletes = 0;

    // Open the input file
    ifstream inputFile("C:\\track_data\\raw-athletes.txt");
    if (!inputFile) { // Check if the input file was opened successfully
        cerr << "Error opening file" << endl; // Print an error message if the file could not be opened
        return;
    }

    while (inputFile && numAthletes < totalAthletes) {
        string line;
        getline(inputFile, line);
        if (line.empty()) {
            continue; // Skip empty lines
        }
        cout << line << endl;

        size_t pos1 = line.find("#"); // Find the position of the first hash symbol
        size_t pos2 = line.find_last_of("#"); // Find the position of the last hash symbol
        size_t pos3 = line.find_last_of('-');

        // Check if pos1 and pos3 are not equal to string::npos before extracting the feet and inches values #PROBLEM HERE!!!
        if (pos1 == string::npos || pos3 == string::npos) {
            cerr << "Error: Invalid input format in input line " << numAthletes + 1 << endl;
            continue; // Skip the current line and move on to the next line
        }

        // Extract each substring from the input line and assign to the appropriate variable
        name = line.substr(0, pos1);
        score = line.substr(pos1 + 1, pos2 - pos1 - 1);
        school = line.substr(pos2 + 1);
        // converts to feet and inches if the athlete has a previous score
        if (score != "-1")
        {
            feet = stod(line.substr(pos1 + 1, pos3 - 1));
            inches = stod(line.substr(pos3 + 1, pos2 - 1));
            athletes[numAthletes].feet = feet;
            athletes[numAthletes].inches = inches;
        }
        else
        {
            feet = 0;
            inches = 0;
            athletes[numAthletes].feet = 0;
            athletes[numAthletes].inches = 0;
        }

        // Add each to the structure
        athletes[numAthletes].name = name;
        athletes[numAthletes].score = score;
        athletes[numAthletes].school = school;
        numAthletes++; // Increment the counter for the number of Athlete objects read
        cin.clear(); // clears the buffer
    }

    inputFile.close();
    cout << "\nThere were " << numAthletes << " total lines read from the file.\n";
    cout << "\n------------------------------";

    // Sort the athletes array by feet in ascending order using selection sort algorithm
    for (int i = 0; i < numAthletes - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < numAthletes; j++)
        {
            if (athletes[j].feet < athletes[minIndex].feet)
            {
                minIndex = j;
            }
            else if (athletes[j].feet == athletes[minIndex].feet)
            {
                if (athletes[j].inches < athletes[minIndex].inches)
                    minIndex = j;
            }

        }
        if (minIndex != i) {
            Athletes temp = athletes[i];
            athletes[i] = athletes[minIndex];
            athletes[minIndex] = temp;
        }
    }
}


void output(Athletes arr[], int size)
{
    // Remove duplicates by comparing each athlete's name to the names of the other athletes
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i].name == arr[j].name) {
                // Remove the duplicate athlete object from the array
                for (int k = j; k < size - 1; k++) {
                    arr[k] = arr[k + 1];
                }
                size--; // Decrease the size of the array
                j--; // Decrement j so it continues to check the current position again
            }
        }
    }

    int index = 0;
    for (index = 0; index < size; index++)
    {
        //Output the structure
        cout << "Thrower: " << arr[index].name << endl;
        cout << "School: " << arr[index].school << endl;
        cout << "Distance Thrown: " << arr[index].feet <<
            " feet, " << arr[index].inches << " inches\n";
        cout << endl;
    }
    cout << "There were " << index << " total throwers in the structure.\n";
}