#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QAbstractButton>
#include <QKeyEvent>

#include "Invoker.hpp"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void LockPressed(const std::string& command);
    void SwitchPressed(unsigned index);

    void SwitchPage();
    void Calculate();
    void Clear();
    void Delete();

private:
    std::string expr_;
    std::shared_ptr<Invoker> invoker_;
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
