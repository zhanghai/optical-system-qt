/*
 * Copyright (c) 2017 Zhang Hai <Dreaming.in.Code.ZH@Gmail.com>
 * All Rights Reserved.
 */

#include <QtWidgets/QMessageBox>
#include "main_window.h"

#include "ui_main_window.h"

#include "core.h"

MainWindow::MainWindow(QWidget *parent)
        : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    on_infiniteObjectDistanceCheck_stateChanged(
            ui->infiniteObjectDistanceCheck->checkState());
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_infiniteObjectDistanceCheck_stateChanged(int state) {
    bool isInfinite = isObjectDistanceInfinite();
    ui->fieldAngleSpin->setEnabled(isInfinite);
    ui->objectDistanceSpin->setEnabled(!isInfinite);
    ui->objectHeightSpin->setEnabled(!isInfinite);
}

void MainWindow::on_computeButton_clicked() {
    bool isInfinite = isObjectDistanceInfinite();
    char *error = core(isInfinite ? 1 : 0, ui->fieldAngleSpin->value(),
         ui->objectDistanceSpin->value(), ui->objectHeightSpin->value());
    if (error == NULL) {
        QMessageBox::information(this, windowTitle(), "计算成功");
    } else {
        QMessageBox::critical(this, windowTitle(), error);
    }
}

bool MainWindow::isObjectDistanceInfinite() {
    return ui->infiniteObjectDistanceCheck->checkState()
           != Qt::CheckState::Unchecked;
}
