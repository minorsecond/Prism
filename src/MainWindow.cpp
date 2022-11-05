//
// Created by rossw on 11/4/2022.
//

#include "MainWindow.h"
#include "ExifData.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    /*
     * Set up the main window.
     */

    ui->setupUi(this);
}