#include "adicionar.h"
#include "ui_adicionar.h"
#include <QMessageBox>
#include <contato.h>
#include <vetorobjeto.h>
#include <indice.h>
#include <bits/stdc++.h>
using namespace std;


Adicionar::Adicionar(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Adicionar)
{

    ui->setupUi(this);
    setWindowTitle("Novo Contato");
}

Adicionar::~Adicionar()
{
    delete ui;
}

void Adicionar::on_pushButton_clicked()
{

    if(ui->checkBox->isChecked())
    {
        ui->checkBox->setChecked(false);

        Contato B;
        string T = ui->lineEdit->text().toStdString();

        if (T == "")
        {
             QMessageBox::information(this,"Alerta","Prencha os campos corretamente!!");
             return;
        }

        strcpy(B.Nome,ui->lineEdit->text().toStdString().c_str());
        strcpy(B.Telefone,ui->lineEdit_2->text().toStdString().c_str());
        strcpy(B.Endereco,ui->lineEdit_3->text().toStdString().c_str());
        B.Ano = ui->lineEdit_6->text().toInt();
        B.Dia = ui->lineEdit_4->text().toInt();
        B.Mes = ui->lineEdit_5->text().toInt();

        cout<<B.Nome<<endl;
        cout<<B.Telefone<<endl;
        cout<<B.Endereco<<endl;
        cout<<B.Dia<<endl;
        cout<<B.Mes<<endl;
        cout<<B.Ano<<endl;

        //Colocar no Arquivo Completo
        ofstream ARQ;
        ARQ.open("Contatos.dat",ios::binary|ios::app);

        B.PRelativa = ARQ.tellp()/sizeof(Contato);
        cout<<B.PRelativa<<endl;
        ARQ.write((char*)&B,sizeof(Contato));
        ARQ.close();

        //Criando o Indice
        indice OB;
        OB.TN = (int)T.size();
        strcpy(OB.Nome,ui->lineEdit->text().toStdString().c_str());
        OB.PRelativa = B.PRelativa;

        //Colocar no Arquivo de Indice
        VetorObjeto V;

        fstream ARQ2;
        ARQ2.open("Indice.dat",ios::binary|ios::app);

        ARQ2.write((char*)&OB,sizeof(indice));
        ARQ2.close();

        ui->lineEdit->clear();
        ui->lineEdit_2->clear();
        ui->lineEdit_3->clear();
        ui->lineEdit_4->clear();
        ui->lineEdit_5->clear();
        ui->lineEdit_6->clear();

    }
    else
    {
        QMessageBox::information(this,"Alerta","Check a caixa");
    }

}


