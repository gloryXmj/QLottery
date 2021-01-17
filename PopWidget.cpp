#include "PopWidget.h"
#include "ui_PopWidget.h"

PopMessage::PopMessage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

PopMessage::~PopMessage()
{
    delete ui;
}
