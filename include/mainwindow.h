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

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QAction>
#include <QMainWindow>
#include <QSystemTrayIcon>
#include <QMenu>
#include <QGraphicsScene>
#include <QPixmap>

namespace Ui { class MainWindow; }

class MainWindow : public QMainWindow {
  Q_OBJECT

public:
  explicit MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

private slots:
  void onQuitButtonClicked();
  void onHideButtonClicked();
  void onShootButtonClicked();
  void onSaveButtonClicked();

private:
  Ui::MainWindow *ui;
  QSystemTrayIcon *systemTrayIcon;
  QMenu *systemTrayMenu;
  QAction *shootAction;
  QAction *showAction;
  QAction *quitAction;
  QGraphicsScene *scene;
  QPixmap screenshot;

  void setUpSystemTrayIcon();
  void connectButtonSignals();
  QMenu *buildSystemTrayMenu();
  void shootScreen();

};

#endif // MAINWINDOW_H
