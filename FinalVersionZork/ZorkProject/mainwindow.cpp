#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ZorkUL.h"
using namespace std;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    zork = new ZorkUL();
;   // QObject::connect(ui->pushButton,&QPushButton::clicked,this,&MainWindow::goNorth);

}
//void MainWindow::goNorth(){
//cout<< "You went North"<<endl;
//}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    Command dir = Command("go", "north");
    string room = zork->goRoom(dir);
    QString str = QString::fromUtf8(room.c_str());
    ui->DirectionLabel->setText(str);
}


void MainWindow::on_pushButton_2_clicked()
{
    Command dir = Command("go", "east");
    string room = zork->goRoom(dir);
    QString str = QString::fromUtf8(room.c_str());
    ui->DirectionLabel->setText(str);
}


void MainWindow::on_pushButton_3_clicked()
{
    Command dir = Command("go", "west");
    string room = zork->goRoom(dir);
    QString str = QString::fromUtf8(room.c_str());
    ui->DirectionLabel->setText(str);
}


void MainWindow::on_pushButton_4_clicked()
{
    Command dir = Command("go", "south");
    string room = zork->goRoom(dir);
    QString str = QString::fromUtf8(room.c_str());
    ui->DirectionLabel->setText(str);
}


void MainWindow::on_pushButton_5_clicked()
{
    QString data = ui->useBox->toPlainText();
    Command use = Command("use", data.toStdString());
    zork-> processCommand(use);

}


void MainWindow::on_pushButton_6_clicked()
{
    QString data = ui->useBox->toPlainText();
    Command take = Command("take", data.toStdString());
    zork-> processCommand(take);
}


void MainWindow::on_pushButton_7_clicked()
{
    Command dab = Command("dab","");
    zork-> processCommand(dab);
    ui->main->setText("YOU HIT AN EPIC DAB!!");
}


void MainWindow::on_pushButton_8_clicked()
{
    Command map = Command("map","");
    zork-> processCommand(map);
    ui->main->setText("[The Armoury] --- [North Rampart] --- [The Library] \n        |                               |                             |       \n        |                               |                             |       \n [West Rampart] --- [The Courtyard] --- [East Rampart]\n        |                               |                             |       \n        |                               |                             |       \n[Mages Quaters] --- [South Rampart] --- [Kings Keep] \n                                        |                          \n                                 [Sketchy Rope]                   \n                                        |                          \n                                 [Rendezvous]                     \n");

}


void MainWindow::on_pushButton_10_clicked()
{
    Command inventory = Command("inventory","");
    zork-> processCommand(inventory);
}

