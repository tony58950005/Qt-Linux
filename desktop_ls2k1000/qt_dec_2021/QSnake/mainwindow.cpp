#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QLayout>
#include <QFileDialog>
#include <QMessageBox>
#include <QAction>
#include <QLCDNumber>
#include <QStyle>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setWindowTitle(tr("贪吃蛇"));
    gamearea = new GameArea(this);

    createActions();
    createMenus();
    createToolbar();
    createButtons();

    QLCDNumber *clock = new QLCDNumber(this);
    clock->setMaximumHeight(80);
    clock->setSegmentStyle(QLCDNumber::Filled);

    QWidget *buttonWidget = new QWidget(this);
    buttonWidget->setLayout(new QVBoxLayout);

    buttonWidget->layout()->addWidget(openButton);
    buttonWidget->layout()->addWidget(saveButton);
    buttonWidget->layout()->addWidget(startButton);
    buttonWidget->layout()->addWidget(pauseButton);
    buttonWidget->layout()->addWidget(resumeButton);
    buttonWidget->layout()->addWidget(resetButton);
    buttonWidget->layout()->addWidget(exitButton);

    QWidget *c_widget = new QWidget(this);
    setCentralWidget(c_widget);

    QGridLayout *gridLayout = new QGridLayout;
    gridLayout->setAlignment(Qt::AlignTop);
    c_widget->setLayout(gridLayout);

    gridLayout->addWidget(gamearea, 0, 0, -1, 6);
    gridLayout->setRowStretch(0, 1);

    gridLayout->addWidget(clock, 0, 7);
    gridLayout->addWidget(buttonWidget, 1, 7);

    connect(this, SIGNAL(toggleState()), gamearea, SLOT(stateChanged()));
    connect(gamearea, SIGNAL(gameResumed()), this, SLOT(gameHasStarted()));
    connect(gamearea, SIGNAL(gamePaused()), this, SLOT(gameHasPaused()));
    connect(gamearea, SIGNAL(gameReset()), this, SLOT(gameHasReset()));
    connect(gamearea, SIGNAL(gameEnded()), this, SLOT(gameHasStopped()));
    connect(gamearea, SIGNAL(updateTimer(int)), clock, SLOT(display(int)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    switch (event->key()) {
    case Qt::Key_Space:
        emit toggleState();
        break;
    default:
        QWidget::keyPressEvent(event);
    }
}

void MainWindow::createActions()
{
    auto useIcon = [](QStyle::StandardPixmap sp) {
        return QApplication::style()->standardIcon(sp);
    };

    openAct = new QAction(useIcon(QStyle::SP_DialogOpenButton), tr("&加载..."), this);
    openAct->setShortcuts(QKeySequence::Open);
    openAct->setStatusTip(tr("打开一个已保存的游戏"));
    connect(openAct, SIGNAL(triggered()), gamearea, SLOT(loadGame()));

    saveAct = new QAction(useIcon(QStyle::SP_DialogSaveButton), tr("&保存..."), this);
    saveAct->setShortcuts(QKeySequence::Save);
    saveAct->setStatusTip(tr("保存游戏到硬盘"));
    saveAct->setEnabled(false);
    connect(saveAct, SIGNAL(triggered()), gamearea, SLOT(saveGame()));

    exitAct = new QAction(useIcon(QStyle::SP_DialogCloseButton), tr("&退出"), this);
    exitAct->setShortcuts(QKeySequence::Quit);
    exitAct->setStatusTip(tr("退出当前程序"));
    connect(exitAct, &QAction::triggered, this, &QWidget::close);

    startAct = new QAction(useIcon(QStyle::SP_MediaPlay), tr("开始"), this);
    startAct->setStatusTip(tr("开始游戏"));
    connect(startAct, SIGNAL(triggered()), gamearea, SLOT(startGame()));

    pauseAct = new QAction(useIcon(QStyle::SP_MediaPause), tr("暂停"), this);
    pauseAct->setStatusTip(tr("暂停游戏"));
    pauseAct->setEnabled(false);
    connect(pauseAct, SIGNAL(triggered()), gamearea, SLOT(pauseGame()));

    resumeAct = new QAction(useIcon(QStyle::SP_MediaSeekForward), tr("继续"), this);
    resumeAct->setStatusTip(tr("继续游戏"));
    resumeAct->setEnabled(false);
    connect(resumeAct, SIGNAL(triggered()), gamearea, SLOT(resumeGame()));

    resetAct = new QAction(useIcon(QStyle::SP_DialogResetButton), tr("&重置"), this);
    resetAct->setStatusTip(tr("重置游戏"));
    resetAct->setEnabled(false);
    connect(resetAct, SIGNAL(triggered()), gamearea, SLOT(resetGame()));
}

void MainWindow::createMenus()
{
    fileMenu = ui->menubar->addMenu(tr("&文件"));
    fileMenu->addAction(openAct);
    fileMenu->addAction(saveAct);
    fileMenu->addSeparator();
    fileMenu->addAction(exitAct);

    gameMenu = ui->menubar->addMenu(tr("游戏"));
    gameMenu->addAction(startAct);
    gameMenu->addAction(pauseAct);
    gameMenu->addAction(resumeAct);
    gameMenu->addAction(resetAct);
}

void MainWindow::createToolbar()
{
    ui->toolBar->addAction(openAct);
    ui->toolBar->addAction(saveAct);
    ui->toolBar->addSeparator();
    ui->toolBar->addAction(startAct);
    ui->toolBar->addAction(pauseAct);
    ui->toolBar->addAction(resumeAct);
    ui->toolBar->addAction(resetAct);
    ui->toolBar->addSeparator();
    ui->toolBar->addAction(exitAct);
}

void MainWindow::createButtons()
{
    QSizePolicy policy(QSizePolicy::Minimum,
                       QSizePolicy::MinimumExpanding);

    openButton = new QPushButton(tr("&加载..."));
    openButton->setSizePolicy(policy);
    connect(openButton, SIGNAL(pressed()), gamearea, SLOT(loadGame()));

    saveButton = new QPushButton(tr("&保存..."));
    saveButton->setSizePolicy(policy);
    connect(saveButton, SIGNAL(pressed()), gamearea, SLOT(saveGame()));
    saveButton->setEnabled(false);

    exitButton = new QPushButton(tr("&退出"));
    exitButton->setSizePolicy(policy);
    connect(exitButton, &QPushButton::pressed, this, &QWidget::close);

    startButton = new QPushButton(tr("开始"));
    startButton->setSizePolicy(policy);
    connect(startButton, SIGNAL(pressed()), gamearea, SLOT(startGame()));
    startButton->setEnabled(true);

    pauseButton = new QPushButton(tr("暂停"));
    pauseButton->setSizePolicy(policy);
    connect(pauseButton, SIGNAL(pressed()), gamearea, SLOT(pauseGame()));
    pauseButton->setEnabled(false);

    resumeButton = new QPushButton(tr("继续"));
    resumeButton->setSizePolicy(policy);
    connect(resumeButton, SIGNAL(pressed()), gamearea, SLOT(resumeGame()));
    resumeButton->setEnabled(false);

    resetButton = new QPushButton(tr("&重置"));
    resetButton->setSizePolicy(policy);
    connect(resetButton, SIGNAL(pressed()), gamearea, SLOT(resetGame()));
    resetButton->setEnabled(false);
}

void MainWindow::gameHasReset()
{
    openAct->setEnabled(true);
    saveAct->setEnabled(false);
    startAct->setEnabled(true);
    pauseAct->setEnabled(false);
    resumeAct->setEnabled(false);
    resetAct->setEnabled(false);

    openButton->setEnabled(true);
    saveButton->setEnabled(false);
    startButton->setEnabled(true);
    pauseButton->setEnabled(false);
    resumeButton->setEnabled(false);
    resetButton->setEnabled(false);
}

void MainWindow::gameHasStarted()
{
    openAct->setEnabled(false);
    saveAct->setEnabled(false);
    startAct->setEnabled(false);
    pauseAct->setEnabled(true);
    resumeAct->setEnabled(false);
    resetAct->setEnabled(false);

    openButton->setEnabled(false);
    saveButton->setEnabled(false);
    startButton->setEnabled(false);
    pauseButton->setEnabled(true);
    resumeButton->setEnabled(false);
    resetButton->setEnabled(false);
}

void MainWindow::gameHasStopped()
{
    openAct->setEnabled(false);
    saveAct->setEnabled(false);
    startAct->setEnabled(false);
    pauseAct->setEnabled(false);
    resumeAct->setEnabled(false);
    resetAct->setEnabled(true);

    openButton->setEnabled(false);
    saveButton->setEnabled(false);
    startButton->setEnabled(false);
    pauseButton->setEnabled(false);
    resumeButton->setEnabled(false);
    resetButton->setEnabled(true);
}

void MainWindow::gameHasPaused()
{
    openAct->setEnabled(false);
    saveAct->setEnabled(true);
    startAct->setEnabled(false);
    pauseAct->setEnabled(false);
    resumeAct->setEnabled(true);
    resetAct->setEnabled(true);

    openButton->setEnabled(false);
    saveButton->setEnabled(true);
    startButton->setEnabled(false);
    pauseButton->setEnabled(false);
    resumeButton->setEnabled(true);
    resetButton->setEnabled(true);
}
