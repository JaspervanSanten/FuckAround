#include "formlabiel.h"
#include "ui_formlabiel.h"

FormLabiel::FormLabiel(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormLabiel)
{
    ui->setupUi(this);
}

FormLabiel::~FormLabiel()
{
    delete ui;
}
