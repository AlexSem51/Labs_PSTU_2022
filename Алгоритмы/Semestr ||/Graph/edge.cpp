#include "vertex.h"
#include "edge.h"
#include "graph.h"

#include <QtMath>


#define M_PI 3.1415926



Edge::Edge(Vertex *source, Vertex *dest, double weight){
    this->source = source;
    this->dest = dest;
    setAcceptedMouseButtons(Qt::NoButton);
    source->addEdge(this);
    this->weight = weight;
    color = "whtie";
    adjust();
}

Edge::~Edge(){

}

Vertex *Edge::sourceVertex() const{
    return source;
}

Vertex *Edge::destVertex() const{
    return dest;
}

void Edge::adjust(){
    if(!source || !dest){
        return;
    }
    QLineF line(mapFromItem(source, 0, 0), mapFromItem(dest, 0, 0));
    qreal length = line.length();
    prepareGeometryChange();

    if(length > qreal(20.)){
        QPointF edgeOffset((line.dx() * 10) / length, (line.dy() * 10) / length);
        sourcePoint = line.p1() + edgeOffset;
        destPoint = line.p2() - edgeOffset;
    } else {
        sourcePoint = destPoint = line.p1();
    }
}

QRectF Edge::boundingRect() const{
    if(!source || !dest){
        return QRectF();
    }
    qreal penWidth = 1;
    qreal extra = (penWidth + arrowSize) / 2.0;
    return QRectF(sourcePoint, QSizeF(destPoint.x() - sourcePoint.x(), destPoint.y() - sourcePoint.y())).normalized().adjusted(-extra, -extra, extra, extra);
}

void Edge::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *){
    if(!source || !dest){
        return;
    }
    QLineF line(sourcePoint, destPoint);
    if(qFuzzyCompare(line.length(), qreal(0.))){
        return;
    }

    double angle = std::atan2(-line.dy(), line.dx());
    QPointF destArrowP1 = destPoint + QPointF(sin(angle - M_PI / 3) * arrowSize, cos(angle - M_PI / 3) * arrowSize);
    QPointF destArrowP2 = destPoint + QPointF(sin(angle - M_PI + M_PI / 3) * arrowSize, cos(angle - M_PI + M_PI / 3) * arrowSize);


    if(color == "white"){
        painter->setBrush(Qt::black);
        painter->setPen(QPen(Qt::black, 1, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
    }
    else if(color == "black"){
        painter->setBrush(Qt::red);
        painter->setPen(QPen(Qt::red, 1, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
    }
    painter->drawLine(line);
    painter->drawPolygon(QPolygonF() << line.p2() << destArrowP1 << destArrowP2);

    painter->drawText(QRectF(QPointF(sourcePoint.x() - 15, sourcePoint.y() - 15), QPointF(destPoint.x() + 15, destPoint.y() + 15)), Qt::AlignCenter, QString::number(weight));
}

double Edge::getWeight(){
    return weight;
}

void Edge::setWeight(double w){
    weight = w;
}

QString Edge::getColor(){
    return color;
}

void Edge::setColor(QString color){
    this -> color = color;
    qApp->processEvents();
    update();
}
