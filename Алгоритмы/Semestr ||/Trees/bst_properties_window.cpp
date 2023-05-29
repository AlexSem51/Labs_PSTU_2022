#include "bst_properties_window.h"
#include <iostream>
#include <QScrollArea>
#include <QHBoxLayout>

BST_Properties_Window::BST_Properties_Window(QWidget *parent) : QMainWindow(parent)
{
    this->setWindowTitle("Properties");
    this->setFixedSize(QSize(400, 650));

    labelLayout = new QVBoxLayout;
    heightLabel = new QLabel("Height:");
    nodeCountLabel = new QLabel("Node count:");
    leafNodesLabel = new QLabel("Leaf nodes:");
    internalNodesLabel = new QLabel("Internal nodes:");
    heightLabel->setStyleSheet("font-size: 14px;");
    nodeCountLabel->setStyleSheet("font-size: 14px;");
    leafNodesLabel->setStyleSheet("font-size: 14px;");
    internalNodesLabel->setStyleSheet("font-size: 14px;");

    labelLayout->addWidget(heightLabel);
    labelLayout->addWidget(nodeCountLabel);
    labelLayout->addWidget(leafNodesLabel);
    labelLayout->addWidget(internalNodesLabel);

    textAreaLayout = new QVBoxLayout;
    heightValue = new QLineEdit("");
    nodeCountValue = new QLineEdit("");
    leafNodesValue = new QLineEdit("");
    internalNodesValue = new QLineEdit("");
    heightValue->setReadOnly(true);
    nodeCountValue->setReadOnly(true);
    leafNodesValue->setReadOnly(true);
    internalNodesValue->setReadOnly(true);

    heightValue->setStyleSheet("color: black; width: 100px;"
                               "padding-left: 10px; font-size: 14px;");
    nodeCountValue->setStyleSheet("color: black; width: 100px;"
                                  "padding-left: 10px; font-size: 14px;");
    leafNodesValue->setStyleSheet("color: black; width: 100px;"
                                  "padding-left: 10px; font-size: 14px;");
    internalNodesValue->setStyleSheet("color: black; width: 100px;"
                                      "padding-left: 10px; font-size: 14px;");

    textAreaLayout->addWidget(heightValue);
    textAreaLayout->addWidget(nodeCountValue);
    textAreaLayout->addWidget(leafNodesValue);
    textAreaLayout->addWidget(internalNodesValue);

    containerLayout = new QHBoxLayout;
    containerLayout->addLayout(labelLayout);
    containerLayout->addLayout(textAreaLayout);


    preOrderTraversal = new QTextEdit;
    inOrderTraversal = new QTextEdit;
    postOrderTraversal = new QTextEdit;
    breadthFirstTraversal = new QTextEdit;
    find_element=new QTextEdit;
    finD=new QLineEdit;
    preOrderTraversal->setReadOnly(true);
    inOrderTraversal->setReadOnly(true);
    postOrderTraversal->setReadOnly(true);
    breadthFirstTraversal->setReadOnly(true);
    find_element->setReadOnly(true);

    exitButton = new QPushButton("E&xit", this);
    connect(exitButton, SIGNAL(clicked()), this, SLOT(exitSlot()));
    findButton=new QPushButton("F&ind", this);

    QHBoxLayout *buttonLayout = new QHBoxLayout;
    buttonLayout->addStretch(0);
    buttonLayout->addWidget(exitButton);
    buttonLayout->addStretch(3);
    buttonLayout->addWidget(findButton);
    buttonLayout->addWidget(finD);

    mainLayout = new QVBoxLayout;
    mainLayout->addLayout(containerLayout);
    mainLayout->addWidget(new QLabel("Preorder Traversal:"));
    mainLayout->addWidget(preOrderTraversal);
    mainLayout->addWidget(new QLabel("Inorder Traversal:"));
    mainLayout->addWidget(inOrderTraversal);
    mainLayout->addWidget(new QLabel("Postorder Traversal:"));
    mainLayout->addWidget(postOrderTraversal);
    mainLayout->addWidget(new QLabel("Breadthfirst Traversal"));
    mainLayout->addWidget(breadthFirstTraversal);
    mainLayout->addWidget(new QLabel("Searching for an element by key"));
    mainLayout->addWidget(find_element);
    mainLayout->addLayout(buttonLayout);

    centralWidget = new QWidget(this);
    centralWidget->setLayout(mainLayout);

    this->setCentralWidget(centralWidget);
}

BST_Properties_Window::~BST_Properties_Window(){
    delete heightLabel;
    delete heightValue;
    delete nodeCountLabel;
    delete nodeCountValue;
    delete leafNodesLabel;
    delete leafNodesValue;
    delete internalNodesLabel;
    delete internalNodesValue;
    delete labelLayout;
    delete textAreaLayout;
    delete containerLayout;
    delete preOrderTraversal;
    delete inOrderTraversal;
    delete postOrderTraversal;
    delete breadthFirstTraversal;
    delete exitButton;
    delete mainLayout;
    delete centralWidget;
}

void BST_Properties_Window::closePropertyWindow()
{
    this->close();
    return;
}

void BST_Properties_Window::update(BinarySearchTree<int> *bst)
{
    this->heightValue->setText(QString::number(bst->getTreeHeight()));
    this->nodeCountValue->setText(QString::number(bst->getNodeCount()));
    this->leafNodesValue->setText(QString::number(bst->getLeafNodeCount()));
    this->internalNodesValue->setText(QString::number(bst->getNodeCount() - bst->getLeafNodeCount()));
    this->preOrderTraversal->setText(bst->getPreOrderTraversal());
    this->inOrderTraversal->setText(bst->getInOrderTraversal());
    this->postOrderTraversal->setText(bst->getPostOrderTraversal());
    this->breadthFirstTraversal->setText(bst->getBreadthFirstSearch());
    return;
}


void BST_Properties_Window::show()
{
    this->setVisible(true);
    this->activateWindow();
    return;
}

void BST_Properties_Window::exitSlot()
{
    this->close();
    return;
}
