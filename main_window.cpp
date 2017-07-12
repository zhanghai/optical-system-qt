/*
 * Copyright (c) 2017 Zhang Hai <Dreaming.in.Code.ZH@Gmail.com>
 * All Rights Reserved.
 */

#include "main_window.h"

#include "ui_main_window.h"

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
    bool isObjectDistanceInfinite = state != Qt::CheckState::Unchecked;
    ui->fieldAngleSpin->setEnabled(isObjectDistanceInfinite);
    ui->objectDistanceSpin->setEnabled(!isObjectDistanceInfinite);
    ui->objectHeightSpin->setEnabled(!isObjectDistanceInfinite);
}
