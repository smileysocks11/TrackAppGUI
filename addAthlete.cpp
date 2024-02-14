#include <QString>
#include <QInputDialog>
#include <fstream>
#include "MAINWINDOW.H"
#include "Athletes.h"
#include "TrackAppGUI.h"

// function prototypes
void scoreSort(int&);

/*--------------------------------
# addAthlete accepts no arguments
# It asks the user for the new athlete's
# name, max, and school. It then appends
# the information to the athletes file
# matching the existing format
----------------------------------*/

string MainWindow::addAthlete(Athletes athletes[], int num_athletes)
{
	// Placeholder file
	ofstream athleteFile("C:\\track_data\\raw-athletes.txt", ios_base::app);

	// Variables
	QString newFirstname; // User inputed first name
	QString newLastname; // User inputed last name
	QString newMax; // User inputed max, will be -1 if there is no max
	int feet; // User inputed feet (for max)
	int inches; // User inputed inches (for max)
	int qtrInches; // User inputed quarter inches (for max)
	QString displayNewMax; // Used to display max whwn outputed to user. This is to avoid displaying -1 if there is no max
	QString newSchool; // User inputed school
	QString ifMax; // Holds user input on whether or not the new athlete has a max
	QString confirm = "n"; // Holds user decision on whether or not to change information
	QString addNewAthlete = "y"; // Holds user decision on whetther or not to continue adding atheltes
	int inputCheck;
	bool check = true;
	bool validate = 1;
	QString text;
	bool ok;

	// Validates file
	if (!athleteFile)
		QMessageBox::information(this, "Error", "File not found.");
	else
	{

		while (addNewAthlete == 'y') // repeats as long as user wants to continue adding athletes
		{
			confirm = 'n';

			// Loops if user wishes to change the information before confirming adding the athlete
			while (confirm == 'n')
			{
				validate = 1;
				bool ok;
				while (validate == 1)
				{
					// Takes input for first name
					newFirstname = QInputDialog::getText(0, "", "Enter the first name of the athlete you would like to add:", QLineEdit::Normal, "", &ok, Qt::WindowStaysOnTopHint | Qt::FramelessWindowHint);

					if (ok && !newFirstname.isEmpty())
						validate = 0;
				}

				validate = 1;
				while (validate == 1)
				{
					/// Takes input for last name
					newLastname = QInputDialog::getText(0, "", "Enter the last name of the athlete you would like to add:", QLineEdit::Normal, "", &ok, Qt::WindowStaysOnTopHint | Qt::FramelessWindowHint);

					if (ok && !newLastname.isEmpty())
						validate = 0;
				}

				validate = 1;
				while (validate == 1)
				{
					// takes input for school name
					newSchool = QInputDialog::getText(0, "", "Enter the name of their school:", QLineEdit::Normal, "", &ok, Qt::WindowStaysOnTopHint | Qt::FramelessWindowHint);

					if (ok && !newSchool.isEmpty())
						validate = 0;
				}



				// Takes input for max
				while (validate == 1)
				{
					ifMax = QInputDialog::getText(0, "", "Do they have a max? (y/n):", QLineEdit::Normal, "", &ok, Qt::WindowStaysOnTopHint | Qt::FramelessWindowHint);
					if (ifMax == "y")
					{
						// Receives input for feet
						feet = QInputDialog::getInt(0, "", "Enter their max for feet:", 1, 1, 1000, 1, &ok, Qt::WindowStaysOnTopHint | Qt::FramelessWindowHint);

						// Receives input for inches
						inches = QInputDialog::getInt(0, "", "Enter their max for inches:", 1, 1, 11, 1, &ok, Qt::WindowStaysOnTopHint | Qt::FramelessWindowHint);

						// Receives input for quarter inches
						qtrInches = QInputDialog::getInt(0, "", "Enter their max for quarter inches:", 1, 1, 3, 1, &ok, Qt::WindowStaysOnTopHint | Qt::FramelessWindowHint);

						// joins max
						newMax = feet + "-" + inches;
						newMax += "." + qtrInches;
						displayNewMax = newMax;

						validate = 0;
					}

					else if (ifMax == "n")
					{
						newMax = "-1";
						displayNewMax = "No max";
						validate = 0;
					}
				}

				// Takes input for name of school
				validate = 1;
				while (validate == 1)
				{

					// Outputs what user has entered and asks them if it is correct
					text = "\nYou entered:\nFirst name : " + newFirstname;
					text += "\nLast name: " + newLastname;
					text += "\nMax: " + displayNewMax;
					text += "\nSchool: " + newSchool;
					text += "\nDoes this information look correct? (y/n): ";

					confirm = QInputDialog::getText(0, "", text, QLineEdit::Normal, "", &ok, Qt::WindowStaysOnTopHint | Qt::FramelessWindowHint);

					// validates
					if (confirm == "y" || confirm == "n")
						validate = 0;
				}

			}


			// Writes the new athlete's information to the file
			athleteFile << endl << newLastname.toStdString() << ", " << newFirstname.toStdString() << "#" << newMax.toStdString() << "#" << newSchool.toStdString();

			// Asks user if they would like to continue adding additional athletes
			validate = 1;
			while (validate == 1)
			{
				addNewAthlete = QInputDialog::getText(0, "", "Athlete added. Would you like to continue adding additional athletes? (y/n): ", QLineEdit::Normal, "", &ok, Qt::WindowStaysOnTopHint | Qt::FramelessWindowHint);

				// validates
				if (addNewAthlete == "y" || addNewAthlete == "n")
				{
					if (ok && !text.isEmpty())
						validate = 0;
				}

			}
		}
	}
	// Closes file
	athleteFile.close();


	scoreSort(num_athletes);

	string add = "add";
	return add;
}