/*
 * Copyright (c) 2017 Zhang Hai <Dreaming.in.Code.ZH@Gmail.com>
 * All Rights Reserved.
 */

#ifndef ZDOUBLESPINBOX_H
#define ZDOUBLESPINBOX_H

#include <QDoubleSpinBox>

class ZDoubleSpinBox : public QDoubleSpinBox {

public:

    explicit ZDoubleSpinBox(QWidget *parent = Q_NULLPTR);

    QString textFromValue(double value) const override;
};

#endif //ZDOUBLESPINBOX_H
