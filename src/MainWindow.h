//
// Created by rossw on 11/4/2022.
//

#ifndef PRISM_MAINWINDOW_H
#define PRISM_MAINWINDOW_H

#include <QtWidgets/QMainWindow>
#include "../gui/ui_mainwindow.h"


class MainWindow : public QMainWindow {
Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);

    ~MainWindow() override = default;

private:
    Ui::MainWindow *ui;
};


#endif //PRISM_MAINWINDOW_H
