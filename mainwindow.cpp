#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qmessagebox.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_thucHien_clicked()
{
    QString str_kq;
    QString nhap = ui->lineEdit_nhap->text();
    QList<QString> list = nhap.split(" ");

    //Sap xep
    if(ui->radioButton_sapXepTang->isChecked())
    {
        list.sort();
    } else if(ui->radioButton_sapXepGiam->isChecked())
    {
        QList<QString> temp = list;
        temp.sort();
        int dem = 0;
        list.clear();
        for(int i = (temp.length() - 1); i >= 0; i--)
        {
            list.insert(dem, temp.at(i));
            dem++;
        }

    }
    //Tim kiem
    if(ui->radioButton_timKiemGiaTri->isChecked())
    {
        QString giaTri = ui->lineEdit_timKiemGiaTri->text();

        if(list.count(giaTri) > 0)
        {
            ui->lineEdit_timKiemKQ->setText(giaTri);
        } else
        {
            ui->lineEdit_timKiemKQ->setText("Khong tim duoc");
        }
    } else if(ui->radioButton_timKiemViTri->isChecked())
    {
        int viTri = ui->lineEdit_timKiemViTri->text().toInt();
        ui->lineEdit_timKiemKQ->setText(list.at(viTri));
    }
    //Xoa
    if(ui->radioButton_xoaGiaTri->isChecked())
    {
        list.removeOne(ui->lineEdit_xoaGiaTri->text());
    } else if(ui->radioButton_xoaViTri->isChecked())
    {
        list.removeAt(ui->radioButton_xoaViTri->text().toInt());
    }
    //Them
    if(ui->radioButton_themGiaTri->isChecked())
    {
        list.insert(ui->lineEdit_themVitri->text().toInt(), ui->lineEdit_themGiaTri->text());
    }
    //Thay the
    if(ui->radioButton_thayTheGiaTri->isChecked())
    {
        QString giaTri = ui->lineEdit_thayTheGiaTri->text();
        for(int i = 0; i < list.length(); i++)
        {
            if(list.at(i) == giaTri)
            {
                list.removeAt(i);
                list.insert(i, ui->lineEdit_thayTheSo->text());
                break;
            }
        }
    }
    //KQ
    for(int i = 0; i < list.length(); i++)
    {
        str_kq += list.at(i);
        str_kq += " ";
    }
    ui->lineEdit_ketQua->setText(str_kq);
}

void MainWindow::on_pushButton_tong_clicked()
{
    int tong = 0;
    int tongChan = 0;
    int tongLe = 0;
    QList<QString> list = ui->lineEdit_ketQua->text().split(" ");
    for(int i = 0; i < list.length(); i++)
    {
        tong += list.at(i).toInt();
        if(list.at(i).toInt() % 2 == 0)
        {
            tongChan += list.at(i).toInt();
        } else
        {
            tongLe += list.at(i).toInt();
        }
    }

    ui->lineEdit_tongMang->setText(QString::number(tong));
    ui->lineEdit_tongChan->setText(QString::number(tongChan));
    ui->lineEdit_tongLe->setText(QString::number(tongLe));
}

void MainWindow::on_pushButton_maxmin_clicked()
{
    QList<QString> list = ui->lineEdit_ketQua->text().split(" ");
    int max = list.at(0).toInt();
    int min = list.at(0).toInt();

    for(int i = 1; i < list.length() - 1; i++)
    {
        if(list.at(i).toInt() >= max)
        {
            max = list.at(i).toInt();
        }
        if(list.at(i).toInt() <= min)
        {
            min = list.at(i).toInt();
        }
    }

    ui->lineEdit_max->setText(QString::number(max));
    ui->lineEdit_min->setText(QString::number(min));
}

void MainWindow::on_pushButton_reset_clicked()
{
    ui->lineEdit_nhap->setText("");
    ui->lineEdit_ketQua->setText("");
    ui->radioButton_sapXepTang->setChecked(false);
    ui->radioButton_sapXepGiam->setChecked(false);
    ui->radioButton_timKiemGiaTri->setChecked(false);
    ui->radioButton_timKiemViTri->setChecked(false);
    ui->lineEdit_timKiemGiaTri->setText("");
    ui->lineEdit_timKiemViTri->setText("");
    ui->lineEdit_timKiemKQ->setText("");
    ui->radioButton_xoaGiaTri->setChecked(false);
    ui->radioButton_xoaViTri->setChecked(false);
    ui->lineEdit_xoaGiaTri->setText("");
    ui->lineEdit_xoaViTri->setText("");
    ui->radioButton_themGiaTri->setChecked(false);
    ui->lineEdit_themGiaTri->setText("");
    ui->lineEdit_themVitri->setText("");
    ui->lineEdit_tongMang->setText("");
    ui->lineEdit_tongChan->setText("");
    ui->lineEdit_tongLe->setText("");
    ui->lineEdit_max->setText("");
    ui->lineEdit_min->setText("");
    ui->radioButton_thayTheGiaTri->setChecked(false);
    ui->radioButton_thayTheViTri->setChecked(false);
    ui->lineEdit_thayTheGiaTri->setText("");
    ui->lineEdit_thayTheViTri->setText("");
    ui->lineEdit_themGiaTri->setText("");
    ui->lineEdit_thayTheSo->setText("");
}

void MainWindow::on_pushButton_thoat_clicked()
{
    QMessageBox a;
            a.setWindowTitle("Close");
            a.setText("Ban co muon close khong?");
            a.setInformativeText("Nhan Yes de close");
            a.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
            a.setDefaultButton(QMessageBox::No);
            a.setIcon(QMessageBox::Warning);
            int ketQua = a.exec();
            switch (ketQua) {
                case QMessageBox::Yes:
                close();
                break;
            case QMessageBox::No:
                break;
            }


}
