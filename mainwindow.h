#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QString str_kq;

private slots:
    void on_pushButton_thucHien_clicked();

    void on_pushButton_tong_clicked();

    void on_pushButton_maxmin_clicked();

    void on_pushButton_reset_clicked();

    void on_pushButton_thoat_clicked();

private:
    Ui::MainWindow *ui;

};
#endif // MAINWINDOW_H
