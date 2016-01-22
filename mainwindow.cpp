#include <QUndoView>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "newlevel.h"
#include "editorview.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //Add historyView functionality
    historyView = new QUndoView(ui->undoViewDock);
    ui->undoViewDock->setWidget(historyView);

    propertyBrowser = new QtTreePropertyBrowser(ui->Propertydock);
    ui->Propertydock->setWidget(propertyBrowser);

    //Set edit and save buttons disabled as you can't use them anyway
    ui->actionUndo->setDisabled(true);
    ui->actionRedo->setDisabled(true);
    ui->actionCopy->setDisabled(true);
    ui->actionCut->setDisabled(true);
    ui->actionPaste->setDisabled(true);
    ui->actionSave->setDisabled(true);
    ui->actionSave_As->setDisabled(true);
    ui->actionZoomIn->setDisabled(true);
    ui->actionZoomOut->setDisabled(true);

    //Ensure that our menu items are properly checked
    ui->actionLevel_Objects->setChecked(true);
    ui->actionObjects->setChecked(true);
    ui->actionMain_Toolbar->setChecked(true);
    ui->actionProperties->setChecked(true);

    //Set item tabs disabled, you won't be using them anyway if there isn't any documents open
    ui->objectsTabWidget->setDisabled(true);

    ui->statusBar->showMessage("Ready");
}

MainWindow::~MainWindow()
{

    delete ui;
    delete historyView;
}

void MainWindow::on_actionNew_triggered()
{
    NewLevel* dialog = new NewLevel(this);
    ui->statusBar->showMessage("Creating new level...");
    if(dialog->exec()){
        EditorView *editorView = new EditorView(this, dialog->getBackground());
        ui->tabWidget->addTab(editorView, dialog->getName() + QString("*"));
        if(!ui->objectsTabWidget->isEnabled()){
            ui->objectsTabWidget->setEnabled(true);
            //ui->actionUndo->setEnabled(true);
            //ui->actionRedo->setEnabled(true);
            //ui->actionCopy->setEnabled(true);
            //ui->actionCut->setEnabled(true);
            //ui->actionPaste->setEnabled(true);
            ui->actionSave->setEnabled(true);
            ui->actionSave_As->setEnabled(true);
            ui->actionZoomIn->setEnabled(true);
            ui->actionZoomOut->setEnabled(true);
        }
        if(!dialog->getBackground().isEmpty()){

        }
    }
    delete dialog;
    ui->statusBar->showMessage("Ready");
}

void MainWindow::on_tabWidget_tabCloseRequested(int index)
{
    delete ui->tabWidget->widget(index);
    if(ui->tabWidget->count() == 0 && ui->objectsTabWidget->isEnabled()){
        ui->objectsTabWidget->setDisabled(true);
        ui->actionUndo->setDisabled(true);
        ui->actionRedo->setDisabled(true);
        ui->actionCopy->setDisabled(true);
        ui->actionCut->setDisabled(true);
        ui->actionPaste->setDisabled(true);
        ui->actionSave->setDisabled(true);
        ui->actionSave_As->setDisabled(true);
        ui->actionZoomIn->setDisabled(true);
        ui->actionZoomOut->setDisabled(true);
    }
}

void MainWindow::on_actionQuit_triggered()
{
    this->close();
}

void MainWindow::on_actionAbout_Qt_triggered()
{
    qApp->aboutQt();
}

void MainWindow::on_dockWidget_2_visibilityChanged(bool visible)
{
    ui->actionLevel_Objects->setChecked(visible);
}



void MainWindow::on_Propertydock_visibilityChanged(bool visible)
{
    ui->actionProperties->setChecked(visible);
}

void MainWindow::on_objectPicker_visibilityChanged(bool visible)
{
    ui->actionObjects->setChecked(visible);
}

void MainWindow::on_actionObjects_triggered(bool checked)
{
    ui->objectPicker->setVisible(checked);
}

void MainWindow::on_actionLevel_Objects_toggled(bool arg1)
{

}

void MainWindow::on_actionLevel_Objects_triggered(bool checked)
{
    ui->dockWidget_2->setVisible(checked);
}

void MainWindow::on_actionProperties_triggered(bool checked)
{
    ui->Propertydock->setVisible(checked);
}

void MainWindow::on_actionMain_Toolbar_triggered(bool checked)
{
    ui->toolBar->setVisible(checked);
}

void MainWindow::on_actionHistory_triggered(bool checked)
{
    ui->undoViewDock->setVisible(checked);
}

void MainWindow::on_undoViewDock_visibilityChanged(bool visible)
{
    ui->actionHistory->setChecked(visible);
}

void MainWindow::on_tabWidget_currentChanged(int index)
{
    if(ui->tabWidget->count() > 0){
        EditorView* editor = (EditorView*)ui->tabWidget->currentWidget();
        historyView->setStack(editor->getUndoStack());
    }
}
