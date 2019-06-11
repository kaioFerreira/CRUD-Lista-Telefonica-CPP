#include "contatomostrar.h"
#include "ui_contatomostrar.h"
#include <indice.h>
#include <contato.h>
#include <bits/stdc++.h>
#include <QMessageBox>

using namespace std;

int PosicaoARQC;
int PosicaoARQI;

ContatoMostrar::ContatoMostrar(int index,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ContatoMostrar)
{
    ui->setupUi(this);
    setWindowTitle("Contato");

    indice A;
    Contato B;

    ifstream ARQ;
    cout<<"index "<<index<<endl;
    ARQ.open("Indice.dat",ios::binary|ios::app);
    ARQ.seekg(index*sizeof(indice),ARQ.beg);
    PosicaoARQI = index*sizeof(indice);
    ARQ.read((char*)&A,sizeof(indice));

    ARQ.close();


    ARQ.open("Contatos.dat",ios::binary|ios::app);
    ARQ.seekg(A.PRelativa*sizeof(Contato),ARQ.beg);
    PosicaoARQC = A.PRelativa*sizeof(Contato);
    ARQ.read((char*)&B,sizeof(Contato));
    ARQ.close();
    cout<<B.Nome<<endl;
    ui->lineEdit->setText(B.Nome);
    ui->lineEdit_2->setText(B.Telefone);
    ui->lineEdit_3->setText(B.Endereco);
    ui->lineEdit_4->setText(QVariant(B.Dia).toString());
    ui->lineEdit_5->setText(QVariant(B.Mes).toString());
    ui->lineEdit_6->setText(QVariant(B.Ano).toString());
    cout<<PosicaoARQC<<endl;

}

ContatoMostrar::~ContatoMostrar()
{
    delete ui;
}
void ContatoMostrar::on_pushButton_2_clicked()
{
    if (ui->checkBox->isChecked())
    {
        string B1;

        indice A,A1;
        Contato B;
        fstream ARQ;

        ARQ.open("Contatos.dat",ios::out);
        strcpy(B.Nome,ui->lineEdit->text().toStdString().c_str());
        strcpy(A.Nome,ui->lineEdit->text().toStdString().c_str());
        strcpy(B.Telefone,ui->lineEdit_2->text().toStdString().c_str());
        strcpy(B.Endereco,ui->lineEdit_3->text().toStdString().c_str());
        B.Dia = ui->lineEdit_4->text().toInt();
        B.Mes = ui->lineEdit_5->text().toInt();
        B.Ano = ui->lineEdit_6->text().toInt();


        ARQ.seekp(PosicaoARQC,ARQ.beg);
        ARQ.write((char *)&B,sizeof(Contato));
        ARQ.close();

        ARQ.open("Indice.dat",ios::out|ios::in);
        ARQ.seekp(PosicaoARQI,ARQ.beg);
        ARQ.read((char *)&A1,sizeof(indice));

        B1=ui->lineEdit->text().toStdString();

        A.Excluido = A1.Excluido;
        A.PRelativa = A1.PRelativa;
        A.TN = (int)B1.size();
        ARQ.seekp(PosicaoARQI,ARQ.beg);
        ARQ.write((char *)&A,sizeof(indice));
        ARQ.close();
        close();

    }
    else
    {
        QMessageBox::information(this,"Alerta","Check a caixa");
    }

}
void ContatoMostrar::on_pushButton_3_clicked()
{
    if(ui->checkBox->isChecked())
    {
        indice N3,N4;
        fstream ARQ;
        ARQ.open("Indice.dat",ios::out|ios::in);
        ARQ.seekp(PosicaoARQI,ARQ.beg);
        ARQ.read((char *)&N3,sizeof(indice));

        N3.Excluido = !N3.Excluido;

        ARQ.seekp(PosicaoARQI,ARQ.beg);
        ARQ.write((char*)&N3,sizeof(indice));
        this->close();
    }
    else
    {
        QMessageBox::information(this,"Alerta","Check a caixa");
    }
}
