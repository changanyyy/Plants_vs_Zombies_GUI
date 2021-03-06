#include "mainwindow.h"
#include "Config.h"
#include"plant.h"
#include"zombie.h"
#include"shop.h"
#include"chessboard.h"
#include<QGraphicsScene>
#include<QGraphicsView>
#include<QTimer>
#include<QMediaPlayer>
#include<QDebug>
#include"bullet.h"
#include"shovel.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    //初始化成员变量
    qDebug()<<"scene构造函数";
    this->scene=new QGraphicsScene(150,0,Window_Width,Window_Height,this);
    qDebug()<<"scene构造函数";
    this->view=new QGraphicsView(scene,this);
    qDebug()<<"view构造函数";
    this->timer=new QTimer(this);
    this->timectrl=new TimeCtrl(scene,timer);
    this->shop=new Shop;
    this->chessbd=new ChessBoard(600,320);
    scene->addItem(shop);
    scene->addItem(chessbd);
    shop->CreateCard();
    chessbd->SetShop(shop);
    qDebug()<<"添加商店 构造函数";
    //设定窗口大小
    this->setFixedSize(Window_Width,Window_Height);


    //禁用索引，防止运行缓慢
    scene->setItemIndexMethod(QGraphicsScene::NoIndex);


    timer->start();

    view->resize(Window_Width+2,Window_Height+2);
    view->setBackgroundBrush(QPixmap(":/resource/Background.jpg"));

    view->setRenderHint(QPainter::Antialiasing);
    view->setCacheMode(QGraphicsView::CacheBackground);
    view->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
    view->show();

    startSound=new QSound(":/resource/Grazy Dave.wav");  //创建一个音乐播放器
    startSound->play();

    Car* car1=new Car(240,130);
    Car* car2=new Car(240,230);
    Car* car3=new Car(240,330);
    Car* car4=new Car(240,430);
    Car* car5=new Car(240,530);
    scene->addItem(car1);
    scene->addItem(car2);
    scene->addItem(car3);
    scene->addItem(car4);
    scene->addItem(car5);

    shovel* sh=new shovel();
    scene->addItem(sh);

    connect(timer,&QTimer::timeout,timectrl,&TimeCtrl::Update);
    connect(timer,&QTimer::timeout,scene,&QGraphicsScene::advance);

}

MainWindow::~MainWindow()
{
    delete scene;
    delete view;
    delete timer;
    delete timectrl;
    delete startSound;
}

