#ifndef TABEDITOR_H
#define TABEDITOR_H

#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QUndoStack>

namespace Ui {
class TabEditor;
}

class TabEditor : public QWidget
{
    Q_OBJECT

public:
    explicit TabEditor(QWidget *parent = 0, QString address = QString(""));
    ~TabEditor();

private:
    Ui::TabEditor *ui;
    QGraphicsScene *scene;
    QGraphicsPixmapItem *background;
    QUndoStack *history;
};

#endif // TABEDITOR_H
