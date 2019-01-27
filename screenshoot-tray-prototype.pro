#
# Project:   screenshot-tray-prototype - A system-trayed screenshoot prototype
# Github:    https://github.com/tpiekarski/screenshot-tray-prototype
# Copyright: (c) 2019 Thomas Piekarski <t.piekarski@deloquencia.de>
# License:   Mozilla Public License, v. 2.0
#
# This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
# If a copy of the MPL was not distributed with this file, You can obtain one at http://mozilla.org/MPL/2.0/.
#

QT       += core gui widgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = screenshoot-tray-prototype
TEMPLATE = app
DEFINES += QT_DEPRECATED_WARNINGS
CONFIG += c++14
CONFIG(release, debug|release) { DEFINES += QT_NO_DEBUG_OUTPUT }
INCLUDEPATH *= include

SOURCES += \
        src/main.cpp \
        src/mainwindow.cpp

HEADERS += \
        include/mainwindow.h

FORMS += \
        form/mainwindow.ui

RESOURCES += \
    screenshoot-tray-prototype.qrc

DISTFILES += \
    LICENSE \
    README.md \
    screenshot-tray-prototype.mf
