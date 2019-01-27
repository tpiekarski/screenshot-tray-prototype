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
