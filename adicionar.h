#ifndef ADICIONAR_H
#define ADICIONAR_H

#include <QDialog>

namespace Ui {
class Adicionar;
}

class Adicionar : public QDialog
{
    Q_OBJECT

public:
    explicit Adicionar(QWidget *parent = 0);
    ~Adicionar();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Adicionar *ui;
};

#endif // ADICIONAR_H
