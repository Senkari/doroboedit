#include <QMessageBox>
#include <QFileDialog>

#include "newlevel.h"
#include "ui_newlevel.h"


NewLevel::NewLevel(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewLevel),
    name(""), background(""), music("")
{
    ui->setupUi(this);
}

NewLevel::~NewLevel()
{
    delete ui;
}

void NewLevel::on_NewLevel_accepted()
{
}

QString NewLevel::getName(){
    return name;
}

QString NewLevel::getBackground(){
    return background;
}

QString NewLevel::getMusic(){
    return music;
}

void NewLevel::on_cancelButton_clicked()
{
    this->reject();
}

void NewLevel::on_okButton_clicked()
{
    if(ui->lineEdit->text().isEmpty()){
        QMessageBox::critical(this,"Error","At least one character is required in the name!");
    }
    else{
        name = ui->lineEdit->text();
        background = ui->comboBox->currentText();
        music = ui->comboBox_2->currentText();
        this->accept();
    }
}

void NewLevel::on_pushButton_clicked()
{
    QString file = QFileDialog::getOpenFileName(this,"Select background",QString(),"Image Files (*.jpg *.jpeg *.png);;"
                                                                                    "JPEG Files (*.jpg *.jpeg);;"
                                                                                    "PNG Files (*.png);;"
                                                                                    "All Files (*.*)");
    ui->comboBox->addItem(file);
    ui->comboBox->setCurrentIndex(ui->comboBox->count()-1);
}

void NewLevel::on_pushButton_2_clicked()
{
    QString file = QFileDialog::getOpenFileName(this,"Select background",QString(),"Music Files (*.mid *.midi *.mp3 *.wav);;"
                                                                                    "MIDI Files (*.mid *.midi);;"
                                                                                    "MP3 Files (*.mp3);;"
                                                                                    "Wav Files (*.wav);;"
                                                                                    "All Files (*.*)");
    ui->comboBox_2->addItem(file);
    ui->comboBox_2->setCurrentIndex(ui->comboBox->count()-1);
}
