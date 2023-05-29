#ifndef RENDERAREA_H
#define RENDERAREA_H

#include <QWidget>
#include <QPen>
#include <QBrush>
#include <QMouseEvent>
#include "binarysearchtree.h"
#include <QColor>

class RenderArea : public QWidget
{
    Q_OBJECT
public:
    explicit RenderArea(BinarySearchTree<int> *bst, QWidget *parent = 0);

    QSize minimumSizeHint() const override;
    QSize sizeHint() const override;
    void autoSize();
    QColor getNodeColor() const;
    QColor getBackgroundColor() const;
    QColor getTextColor() const;

signals:

public slots:

protected:
    void paintEvent(QPaintEvent *event) override;
private:
    BinarySearchTree<int> *bst;
    double scale;
    QPen pen;
    QBrush brush;
    QColor backgroundColor;
    QColor nodeColor;
    QColor textColor;

};

#endif // RENDERAREA_H
