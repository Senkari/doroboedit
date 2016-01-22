#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QUndoView>

#include "qttreepropertybrowser.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_actionNew_triggered();

    void on_tabWidget_tabCloseRequested(int index);

    void on_actionQuit_triggered();

    void on_actionAbout_Qt_triggered();

    void on_dockWidget_2_visibilityChanged(bool visible);

    void on_Propertydock_visibilityChanged(bool visible);

    void on_objectPicker_visibilityChanged(bool visible);

    void on_actionObjects_triggered(bool checked);

    void on_actionLevel_Objects_toggled(bool arg1);

    void on_actionLevel_Objects_triggered(bool checked);

    void on_actionProperties_triggered(bool checked);

    void on_actionMain_Toolbar_triggered(bool checked);

    void on_actionHistory_triggered(bool checked);

    void on_undoViewDock_visibilityChanged(bool visible);

    void on_tabWidget_currentChanged(int index);

private:
    Ui::MainWindow *ui;
    QUndoView *historyView;
    QtTreePropertyBrowser *propertyBrowser;
};

#endif // MAINWINDOW_H
