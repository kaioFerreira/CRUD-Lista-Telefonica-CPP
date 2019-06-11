#ifndef CONTATOMOSTRAR_H
#define CONTATOMOSTRAR_H

#include <QDialog>

namespace Ui {
class ContatoMostrar;
}

class ContatoMostrar : public QDialog
{
    Q_OBJECT

public:
    explicit ContatoMostrar(int index,QWidget *parent = 0);
    ~ContatoMostrar();

private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::ContatoMostrar *ui;
};

#endif // CONTATOMOSTRAR_H
