#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QPushButton>
#include <QScrollArea>
#include <QVBoxLayout>
#include <QMenu>
#include <QAction>
#include <QLabel>
#include <QColorDialog>
#include <QColor>
#include "renderarea.h"
#include "bst_properties_window.h"
#include "binarysearchtree.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT
    QWidget *centralWidget;

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    RenderArea *renderArea;
    QPushButton *propertyButton;
    QPushButton *deleteButton;
    QPushButton *insertButton;
    QLineEdit *insertValueLineEdit;
    QLineEdit *deleteValueLineEdit;
    QScrollArea *treeScrollArea;
    QVBoxLayout *mainLayout;
    QLabel *statusLabel;
    QMenu *editMenu;
    QAction *resetAction;
    BST_Properties_Window *prop;
    BinarySearchTree<int> *bst;
    BinarySearchTree<int> *getBST();
    void createMenu();
    void createActions();

protected:
    virtual void closeEvent(QCloseEvent *event);
    virtual void resizeEvent(QResizeEvent* event);

private slots:
    void propertyClicked() const;
    void insertClicked() const;
    void deleteClicked() const;
    void resetMenu() const;
};

#endif // MAINWINDOW_H
