#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <vector>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    invoker_(std::make_shared<Invoker>()),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->displayPanel->clear();

    connect(ui->num0, &QPushButton::released, this, [this]{LockPressed("0");});
    connect(ui->num1, &QPushButton::released, this, [this]{LockPressed("1");});
    connect(ui->num2, &QPushButton::released, this, [this]{LockPressed("2");});
    connect(ui->num3, &QPushButton::released, this, [this]{LockPressed("3");});
    connect(ui->num4, &QPushButton::released, this, [this]{LockPressed("4");});
    connect(ui->num5, &QPushButton::released, this, [this]{LockPressed("5");});
    connect(ui->num6, &QPushButton::released, this, [this]{LockPressed("6");});
    connect(ui->num7, &QPushButton::released, this, [this]{LockPressed("7");});
    connect(ui->num8, &QPushButton::released, this, [this]{LockPressed("8");});
    connect(ui->num9, &QPushButton::released, this, [this]{LockPressed("9");});

    connect(ui->actionPlus, &QPushButton::released, this, [this]{LockPressed("+");});
    connect(ui->actionMinus, &QPushButton::released, this, [this]{LockPressed("-");});
    connect(ui->actionDiv, &QPushButton::released, this, [this]{LockPressed("/");});
    connect(ui->actionMul, &QPushButton::released, this, [this]{LockPressed("*");});
    connect(ui->comma, &QPushButton::released, this, [this]{LockPressed(".");});

    connect(ui->switch1, &QPushButton::released, this, [this]{SwitchPressed(0);});
    connect(ui->switch2, &QPushButton::released, this, [this]{SwitchPressed(1);});
    connect(ui->switch3, &QPushButton::released, this, [this]{SwitchPressed(2);});
    connect(ui->switch4, &QPushButton::released, this, [this]{SwitchPressed(3);});

    connect(ui->actionDel, &QPushButton::released, this, &MainWindow::Delete);
    connect(ui->actionClear, &QPushButton::released, this, &MainWindow::Clear);
    connect(ui->actionCalc, &QPushButton::released, this, &MainWindow::Calculate);
    connect(ui->switchPage, &QPushButton::released, this, &MainWindow::SwitchPage);

    this->setFixedSize(QSize(444, 319));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::LockPressed(const std::string& command)
{
    invoker_->ExecMainCommand(command,expr_);

    ui->displayPanel->setText(QString::fromStdString(expr_));
}

void MainWindow::SwitchPressed(unsigned index){
    invoker_->ExecSwitchCommand(index,expr_);
    ui->displayPanel->setText(QString::fromStdString(expr_));
}

void MainWindow::SwitchPage(){
    ui->switch1->setText((ui->switch1->text()=="(") ? "sin" : "(");
    ui->switch2->setText((ui->switch2->text()==")") ? "cos" : ")");
    ui->switch3->setText((ui->switch3->text()=="sqrt") ? "tan" : "sqrt");
    ui->switch4->setText((ui->switch4->text()=="pow") ? "!" : "pow");
    invoker_->SwitchtPage();
}

void MainWindow::Delete()
{
    invoker_->DeleteLast(expr_);
    ui->displayPanel->setText(QString::fromStdString(expr_));
}

void MainWindow::Calculate()
{
    invoker_->Calculate(expr_);
    ui->displayPanel->setText(QString::fromStdString(expr_));
}

void MainWindow::Clear()
{
    invoker_->ClearAll(expr_);
    ui->displayPanel->setText(QString::fromStdString(expr_));
}


