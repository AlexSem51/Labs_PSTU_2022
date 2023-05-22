#ifndef VERTEX_H
#define VERTEX_H

#include <graph.h>

#include <QMainWindow>
#include <QGraphicsItem>
#include <QVector>
#include <QPointF>
#include <QGraphicsView>
#include <QWidget>
#include <QStyleOptionGraphicsItem>
#include <QKeyEvent>

class vertex;
class Edge;
class Graph;

class Vertex : public QGraphicsItem {
public:

    Vertex(Graph *graph, int index);
    ~Vertex();
    void addEdge(Edge* edge);
    QVector<Edge *> getEdges() const;

    void calculateForces();
    bool advancePosition();

    QString getColor();
    void setColor(QString color);
    int getDegree();
    int getIndex();
    void setIndex(int index);
    QString getName();
    void setName(QString name);
    void setPosition(double xvel, double yvel);
    void insertEdge(int dest, double weight);
    bool pathExist(int dest);
    void updateWeight(int dest, double weight);
    void eraseEdge(int dest);
    void clearEdge();
    void changeEdgeColor(int dest);
    QPointF getPos();

    QRectF boundingRect() const override;
    QPainterPath shape() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;


protected:
    QVariant itemChange(GraphicsItemChange change, const QVariant &value) override;

    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;

private:
    int vertexIndex;
    QString name;
    int degree;
    QVector<Edge *> edgeList;
    QPointF newPos;
    Graph *graph;
    QString color;
};

#endif // VERTEX_H
