#ifndef LOTTERYDEMO_H
#define LOTTERYDEMO_H

#include <QDialog>
#include "ui_lotterydemo.h"

class LotteryDemo : public QDialog
{
    Q_OBJECT
    Q_PROPERTY(int rotate READ getRotate WRITE setRotate)

public:
    LotteryDemo(QWidget *parent = 0);
    ~LotteryDemo();


protected:
    void paintEvent(QPaintEvent*);// 绘制事件
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);


public:
    int getRotate();
    void setRotate(int rotate);
    void showHead();
private slots:
    void onRotateFinished();
    void OnButtonPressed();

private:

    void initControl();
    bool HasWiner(int index);
    void Push(int value);
    int AngleToWinerid(int angle) const;
    void clockwise(QPixmap &image, double angle);
    void anticlockwise(QPixmap &image, double angle);

private:
    Ui::LotteryDemoClass ui;
    int m_rotation;
    QRect m_pointerRect;
    QPixmap m_pixmapBack;
    QPixmap m_pointer;
    std::vector<QPixmap> m_selectPixmap;
    std::vector<int> m_winerId;
    //选中的模块需要变色
    std::map<int,QPixmap> m_selPartPixmap;
};

#endif // LOTTERYDEMO_H
