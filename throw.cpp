#include "MAINWINDOW.H"
#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>
#include <QInputDialog>
#include <QLabel>
#include <QSpinBox>
#include <QPushButton>
#include "Athletes.h"
using namespace std;

//Landon Marcotte


void MainWindow::throwTurns(Athletes a[], int flights, int athletes, int rounds)
{
	/*use the loop to loop through the array until all the athletes from a single flight has
	thrown and moves on to the next athletes in the structure bassed off their throw
	the second has the school they go to and the third has their best throw
	A failed attempt is a DQ in the stystem
	fill the first flight with more people than tht others if there are left*/


	// variables
	int div = athletes / flights;
	char choice;
	int checkIndex = 0;
	string toss;
	string measure;
	int tossCheck;
	bool scoreCheck = true;
	QString confirm = "n";
	QString text;
	bool ok;
	char delimeter = '-';
	size_t position;
	QString distance_throw;

	int count = 0, amount = 0;
	int inFlights[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

	for (size_t i = 0; i < flights; i++)
	{
		for (int index = 0; index < athletes; index++)
		{
			if (a[index].flightNum == i + 1)
				inFlights[i]++;
		}
	}

	for (int f = 0; f < flights; f++)
	{
		for (int r = 0; r < rounds; r++)
		{
			count = amount;

			// Output header
			cout << "\n------------------------------\nFlight " << f + 1 << ", Round "
				<< r + 1 << "\n------------------------------\n";

			for (int i = 0; i < inFlights[f]; i++)
			{
				text = "\nIs ";
				text += a[count].name;
				text += " here to throw?\n(y/n)>";

				confirm = QInputDialog::getText(0, "", text, QLineEdit::Normal, "", &ok, Qt::WindowStaysOnTopHint | Qt::FramelessWindowHint);

				if (confirm == "y")
				{
					for (int i = 0; i < 3; i++)
					{
						if (i == 0)
						{
							toss = "12";
							
							// gets input from user 
							text = "What is the distance of the athletes's throw? (feet-inches)";
							distance_throw = QInputDialog::getText(0, "", text, QLineEdit::Normal, "", &ok, Qt::WindowStaysOnTopHint | Qt::FramelessWindowHint);
							toss = confirm.toStdString();

							while (((toss == "-") || (position = toss.find(delimeter)) == string::npos) || (stoi((toss.substr(0, position))) > 12))
							{

								// error message
								QMessageBox::information(this, "Error", "Enter in the format: feet-inches");

								// gets input from user 
								text = "What is the distance of the athletes's throw? (feet-inches)";
								confirm = QInputDialog::getText(0, "", text, QLineEdit::Normal, "", &ok, Qt::WindowStaysOnTopHint | Qt::FramelessWindowHint);
								toss = confirm.toStdString();

							}

							
						}
						
					}
					//add a throw to the array
					//format for enter the numbers into the array 105-2.5
					if (r == 0)
					{
						a[count].throw1 = toss;
					}
					if (r == 1)
					{
						a[count].throw2 = toss;
					}
					if (r == 2)
					{
						a[count].throw3 = toss;
					}
					if (r == 3)
					{
						a[count].throw4 = toss;
					}
					cout << a[count].throw1 << endl;
				}
				// Put empty values into throw if athlete not here
				else if (confirm == "n")
				{
					if (r == 0)
					{
						a[count].throw1 = "-1";
					}
					if (r == 1)
					{
						a[count].throw2 = "-1";
					}
					if (r == 2)
					{
						a[count].throw3 = "-1";
					}
					if (r == 3)
					{
						a[count].throw4 = "-1";
					}
				}
				toss.clear();
				count++;
			}
		}
		amount += inFlights[f];
	}
}