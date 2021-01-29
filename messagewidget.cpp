#include "messagewidget.h"
#include "ui_messagewidget.h"

#include <QPainter>

MessageWidget::MessageWidget(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MessageWidget)
{
    ui->setupUi(this);
    QPalette pal = palette();
    pal.setColor(QPalette::Background, QColor(0x00,0xff,0x00,0x00));
    setPalette(pal);
    //    setStyleSheet(QString::fromUtf8("QDialog#MessageWidget{background-color:transplant;}"));
    setWindowFlags(this->windowFlags()|Qt::FramelessWindowHint);
    setAttribute(Qt::WA_TranslucentBackground,true);
}

MessageWidget::~MessageWidget()
{
    delete ui;
}

void MessageWidget::paintEvent(QPaintEvent *event)
{

    QPixmap covert_pixmap(":/LotteryDemo/Resources/zjl.png");
    covert_pixmap = covert_pixmap.scaled(this->size());

    QPixmap pixmap(covert_pixmap.width(), covert_pixmap.height());

    pixmap.fill(Qt::transparent);

    QPainter painter(&pixmap);

    //    painter.fillRect(this->rect(), QColor(0, 0, 0, 0x20));

    QPoint start_point(0, 0);

    QPoint end_point(0, pixmap.height());

    //QLinearGradient进行渐变色设置

    QLinearGradient linear_gradient(start_point, end_point);

    linear_gradient.setColorAt(0, QColor(255, 255, 255, 255));

    linear_gradient.setColorAt(0.5, QColor(255, 255, 255, 255));

    linear_gradient.setColorAt(1, QColor(255, 255, 255, 255));

    painter.fillRect(this->rect(), QBrush(linear_gradient));

    painter.setCompositionMode(QPainter::CompositionMode_SourceIn);

    painter.drawPixmap(0, 0, covert_pixmap);

    painter.end();
    QPainter painter2(this);
    painter2.drawPixmap(0, 0, pixmap);
    //    return QWidget::paintEvent(event);
}
