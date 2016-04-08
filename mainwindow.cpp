#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QDir>
#include <QMessageBox>
#include <QXmlStreamReader>
#include <QtCore>
#include <QtGui>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->action_Open, SIGNAL(triggered(bool)), this, SLOT(slotOpenFile()), Qt::UniqueConnection);
    //ui->textBrowser->setVisible(false);
    //ui->textEdit->setVisible(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateTitle()
{
    //QString lTitle = "Fb2 Reader";
    QString lTitle = QString( "TextEditor-%1[*]").arg(fileName);
    //устанавливаем заголовок окна
    setWindowTitle(lTitle);
}

void MainWindow::slotOpenFile()
{
    QString lFileName=QFileDialog::getOpenFileName(this, "Openfile...", QDir::homePath(),"Textfiles(*.fb2);;Allfiles(*.*)");
    //указываем фильтры для просмотра файлов
    if(lFileName.isEmpty()) //Если пользователь не выбрал ни одного файла
    {
    return ; //выйти из метода
    }
    QFile lFile(lFileName); //Устанавливаем имя открытого файла
    //Если текстовый файл открыт только для чтения...
    /*if(lFile.open(QIODevice::ReadOnly|QIODevice::Text ))
    {
    fileName = lFileName; //задать имя файла
    //читаем все содержимое и устанавливаем текст для редактора
    ui->textEdit->setText(lFile.readAll());
    //ui->textEdit->setHtml(lFile.readAll());
    lFile.close(); //закрываем открытый файл
    //устанавливаем состояние окна — содержимое не модифицировано
    setWindowModified(false);
    //и обновляем заголовок окна для демонстрации названия текущего открытого файла
    updateTitle();
    }*/
    if(lFile.open(QIODevice::ReadOnly))
    {
        QSize s1(50,100);
        QSizeF s(s1);
        textDoc.setPageSize(s);
        textDoc.setPlainText(lFile.readAll());
        ui->textBrowser->append(QString::number(textDoc.pageCount()));
        qApp->processEvents();
        int i = 0;
//        QXmlStreamReader textStream(&lFile);
//        do{
//            textStream.readNext();
//            QString tegInfo = textStream.tokenString() + " " + textStream.name().toString() + " " + textStream.text().toString();
            //ui->textEdit->append(QString::number(i));
            //ui->textBrowser->append(QString::number(i));
//            ui->textBrowser->append(tegInfo);
            //ui->textBrowser->update();
//            qApp->processEvents();
//            i++;
//        } while(!textStream.atEnd());
        ui->textEdit->append(QString::number(i));
        lFile.close();
    }
    else
    {
    //Если при открытии файла возникла ошибка выводим диалоговое окно с сообщением,
    //содержащим имя файла, одну кнопку «Ок» и заголовок «Error»
    QMessageBox::warning(this,"Error",QString("Could not open file %1 for reading").arg(lFile.fileName()),QMessageBox::Ok) ;
    }
}

void MainWindow::paintEvent(QPaintEvent *e)
{
    QPainter painter(this);
//    painter.drawText(100,100,"Hello World");

    QRect rec(0,0,500,250);
    painter.translate(50,50);

//    QSize s1(50,100);
//    QSizeF s(s1);
//    textDoc.setPageSize(s);
//    textDoc.setPlainText("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabbbbbbbbbbbbbbbb");
    //textDoc.
//    textDoc.drawContents(&painter, rec);
}
