#include "mainwindow.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QCloseEvent>
#include <QMenuBar>
#include <QSpacerItem>
#include <qglobal.h>
#include <QTime>
#include <QFileDialog>
#include <QStandardPaths>
#include <QFileInfo>
#include <QFile>
#include <QTextStream>
#include <QStringList>
#include <QStringListIterator>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{

    QString directory = QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation) + "/BSTVisualizer";
    if (!QDir(directory).exists())
        QDir().mkdir(directory);

    this->bst = this->getBST();

    this->createMenu();

    propertyButton = new QPushButton("&Properties", this);
    deleteButton = new QPushButton("&Delete", this);
    insertButton = new QPushButton("Insert", this);
    insertValueLineEdit = new QLineEdit;
    deleteValueLineEdit = new QLineEdit;
    statusLabel = new QLabel;

    propertyButton->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    deleteButton->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    insertButton->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);

    insertValueLineEdit->setFixedWidth(200);
    insertValueLineEdit->setToolTip("Enter single value or multiple values separated by space");

    deleteValueLineEdit->setFixedWidth(100);
    deleteValueLineEdit->setToolTip("Enter value to delete");

    connect(propertyButton, SIGNAL(clicked()), this, SLOT(propertyClicked()));
    connect(deleteButton, SIGNAL(clicked()), this, SLOT(deleteClicked()));
    connect(insertButton, SIGNAL(clicked()), this, SLOT(insertClicked()));
    connect(insertValueLineEdit, SIGNAL(returnPressed()), this, SLOT(insertClicked()));
    connect(deleteValueLineEdit, SIGNAL(returnPressed()), this, SLOT(deleteClicked()));

    QHBoxLayout *buttonLayout = new QHBoxLayout;
    buttonLayout->addWidget(propertyButton);
    buttonLayout->addWidget(deleteButton);
    buttonLayout->addWidget(deleteValueLineEdit);
    buttonLayout->addWidget(insertButton);
    buttonLayout->addWidget(insertValueLineEdit);
    buttonLayout->addSpacing(25);
    buttonLayout->addWidget(statusLabel);
    buttonLayout->addStretch(0);

    renderArea = new RenderArea(this->bst);

    treeScrollArea = new QScrollArea;
    treeScrollArea->setWidget(renderArea);

    treeScrollArea->installEventFilter(renderArea);

    mainLayout = new QVBoxLayout;
    mainLayout->addWidget(treeScrollArea);
    mainLayout->addLayout(buttonLayout);

    centralWidget = new QWidget(this);
    centralWidget->setLayout(mainLayout);
    this->setCentralWidget(centralWidget);
    this->setMinimumHeight(400);
    this->setWindowTitle("Binary Search Tree Visualization");

    prop = new BST_Properties_Window();

    this->show();

}

void MainWindow::resizeEvent(QResizeEvent* event)
{
   QMainWindow::resizeEvent(event);
}

MainWindow::~MainWindow()
{
    delete renderArea;
    delete propertyButton;
    delete deleteButton;
    delete insertButton;
    delete treeScrollArea;
    delete prop;
    delete bst;
    delete centralWidget;
}

void MainWindow::createMenu()
{
    this->createActions();

    editMenu = this->menuBar()->addMenu(tr("&Edit"));
    editMenu->addAction(resetAction);
}

void MainWindow::createActions()
{
    resetAction = new QAction(tr("&Reset"), this);
    resetAction->setStatusTip("Reset the BST to be empty");
    connect(resetAction, &QAction::triggered, this, &MainWindow::resetMenu);
}

void MainWindow::closeEvent(QCloseEvent *event)
{

    QString fileName = QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation) + "/BSTVisualizer/last_bst.txt";

    QString text = bst->getPreOrderTraversal();
    QFile file(fileName);
    if (file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        QTextStream writer(&file);
        writer << text;
        writer.flush();
        file.close();
    }

    prop->closePropertyWindow();
    event->setAccepted(true);
    return;
}

void MainWindow::propertyClicked() const
{
    prop->show();
    prop->update(this->bst);
    return;
}

void MainWindow::deleteClicked() const {
    QString value = deleteValueLineEdit->text();

    if(!this->bst->deleteItem(value.toInt()))
        this->statusLabel->setText("Value is not in tree...");
    else
        this->statusLabel->setText("Value deleted.");

    this->renderArea->repaint();
    this->deleteValueLineEdit->setText("");
    return;
}

void MainWindow::insertClicked() const
{
    QString values = insertValueLineEdit->text();
    QStringList valueList = values.split(QRegExp("\\s+"), QString::SkipEmptyParts);
    QStringListIterator iterator(valueList);

    while (iterator.hasNext())
    {
        if(!this->bst->insert(iterator.next().toInt()))
            this->statusLabel->setText("Duplicate");
        else
            this->statusLabel->setText("Value inserted");
    }
    this->renderArea->repaint();
    insertValueLineEdit->setText("");
    return;
}

void MainWindow::resetMenu() const
{
    this->statusLabel->setText("Reset tree");
    this->bst->resetTree();
    this->renderArea->repaint();
    return;
}

BinarySearchTree<int>* MainWindow::getBST()
{

    BinarySearchTree<int> *bst = new BinarySearchTree<int>;

    QString fileName = QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation) + "/BSTVisualizer/last_bst.txt";

    QString text;
    QFile file(fileName);

    if (!file.exists() || !file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        return bst;
    }

    QTextStream reader(&file);

    while (!reader.atEnd())
    {
        reader >> text;
        if (text != " " && text != "")
            bst->insert(text.toInt());
    }

    file.close();
    return bst;
}
