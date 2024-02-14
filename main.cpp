#include <python.h>
#include <windows.h>
#include "MAINWINDOW.H"
#include "Athletes.h"
#include <QApplication>
#include <fstream>
#include <string>
#include "TrackAppGUI.h"
#include <QInputDialog>
#include <vector>
#include <iostream>

// function prototypes
int getNumAthletes();
void scoreSort(int&);
void getFlights(Athletes[], int, string, int);
void create_actions(Athletes a[], int flights, int athletes, int rounds);


int main(int argcc, char *argvv[])
{
	// opens main window
	QApplication app(argcc, argvv);
	MainWindow mw;
	mw.setWindowState(Qt::WindowMaximized);
	mw.setStyleSheet("background-image: url(:C:\\track_data\\raw-athletes.txt");
	mw.show();

	// repository creator
	wstring filePath = L"C:\\track_data";
	LPCWSTR path = filePath.c_str();

	// python
	const char* argv[2];
	argv[0] = "C:\\track_data\\webscrape.py";

	Py_Initialize();
	PyObject* obj = Py_BuildValue("s", argv[0]);
	FILE* file = _Py_fopen_obj(obj, "r");
	if (file)
		PyRun_SimpleFile(file, argv[0]);
	Py_Finalize();


	// declares variables
	int num_athletes;
	int flights, throws;
	bool ok;
	string input;

	// gets number of athletes and creates array
	num_athletes = getNumAthletes();
	Athletes* athletes = nullptr;
	athletes = new Athletes[num_athletes];

	// calls scoreSort to sort the athletes in the file
	scoreSort(num_athletes);

	// gets the number of flights
	flights = mw.getFlightInput(num_athletes);
	getFlights(athletes, num_athletes, input, flights);

	// gets number of throws
	throws = QInputDialog::getInt(0, "", "How many throws is each athlete attempting?", 1, 1, 4, 1, &ok, Qt::WindowStaysOnTopHint | Qt::FramelessWindowHint);
	
	string add = mw.create_actions(athletes, flights, num_athletes, throws);


    return app.exec();
}
