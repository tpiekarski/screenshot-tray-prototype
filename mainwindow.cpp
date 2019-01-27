#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFileDialog>
#include <QIcon>
#include <QScreen>

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
  MainWindow::connectButtonSignals();
  MainWindow::setUpSystemTrayIcon();
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

void MainWindow::setUpSystemTrayIcon() {
  QIcon icon = QIcon(":/assets/system-icon.png");
  systemTrayIcon->setIcon(icon);
  setWindowIcon(icon);

  systemTrayIcon->setContextMenu(buildSystemTrayMenu());
}

void MainWindow::connectButtonSignals() {
  connect(ui->shootButton, &QPushButton::clicked, this, &MainWindow::onShootButtonClicked);
  connect(ui->saveButton, &QPushButton::clicked, this, &MainWindow::onSaveButtonClicked);
  connect(ui->hideButton, &QPushButton::clicked, this, &MainWindow::onHideButtonClicked);
  connect(ui->quitButton, &QPushButton::clicked, this, &MainWindow::onQuitButtonClicked);
}

QMenu *MainWindow::buildSystemTrayMenu() {
  connect(shootAction, &QAction::triggered, this, &MainWindow::shootScreen);
  connect(showAction, &QAction::triggered, this, &QWidget::showNormal);
  connect(quitAction, &QAction::triggered, this, &MainWindow::onQuitButtonClicked);

  systemTrayMenu->addAction(shootAction);
  systemTrayMenu->addAction(showAction);
  systemTrayMenu->addSeparator();
  systemTrayMenu->addAction(quitAction);

  return systemTrayMenu;
}

void MainWindow::onShootButtonClicked() {
  shootScreen();
}

void MainWindow::onSaveButtonClicked() {
    QFileDialog dialog(this, tr("Save Screenshot"), QDir::currentPath() + "\\tests\\");

    dialog.setFileMode(QFileDialog::AnyFile);
    dialog.setAcceptMode(QFileDialog::AcceptSave);
    dialog.setDefaultSuffix("jpg");
    dialog.setNameFilter(tr("Images (*.png *.jpg)"));

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
  ui->saveButton->setEnabled(true);
}
