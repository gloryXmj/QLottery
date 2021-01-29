#ifndef MESSAGEWIDGET_H
#define MESSAGEWIDGET_H

#include <QDialog>

namespace Ui {
class MessageWidget;
}

class MessageWidget : public QDialog
{
    Q_OBJECT

public:
    explicit MessageWidget(QWidget *parent = nullptr);
    ~MessageWidget();
protected:
    virtual void paintEvent(QPaintEvent *event) override;

private:
    Ui::MessageWidget *ui;
};

#endif // MESSAGEWIDGET_H
