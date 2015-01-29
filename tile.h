#ifndef TILE_H
#define TILE_H

#include <QGraphicsItem>

class Tile : public QGraphicsPixmapItem
{
public:
    Tile();
    ~Tile();
private:
    int x;
    int y;
    QString type;

};

#endif // TILE_H
