#include "tabeditor.h"
#include "ui_tabeditor.h"
#include <QGraphicsScene>
#include <QPixmap>

TabEditor::TabEditor(QWidget *parent, QString address) :
    QWidget(parent),
    ui(new Ui::TabEditor)
{
    ui->setupUi(this);
    scene = new QGraphicsScene();

    QImage bg(address);
    background = new QGraphicsPixmapItem(QPixmap::fromImage(bg));
    scene->addItem(background);

    ui->graphicsView->setScene(scene);

}

TabEditor::~TabEditor()
{
    delete ui;
    delete scene;
    delete background;
    delete history;
}
