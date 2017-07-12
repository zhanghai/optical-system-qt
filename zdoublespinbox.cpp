/*
 * Copyright (c) 2017 Zhang Hai <Dreaming.in.Code.ZH@Gmail.com>
 * All Rights Reserved.
 */

#include "zdoublespinbox.h"

ZDoubleSpinBox::ZDoubleSpinBox(QWidget *parent) : QDoubleSpinBox(parent) {
    setMaximum(std::numeric_limits<double>::max());
    setMinimum(std::numeric_limits<double>::lowest());
}

QString ZDoubleSpinBox::textFromValue(double value) const {
    return QDoubleSpinBox::textFromValue(value)
            .remove(QRegExp("\\.?0+$"));
}
