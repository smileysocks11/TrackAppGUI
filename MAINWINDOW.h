#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QLineEdit>
#include "Athletes.h"


class MainWindow : public QMainWindow
{
public:
	MainWindow();
	int getFlightInput(int);
	string create_actions(Athletes[], int, int, int);

private:
	void create_menus();
	void about();
	string addAthlete(Athletes [] , int);
	void throwTurns(Athletes[], int, int, int);
	void viewAthletes(Athletes[], int, int, bool);

	QMenu* about_menu;
	QMenu* add_menu;
	QMenu* throw_menu;
	QMenu* view_menu;
	QMenu* adjust_menu;


};

#endif