#include <QString>
#include <QInputDialog>
#include "MAINWINDOW.H"
using namespace std;

int MainWindow::getFlightInput(int num_athletes)
{
	// declares variables
	int flights;
	bool ok;
	QString text, good, answer;
	bool validate = 1;

	// gets number of flights
	text = "There are " + QString::number(num_athletes);
	text += " athletes attending the meet.\nHow many flights would you like in this meet?";
	flights = QInputDialog::getInt(0, "", text, 1, 1, 100, 1, &ok, Qt::WindowStaysOnTopHint | Qt::FramelessWindowHint);

	// validates for number of flights
	text = "With " + QString::number(flights);
	text += " flights, there will be about ";
	text += "athletes per flight.\nIs this number appropriate? (y/n)\n";

	while (validate == 1)
	{
		answer = QInputDialog::getText(0, "", text, QLineEdit::Normal, "", &ok, Qt::WindowStaysOnTopHint | Qt::FramelessWindowHint);
		if (answer == "y")
			validate = 0;

		else if (answer == "n")
		{
			// re-prompts user for number of flights
			flights = QInputDialog::getInt(0, "", "Re-enter number of flights:", 1, 1, 100, 1, &ok, Qt::WindowStaysOnTopHint | Qt::FramelessWindowHint);
			validate = 0;
		}
	}

	return flights;
}