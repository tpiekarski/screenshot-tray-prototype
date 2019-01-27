/*
 * Project:   screenshot-tray-prototype - A system-trayed screenshoot(ing) prototype
 * Github:    https://github.com/tpiekarski/screenshot-tray-prototype
 * Copyright: (c) 2019 Thomas Piekarski <t.piekarski@deloquencia.de>
 * License:   Mozilla Public License, v. 2.0
 *
 * This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
 * If a copy of the MPL was not distributed with this file, You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 */

#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[]) {
  QApplication app(argc, argv);
  MainWindow window;

  return app.exec();
}
