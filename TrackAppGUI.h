#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_TrackAppGUI.h"

class TrackAppGUI : public QMainWindow
{
    Q_OBJECT

public:
    TrackAppGUI(QWidget *parent = nullptr);
    ~TrackAppGUI();

private:
    Ui::TrackAppGUIClass ui;
};
