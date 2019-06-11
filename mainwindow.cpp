#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <contato.h>
#include <vetorobjeto.h>
#include <contatomostrar.h>
#include <indice.h>
#include <QMessageBox>
#include <fstream>
#include <adicionar.h>
#include <bits/stdc++.h>
using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("Agenda");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    Adicionar A;
    this->hide();
    A.setModal(true);
    A.exec();
    this->show();
}

void ana()
{
    fstream ARQ;

    VetorObjeto V;


    ARQ.open("Indice.dat",ios::in);
    ARQ.seekg(0,ARQ.end);
    int TAM = ARQ.tellg()/sizeof(indice);
    ARQ.seekg(0,ARQ.beg);

    ARQ.read((char*)&V.V,sizeof(indice)*TAM);
    ARQ.close();

    for (int i = 0 ; i < TAM ; i++)
    {
        for (int j = i ; j < TAM ; j++ )
        {
            if(strcmp(V.V[i].Nome , V.V[j].Nome) >0)
            {
                indice aux;

                aux.Excluido = V.V[i].Excluido;
                strcpy(aux.Nome,V.V[i].Nome);
                aux.PRelativa = V.V[i].PRelativa;
                aux.TN = V.V[i].TN;

                V.V[i].Excluido = V.V[j].Excluido;
                strcpy(V.V[i].Nome,V.V[j].Nome);
                V.V[i].PRelativa = V.V[j].PRelativa;
                V.V[i].TN = V.V[j].TN;

                V.V[j].Excluido = aux.Excluido;
                strcpy(V.V[j].Nome,aux.Nome);
                V.V[j].PRelativa = aux.PRelativa;
                V.V[j].TN = aux.TN;
            }
        }
    }
    ARQ.open("Indice.dat",ios::trunc|ios::out);
    ARQ.write((char*)&V.V,TAM*sizeof(indice));
    ARQ.close();
}

void MainWindow::on_pushButton_2_clicked()
{
    ifstream ARQ;
    indice A;
    VetorObjeto V;

    ui->listWidget->clear();
    ana();

    ARQ.open("Indice.dat");

    if (ARQ.is_open())
    {
        while(ARQ.read((char*)(&A),sizeof(indice)) && !ARQ.eof())
        {
            string AUX;
            for(int i = 0 ; i < A.TN ; i++)AUX+=A.Nome[i];
            if(!A.Excluido)
            ui->listWidget->addItem(QString::fromStdString(AUX));
        }
    }
    else
    {
         QMessageBox::information(this,"Alerta","Tente Novamente!\n Erro interno!");
    }

}

void MainWindow::on_listWidget_doubleClicked(const QModelIndex &index)
{
    ContatoMostrar C(index.row());
    this->hide();
    C.show();
    C.exec();
    this->show();
}

void MainWindow::on_pushButton_3_clicked()
{
    ifstream ARQ;
    indice A;
    ui->listWidget->clear();
    ARQ.open("Indice.dat");
    if (ARQ.is_open())
    {
        while(ARQ.read((char*)(&A),sizeof(indice)) && !ARQ.eof())
        {
            string AUX;
            for(int i = 0 ; i < A.TN ; i++)AUX+=A.Nome[i];
            if(A.Excluido)
            ui->listWidget->addItem(QString::fromStdString(AUX));
        }
    }
    else
    {
         QMessageBox::information(this,"Alerta","Tente Novamente!\n Erro interno!");
    }
}


void MainWindow::on_pushButton_4_clicked()
{
    fstream ARQV;
    ARQV.open("Indice.dat",ios::binary|ios::in|ios::out);
    ARQV.seekp(0);

    VetorObjeto V;
    indice A;

    int i = 0;
    while(!ARQV.eof())
    {
        ARQV.read((char*)&A,sizeof(indice));
        if(A.Excluido == false)
        {
            strcpy(V.V[i].Nome,A.Nome);
            cout<<V.V[i].Nome<<endl;
            V.V[i].Excluido = A.Excluido;
            V.V[i].TN = A.TN;
            V.V[i].PRelativa = A.PRelativa;
            i++;
        }
    }
    ARQV.close();
    i--;

    fstream ARQV1;
    ARQV1.open("Indice.dat",ios::trunc|ios::out);
    ARQV1.write((char*)&V.V,sizeof(indice)*i);
    ARQV1.close();
}
