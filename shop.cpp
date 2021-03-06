#include "shop.h"
#include"plant.h"

Shop::Shop()
{
    sun=10000;
    img = new QPixmap(":/resource/Shop.png");
    setPos(600,30);
    mytype=Shop_t;
}

Shop::~Shop()
{
    if (img!=nullptr) delete img;
}

QRectF Shop::boundingRect() const
{
    return QRectF(-200, -30, 500, 60);
}

void Shop::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{

    if (img!=nullptr) painter->drawPixmap(QRect(-270, -45, 640, 90), *img);
    QFont font;
    font.setPointSizeF(10);
    painter->setFont(font);
    painter->drawText(QRectF(-255, 18, 65, 22), Qt::AlignCenter, QString::number(sun));
    painter->drawPoint(-220, 0);
}

void Shop::advance(int phase)
{
    if(phase==1)
        update();
}

void Shop::CreateCard(){
    Card* c1=new Card(450,30,":/resource/Peashooter.png",PeaShooter_t);
    Card* c2=new Card(500,30,":/resource/SunFlower.png",SunFlower_t);
    Card* c3=new Card(550,30,":/resource/WallNut.png",NutWall_t);
    Card* c4=new Card(600,30,":/resource/Tallnut.png",HighNut_t);
    Card* c5=new Card(650,30,":/resource/Repeater.png",DoubleShooter_t);
    Card* c6=new Card(700,30,":/resource/SnowPea.png",IceShooter_t);
    Card* c7=new Card(750,30,":/resource/PotatoMine.png",Potato_t);
    Card* c8=new Card(800,30,":/resource/CherryBomb.png",Cherry_t);
    Card* c9=new Card(850,30,":/resource/Garlic.png",Garlic_t);
    Card* c10=new Card(900,30,":/resource/Pumpkin.png",Pumpkin_t);
    scene()->addItem(c1);cardlist.append(c1);
    scene()->addItem(c2);cardlist.append(c2);
    scene()->addItem(c3);cardlist.append(c3);
    scene()->addItem(c4);cardlist.append(c4);
    scene()->addItem(c5);cardlist.append(c5);
    scene()->addItem(c6);cardlist.append(c6);
    scene()->addItem(c7);cardlist.append(c7);
    scene()->addItem(c8);cardlist.append(c8);
    scene()->addItem(c9);cardlist.append(c9);
    scene()->addItem(c10);cardlist.append(c10);
}

void Shop::CreatePlant(int xx,int yy,int ttype){
    qDebug()<<"即将放置 : "<<ttype;

    cardlist[ttype-1]->Cold();
    switch (ttype) {
    case PeaShooter_t:CreatePeaShooter(xx,yy);break;
    case SunFlower_t:CreateSunFlower(xx,yy);break;
    case NutWall_t:CreateNutWall(xx,yy);break;
    case HighNut_t:CreateHighNut(xx,yy);break;
    case DoubleShooter_t:CreateDoubleShooter(xx,yy);break;
    case IceShooter_t:CreateIceShooter(xx,yy);break;
    case Potato_t:CreatePotato(xx,yy);break;
    case Cherry_t:CreateCherry(xx,yy);break;
    case Garlic_t:CreateGarlic(xx,yy);break;
    case Pumpkin_t:CreatePumpkin(xx,yy);break;
    default:break;
    }
    return;
}
