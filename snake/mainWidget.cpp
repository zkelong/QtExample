#include "mainWidget.h"

mainWidget::mainWidget(QWidget *parent)
    : QWidget(parent)
{
    this->resize(480,270);
    this->setMaximumSize(480,270);  //设置最大尺寸后，将不能最大化
    this->setMinimumSize(100,100); //设置最小尺寸，显示尺寸只能这么小，可以最小化；MinimumSize > MaxmumSize, 以MinimumSize为尺寸，且不能放大，缩小
    this->setWindowIcon(QIcon(":/new/prefix1/img/icon.png"));   //调用资源图片的格式
    this->setWindowTitle("贪吃蛇");
    QPalette palette;
    palette.setBrush(QPalette::Background,QBrush(QPixmap(":/new/prefix1/img/back.jpg").scaled(this->size())));
    this->setPalette(palette);

    startbtn=new QPushButton(this);
    startbtn->setIcon(QIcon(":/new/prefix1/img/start.png"));
    startbtn->setIconSize(QSize(75,75));
    startbtn->setGeometry(QRect(250,170,75,75));
    startbtn->setFlat(true);

    exitbtn=new QPushButton(this);
    exitbtn->setIcon(QIcon(":/new/prefix1/img/quit.png"));
    exitbtn->setIconSize(QSize(70,70));
    exitbtn->setGeometry(QRect(350,170,70,70));
    exitbtn->setFlat(true);
    //设置说明标签
    QFont font;
    font.setFamily("Consolas");
    font.setBold(true);
    font.setPixelSize(13);
    label=new QLabel(this);
    label->setText("游戏说明：贪吃蛇游戏可使用按钮或者w a s d控制蛇的走动");
    label->setFont(font);
    label->setGeometry(QRect(10,10,400,50));

    connect(exitbtn,SIGNAL(clicked()),this,SLOT(exitSlot()));
    connect(startbtn,SIGNAL(clicked()),this,SLOT(startSlot()));
}

mainWidget::~mainWidget()
{
    delete startbtn;
    delete exitbtn;
}
void mainWidget::exitSlot()
{
    if(QMessageBox::question(this,"退出游戏","是否退出当前游戏",QMessageBox::Yes|QMessageBox::No)==QMessageBox::Yes)
    {
        delete this;
        exit(0);
    }
}
void mainWidget::startSlot()
{

    g=new GameWidget(this);
    g->show();
}
//重写resizeEvent
/*void mainWidget::resizeEvent(QResizeEvent *)
{
    QPalette palette;
    palette.setBrush(QPalette::Background,QBrush(QPixmap("img/back.jpg").scaled(this->size())));
    this->setPalette(palette);
    startbtn->setGeometry(QRect(this->size().width()-230,this->size().height()-100,75,75));
    exitbtn->setGeometry(QRect(this->size().width()-130,this->size().height()-100,70,70));
}*/
