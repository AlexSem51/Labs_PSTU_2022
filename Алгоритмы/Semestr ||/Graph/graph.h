#ifndef GRAPH_H
#define GRAPH_H

#include <vertex.h>
#include <edge.h>

#include <ctime>
#include <climits>
#include <iomanip>

#include <QMainWindow>
#include <QGraphicsItem>
#include <QVector>
#include <QStack>
#include <QQueue>
#include <QPointF>
#include <QGraphicsView>
#include <QWidget>
#include <QStyleOptionGraphicsItem>
#include <QKeyEvent>
#include <QPushButton>
#include <QHBoxLayout>
#include <QStyle>
#include <QDialog>
#include <QLineEdit>
#include <QLabel>
#include <QWidget>
#include <QTableWidget>
#include <QApplication>
#include <QGroupBox>
#include <QToolButton>
#include <QMenu>
#include <QDir>
#include <QSaveFile>
#include <QFileDialog>


#include <windows.h>
#include <conio.h>
#include <process.h>
#include "Psapi.h"
#include <TlHelp32.h>
#include <assert.h>
#include <stdio.h>
#include <sstream>

class vertex;
class Edge;
class Graph;


#define M INT_MAX

class Graph : public QGraphicsView {
    Q_OBJECT

public:
    Graph(QWidget *parent = nullptr);
    void itemMoved();
    int getVertexNum();

protected:
    void timerEvent(QTimerEvent *event) override;

    void drawBackground(QPainter *painter, const QRectF &rect) override;
    void createTabWidget(const QRectF &rect);
    void createMenuBar();
    void scaleView(qreal scaleFactor);

    void updateIndex();
    void insertVertex();
    void setVertexPos(int vertexIndex, double x, double y);
    void eraseVertex(int vertexIndex);
    void insertEdge(int source, int dest, double weight);
    void updateWeight(int source, int dest, double weight);
    void eraseEdge(int source, int dest);
    bool checkAdjacent(int source, int dest);
    int getDegree(int vertexIndex);
    void clear();
    void checkConnected();

    void reset();

    void getVertexInfo(int vertexIndex);
    void getGraphInfo();

    void dfsUtil(int vertexIndex, QVector<bool> &visited);
    void dfs(int vertexIndex);

    void bfsUtil(int vertexIndex, QVector<bool> &visited);
    void bfs(int vertexIndex);

    void delay(int time);

    void createEraseVertexWindow();
    void createSetVertexPosWindow();
    void createVertexInfoWindow();
    void createAddEdgeWindow();
    void createEraseEdgeWindow();
    void createUpdateWeightWindow();
    void createDFSWindow();
    void createBFSWindow();
    void createDijkstraWindow();

private slots:
    void eraseVertexSignal();
    void setVertexPosSignal();
    void vertexInfoSignal();
    void addEdgeSignal();
    void eraseEdgeSignal();
    void updateWeightSignal();
    void dfsSignal();
    void bfsSignal();
    int dijkstraSignal();

private:
    unsigned int edgeNum=0;
    int vertexNum;
    bool connected;

    QVector<int> DFS;
    QVector<int> BFS;
    QVector<int> dijkstra(int);

    QVector<Vertex *> vertexList;
    QGraphicsScene *scene;
    int timerId = 0;

    QWidget *window;
    QLineEdit *input1;
    QLineEdit *input2;
    QLineEdit *input3;

    QString curFile;

};

#endif // GRAPH_H
