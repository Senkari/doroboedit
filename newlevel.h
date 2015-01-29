#ifndef NEWLEVEL_H
#define NEWLEVEL_H

#include <QDialog>

namespace Ui {
class NewLevel;
}

class NewLevel : public QDialog
{
    Q_OBJECT

public:
    explicit NewLevel(QWidget *parent = 0);
    ~NewLevel();
    QString getName();
    QString getBackground();
    QString getMusic();

private slots:
    void on_NewLevel_accepted();

    void on_cancelButton_clicked();

    void on_okButton_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::NewLevel *ui;
    QString name;
    QString background;
    QString music;
};

#endif // NEWLEVEL_H
