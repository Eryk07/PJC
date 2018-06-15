#include "CProgram.h"
#include <QGraphicsView>
#include <QRandomGenerator>

CProgram::CProgram()
{
    QGraphicsScene *scene = new QGraphicsScene();
    scene->setSceneRect(-map_border/2, -map_border/2, map_border, map_border);
    scene->setItemIndexMethod(QGraphicsScene::NoIndex);

    CMap *m = new CMap(scene);
    map = m;

    QGraphicsView *view = new QGraphicsView(scene);

    view->setRenderHint(QPainter::Antialiasing);
    view->setCacheMode(QGraphicsView::CacheBackground);
    view->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
    view->setDragMode(QGraphicsView::RubberBandDrag);

    view->setFixedWidth(map_border);
    view->setFixedHeight(map_border);
   // view->autoFillBackground();
    view->setBackgroundBrush(QPixmap::fromImage(QImage(":/parkiet.jpg")));

    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setWindowTitle(QT_TRANSLATE_NOOP(QGraphicsView, "Liszaj"));
    view->show();

    QTimer *timer = new QTimer;
    connect(timer, SIGNAL(timeout()), this, SLOT(step()));
    timer->start(50);
}

void CProgram::step()
{
    for(unsigned int i=0; i<map->ObjectList.size(); i++)
    {
        map->ObjectList.at(i)->update();
    }
    for(unsigned int i=0; i<map->GObjectList.size(); i++)
    {
        map->GObjectList.at(i)->updateG();
    }
}
