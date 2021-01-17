#include "lotterydemo.h"
#include <QPainter>
#include <QPixmap>
#include <QTime>
#include <QMouseEvent>
#include <QDebug>
#include <QPropertyAnimation>
#include <QMessageBox>

QString LottertData[] = { QStringLiteral("一"),
                          QStringLiteral("二"),
                          QStringLiteral("三"),
                          QStringLiteral("四"),
                          QStringLiteral("五"),
                          QStringLiteral("六"),
                          QStringLiteral("七"),
                          QStringLiteral("八"),
                          QStringLiteral("九"),
                          QStringLiteral("十"),
                        };


#define STARTANGLE 0
#define BACKGROUND_ROTAION_ANGLE_START 18
LotteryDemo::LotteryDemo(QWidget *parent)
    : QWidget(parent)
    , m_rotation(STARTANGLE)
{
    ui.setupUi(this);
    initControl();
    m_pixmapBack = QPixmap(":/LotteryDemo/Resources/back.png");
    //注意缩放的时候需要接受返回值
    m_pixmapBack = m_pixmapBack.scaled(this->width(),this->height(),
                                       Qt::IgnoreAspectRatio,Qt::FastTransformation);

    m_selectPixmap.push_back(QPixmap(":/LotteryDemo/Resources/selected.png"));
    m_selectPixmap.push_back(QPixmap(":/LotteryDemo/Resources/selected2.png"));
    m_selectPixmap.push_back(QPixmap(":/LotteryDemo/Resources/selected3.png"));
    m_selectPixmap.push_back(QPixmap(":/LotteryDemo/Resources/selected4.png"));
    m_selectPixmap.push_back(QPixmap(":/LotteryDemo/Resources/selected5.png"));

    for(std::vector<QPixmap>::iterator iterPix = m_selectPixmap.begin(); iterPix != m_selectPixmap.end();iterPix++)
    {
        *iterPix = (*iterPix).scaled(this->width(),this->height(),
                                     Qt::KeepAspectRatio,Qt::FastTransformation);
    }

    ///抽中的需要遮住
    for (int i =0 ; i < 2 ; i++ ) {
        if(i != 0)
        {
            QPixmap pixmapSelect = m_selectPixmap.at(0).copy(this->rect());
            clockwise(pixmapSelect,180);
            m_selPartPixmap.insert(std::pair<int,QPixmap>(5,pixmapSelect));
        }
        else
        {
            m_selPartPixmap.insert(std::pair<int,QPixmap>(0,m_selectPixmap.at(0)));
        }
        if(i != 0)
        {
            QPixmap pixmapSelect = m_selectPixmap.at(1).copy(this->rect());
            clockwise(pixmapSelect,180);
            m_selPartPixmap.insert(std::pair<int,QPixmap>(6,pixmapSelect));
        }
        else
        {
            m_selPartPixmap.insert(std::pair<int,QPixmap>(1,m_selectPixmap.at(1)));
        }
        if(i != 0)
        {
            QPixmap pixmapSelect = m_selectPixmap.at(2).copy(this->rect());
            clockwise(pixmapSelect,180);
            m_selPartPixmap.insert(std::pair<int,QPixmap>(7,pixmapSelect));
        }
        else
        {
            m_selPartPixmap.insert(std::pair<int,QPixmap>(2,m_selectPixmap.at(2)));
        }
        if(i != 0)
        {
            QPixmap pixmapSelect = m_selectPixmap.at(3).copy(this->rect());
            clockwise(pixmapSelect,180);
            m_selPartPixmap.insert(std::pair<int,QPixmap>(8,pixmapSelect));
        }
        else
        {
            m_selPartPixmap.insert(std::pair<int,QPixmap>(3,m_selectPixmap.at(3)));
        }
        if(i != 0)
        {
            QPixmap pixmapSelect = m_selectPixmap.at(4).copy(this->rect());
            clockwise(pixmapSelect,180);
            m_selPartPixmap.insert(std::pair<int,QPixmap>(9,pixmapSelect));
        }
        else
        {
            m_selPartPixmap.insert(std::pair<int,QPixmap>(4,m_selectPixmap.at(4)));
        }
    }

    m_pointer = QPixmap(":/LotteryDemo/Resources/pointer.png");
    m_pointer = m_pointer.scaled(m_pointer.width()/2,m_pointer.height()/2);
    this->setWindowFlags(windowFlags()|Qt::FramelessWindowHint);
}

LotteryDemo::~LotteryDemo()
{

}

void LotteryDemo::initControl()
{
    qsrand(QTime(0, 0, 0).secsTo(QTime::currentTime()));
    setMouseTracking(true);
}

int LotteryDemo::getRotate()
{
    return m_rotation;
}

void LotteryDemo::setRotate(int rotate)
{
    m_rotation = rotate;
    update();
}

void LotteryDemo::paintEvent(QPaintEvent* event)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::SmoothPixmapTransform, true);
    painter.save();
    //窗口宽、高
    int nWindowWidth = this->width();
    int nWindowHeight = this->height();
    //背景图
    //中心偏移至中心位置
    painter.translate(nWindowWidth / 2.0, nWindowHeight / 2.0);
    //旋转m_rotation角度
    painter.rotate(-1 * m_rotation);
    painter.drawPixmap(QRect(0 - nWindowWidth / 2.0,
                             0 - nWindowHeight / 2.0,
                             m_pixmapBack.width(),
                             m_pixmapBack.height()),
                       m_pixmapBack);
    painter.restore();

    for(std::vector<int>::iterator iterSel = m_winerId.begin();
        iterSel!=m_winerId.end()&&m_selPartPixmap.size() > 0&&m_winerId.size() > 0;iterSel++)
    {
        painter.save();
        painter.translate(nWindowWidth / 2.0,nWindowHeight / 2.0);
        painter.rotate(-1*m_rotation);
        painter.drawPixmap(QRect(0 - nWindowWidth / 2.0,
                                 0 - nWindowHeight / 2.0,
                                 m_pixmapBack.width(),
                                 m_pixmapBack.height()),
                           m_selPartPixmap.at(*iterSel));
        //        qDebug()<<__FILE__<<__LINE__<< *iterSel ;
        painter.restore();
    }
    //绘制方向指针

    painter.save();
    m_pointerRect = QRect((nWindowWidth - m_pointer.width()) / 2,
                          (nWindowHeight - m_pointer.height() - 30) / 2,
                          m_pointer.width(), m_pointer.height());
    painter.drawPixmap(m_pointerRect, m_pointer);
    painter.restore();



    /*
   *__super 即调用基类的方法
   */
    __super::paintEvent(event);
}

void LotteryDemo::mousePressEvent(QMouseEvent *event)
{
    if (qApp->mouseButtons() == Qt::LeftButton)
    {
        QRegion ellipseRegion(m_pointerRect, QRegion::Ellipse);
        if (ellipseRegion.contains(event->pos()))
        {
            OnButtonPressed();
        }
    }
    __super::mousePressEvent(event);
}

void LotteryDemo::mouseMoveEvent(QMouseEvent *event)
{
    QRegion ellipseRegion(m_pointerRect, QRegion::Ellipse);
    if (ellipseRegion.contains(event->pos()))
    {
        setCursor(Qt::PointingHandCursor);
    }
    else
    {
        setCursor(Qt::ArrowCursor);
    }
    __super::mouseMoveEvent(event);
}

bool LotteryDemo::HasWiner(int index)
{
    foreach (int value, m_winerId) {
        if(value == index)
            return true;
    }
    return false;
}

void LotteryDemo::Push(int value)
{
    m_winerId.push_back(AngleToWinerid(value));
}

int LotteryDemo::AngleToWinerid(const int angle) const
{
    int value = (angle+18)%360;
    for (int index = 0; index < 10; index++)
    {
        value -= 36.0;
        if (value <= 0)
        {
            return index;
        }
    }
    return -1;
}

void LotteryDemo::onRotateFinished()
{
    float rotation = (m_rotation - 360 * 5+18)%360;
    int currentIndex = 0;
    for (int index = 0; index < 10; index++)
    {
        rotation -= 36.0;
        if (rotation <= 0)
        {
            qDebug()<<index;
            currentIndex = index;
            break;
        }
    }
    QMessageBox msgBox;
    QString message = QStringLiteral("恭喜您中了: %1等奖！").arg(LottertData[currentIndex]);
    msgBox.setText(message);
    msgBox.exec();
    m_winerId.push_back(currentIndex);
    //当达到最大值-1的时候就退出  最后一个不用抽
    if(m_winerId.size() == 9)
        __super::close();
}

void LotteryDemo::OnButtonPressed()
{
#ifdef ALLOW_REPATE
    int rotateRand = qrand() % 360 + 360 * 5;
#else
    int randValue = (qrand() + BACKGROUND_ROTAION_ANGLE_START)%360;
    while(HasWiner(AngleToWinerid(randValue))){randValue=(qrand()+BACKGROUND_ROTAION_ANGLE_START)%360;}
    int rotateRand = randValue + 360 * 5;
#endif //
    m_rotation = STARTANGLE;
    /*!
     * \brief animation
     * 特别注意这个是与 property 绑定的一旦animation 状态修改属性的值一会跟着修改
     */
    QPropertyAnimation *animation = new QPropertyAnimation(this, "rotate");
    animation->setEasingCurve(QEasingCurve::OutCubic);
    animation->setDuration(5000);
    animation->setStartValue(STARTANGLE);
    animation->setEndValue(rotateRand);
    connect(animation, SIGNAL(finished()), this, SLOT(onRotateFinished()));
    animation->start(QAbstractAnimation::DeleteWhenStopped);
}


//顺时针旋转
void LotteryDemo::clockwise(QPixmap &image,double angle)
{
    QMatrix matrix;
    matrix.rotate(angle);
    image = image.transformed(matrix,Qt::FastTransformation);
}
//逆时针旋转
void LotteryDemo::anticlockwise(QPixmap &image,double angle)
{
    QMatrix matrix;
    matrix.rotate(-angle);
    image = image.transformed(matrix,Qt::FastTransformation);
}
