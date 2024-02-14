#include "TrackAppGUI.h"

#ifndef __INTELLISENSE__
#include <QMutex>
#endif

TrackAppGUI::TrackAppGUI(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
}

TrackAppGUI::~TrackAppGUI()
{}
