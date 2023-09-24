#include "mainwindow.h"
#include "ui_mainwindow.h"

double first_num;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
   connect(ui->push_0,SIGNAL(clicked()),this,SLOT(digits_numbers()));
   connect(ui->push_1,SIGNAL(clicked()),this,SLOT(digits_numbers()));
   connect(ui->push_2,SIGNAL(clicked()),this,SLOT(digits_numbers()));
   connect(ui->push_3,SIGNAL(clicked()),this,SLOT(digits_numbers()));
   connect(ui->push_4,SIGNAL(clicked()),this,SLOT(digits_numbers()));
   connect(ui->push_5,SIGNAL(clicked()),this,SLOT(digits_numbers()));
   connect(ui->push_6,SIGNAL(clicked()),this,SLOT(digits_numbers()));
   connect(ui->push_7,SIGNAL(clicked()),this,SLOT(digits_numbers()));
   connect(ui->push_8,SIGNAL(clicked()),this,SLOT(digits_numbers()));
   connect(ui->push_9,SIGNAL(clicked()),this,SLOT(digits_numbers()));
   connect(ui->pushButton_neg,SIGNAL(clicked()),this,SLOT(operations()));
   connect(ui->pushButton_pro,SIGNAL(clicked()),this,SLOT(operations()));
    connect(ui->pushButton_plus,SIGNAL(clicked()),this,SLOT(math_operations()));
    connect(ui->pushButton_minus,SIGNAL(clicked()),this,SLOT(math_operations()));
    connect(ui->pushButton_multy,SIGNAL(clicked()),this,SLOT(math_operations()));
    connect(ui->pushButton_splash,SIGNAL(clicked()),this,SLOT(math_operations()));

    ui->pushButton_plus->setCheckable(true);
    ui->pushButton_minus->setCheckable(true);
     ui->pushButton_multy->setCheckable(true);
      ui->pushButton_splash->setCheckable(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::digits_numbers(){
    QPushButton*button = (QPushButton*)sender();

    double all_numbers;
    QString new_label;
    if(ui->line->text().contains('.') && button->text() == "0"){
        new_label = ui->line->text()+button->text();
    }
    else {
    all_numbers = (ui->line->text()+button->text()).toDouble();
    new_label = QString::number(all_numbers, 'g', 15);
    }
    ui->line->setText(new_label);

}


void MainWindow::on_pushButton_dot_clicked()
{
    if(!(ui->line->text().contains('.'))){
         ui->line->setText( ui->line->text() + '.');
    }
}
void MainWindow::operations(){
    QPushButton*button = (QPushButton*)sender();

    double all_numbers;
    QString new_label;

    if(button->text() == "+/-"){
    all_numbers = (ui->line->text()).toDouble();
    all_numbers = all_numbers * -1;
    new_label = QString::number(all_numbers, 'g', 15);
    ui->line->setText(new_label);}
    else if(button->text() == "%"){
        all_numbers = (ui->line->text()).toDouble();
        all_numbers = all_numbers * 0.01;
        new_label = QString::number(all_numbers, 'g', 15);
        ui->line->setText(new_label);}
}
void MainWindow::math_operations(){
    QPushButton*button = (QPushButton*)sender();
    button->setChecked(true);
    first_num = ui->line->text().toDouble();
    ui->line->setText("");

     button->setChecked(true);

}
void MainWindow::on_pushButton_equ_clicked()
{
    double label_number, new_second;
    QString new_label;

    new_second = ui->line->text().toDouble();

    if(ui->pushButton_plus->isChecked()){
        label_number = first_num + new_second;
        new_label = QString::number(label_number, 'g', 15);

        ui->line->setText(new_label);
        ui->pushButton_plus->setChecked(false);
    }
    else if(ui->pushButton_minus->isChecked()){
        label_number = first_num - new_second;
        new_label = QString::number(label_number, 'g', 15);
        ui->line->setText(new_label);
        ui->pushButton_minus->setChecked(false);
    }
    else if(ui->pushButton_multy->isChecked()){
        label_number = first_num * new_second;
        new_label = QString::number(label_number, 'g', 15);
        ui->line->setText(new_label);
        ui->pushButton_multy->setChecked(false);
    }
    else if(ui->pushButton_splash->isChecked()){
        if(new_second == 0){
        ui->line->setText("0");}
        else {
        label_number = first_num / new_second;
        new_label = QString::number(label_number, 'g', 15);
        ui->line->setText(new_label);
        }
        ui->pushButton_splash->setChecked(false);
    }
    }


void MainWindow::on_pushButton_AC_clicked()
{
    ui->pushButton_plus->setChecked(false);
     ui->pushButton_minus->setChecked(false);
      ui->pushButton_splash->setChecked(false);
       ui->pushButton_multy->setChecked(false);

       ui->line->setText("0");
}
