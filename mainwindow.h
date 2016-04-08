#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtCore>
#include <QtGui>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QString fileName;
    QTextDocument textDoc;
    void updateTitle();
protected:
    void paintEvent(QPaintEvent *e);

private slots:
    void slotOpenFile();
};

#endif // MAINWINDOW_H
