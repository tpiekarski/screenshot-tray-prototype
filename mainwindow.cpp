#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QIcon>
#include <QScreen>
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent),
  ui(new Ui::MainWindow),
  systemTrayIcon(new QSystemTrayIcon(this)),
  systemTrayMenu(new QMenu(this)),
  shootAction(new QAction(tr("&Shoot"), this)),
  showAction(new QAction(tr("Sho&w"), this)),
  quitAction(new QAction(tr("&Quit"), this)),
  scene(new QGraphicsScene())
{
  ui->setupUi(this);

  QIcon icon = QIcon(":/assets/system-icon.png");
  systemTrayIcon->setIcon(icon);
  setWindowIcon(icon);

  connect(ui->shootButton, &QPushButton::clicked, this, &MainWindow::onShootButtonClicked);
  connect(ui->saveButton, &QPushButton::clicked, this, &MainWindow::onSaveButtonClicked);
  connect(ui->hideButton, &QPushButton::clicked, this, &MainWindow::onHideButtonClicked);
  connect(ui->quitButton, &QPushButton::clicked, this, &MainWindow::onQuitButtonClicked);

  connect(shootAction, &QAction::triggered, this, &MainWindow::shootScreen);
  connect(showAction, &QAction::triggered, this, &QWidget::showNormal);
  connect(quitAction, &QAction::triggered, this, &MainWindow::onQuitButtonClicked);

  systemTrayMenu->addAction(shootAction);
  systemTrayMenu->addAction(showAction);
  systemTrayMenu->addSeparator();
  systemTrayMenu->addAction(quitAction);

  systemTrayIcon->setContextMenu(systemTrayMenu);
}

MainWindow::~MainWindow() {
  if (systemTrayIcon != nullptr) {
    delete systemTrayIcon;
    systemTrayIcon = nullptr;
  }

  if (systemTrayMenu != nullptr) {
    delete systemTrayMenu;
    systemTrayMenu = nullptr;
  }

  if (showAction != nullptr) {
    delete showAction;
    showAction = nullptr;
  }

  if (shootAction != nullptr) {
    delete shootAction;
    shootAction = nullptr;
  }

  if (scene != nullptr) {
    delete scene;
    scene = nullptr;
  }

  if (ui != nullptr) {
    delete ui;
    ui = nullptr;
  }
}


void MainWindow::onShootButtonClicked() {
  shootScreen();
}

void MainWindow::onSaveButtonClicked() {
    QFileDialog dialog(this, tr("Save Screenshot"), QDir::currentPath());
    dialog.setFileMode(QFileDialog::AnyFile);
    dialog.setDefaultSuffix("jpg");

    if (dialog.exec() != QDialog::Accepted) {
      return;
    }

    screenshot.save(dialog.selectedFiles().first());
}

void MainWindow::onHideButtonClicked() {
    hide();
}

void MainWindow::onQuitButtonClicked() {
    close();
}

void MainWindow::shootScreen() {
  screenshot = QGuiApplication::primaryScreen()->grabWindow(0);
  scene->addPixmap(screenshot);

  ui->screenshotView->setScene(scene);
  ui->screenshotView->show();
}
