#ifndef POPWIDGET_H
#define POPWIDGET_H

#include <QWidget>

namespace Ui {
class MainWindow;
}

class PopMessage : public QWidget
{
    Q_OBJECT

public:
    explicit PopMessage(QWidget *parent = nullptr);
    ~PopMessage();

private:
    Ui::MainWindow *ui;
};

#endif // POPWIDGET_H
