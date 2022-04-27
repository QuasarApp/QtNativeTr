//#
//# Copyright (C) 2021-2022 QuasarApp.
//# Distributed under the GPLv3 software license, see the accompanying
//# Everyone is permitted to copy and distribute verbatim copies
//# of this license document, but changing it is not allowed.
//#

#include "QtNativeTr/global.h"
#include <QString>

inline void initQtNativeTrResources() { Q_INIT_RESOURCE(QtNativeTr); }

namespace QtNativeTr {

/**
 * @brief init main initialize method of The QtNativeTr library
 * @return true if library initialized successfull
 */
bool QT_NATIVETR_EXPORT init();

/**
 * @brief version This method return string value of a library version
 * @return string value of a library version
 */
QString QT_NATIVETR_EXPORT version();

};
