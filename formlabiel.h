#ifndef FORMLABIEL_H
#define FORMLABIEL_H

#include <QWidget>

namespace Ui {
class FormLabiel;
}

class FormLabiel : public QWidget
{
    Q_OBJECT

public:
    explicit FormLabiel(QWidget *parent = 0);
    ~FormLabiel();

private:
    Ui::FormLabiel *ui;
};

#endif // FORMLABIEL_H
