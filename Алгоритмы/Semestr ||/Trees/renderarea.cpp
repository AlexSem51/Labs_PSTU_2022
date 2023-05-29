#include "renderarea.h"
#include <QApplication>
#include <QPainter>
#include <qglobal.h>
#include <QTime>
#include <QPen>

RenderArea::RenderArea(BinarySearchTree<int> *bst, QWidget *parent) : QWidget(parent), bst(),
    scale(1.0)
{
    this->bst = bst;
    this->scale = 1;

    this->nodeColor = Qt::red;
    this->backgroundColor = Qt::white;
    this->textColor = Qt::black;
}

QSize RenderArea::sizeHint() const
{
    return QSize(50, 50);
}

QSize RenderArea::minimumSizeHint() const
{
    return QSize(50, 50);
}

void RenderArea::paintEvent(QPaintEvent *)
{
    if (this->bst->isEmpty())
        return;
    QPainter painter(this);

    painter.setRenderHint(QPainter::Antialiasing);

    QBrush brush;
    brush.setColor(this->nodeColor);
    brush.setStyle(Qt::SolidPattern);
    QPen pen;
    pen.setColor(this->textColor);

    painter.setBrush(brush);
    painter.setPen(pen);

    this->bst->draw(&painter, this->scale);

    this->autoSize();
}

QColor RenderArea::getNodeColor() const
{
    return this->nodeColor;
}

QColor RenderArea::getBackgroundColor() const
{
    return this->backgroundColor;
}

QColor RenderArea::getTextColor() const
{
    return this->textColor;
}

void RenderArea::autoSize() {
    QSize size(bst->getTotalX(), bst->getTotalY());
    this->setMinimumSize(size);
    this->resize(size);
}
