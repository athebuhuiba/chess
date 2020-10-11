#include "knight.h"
#include "game.h"
extern Game *game;

Knight::Knight(QString team,QGraphicsItem *parent):ChessPiece(team,parent)
{
    setImage();
}

void Knight::setImage()
{
    if(side == "白方")
        setPixmap(QPixmap(":/wkn.png"));
    else
        setPixmap(QPixmap(":/bkn.png"));
}
void Knight::moves()
{
    int row = this->getCurrentBox()->rowLoc;
    int col = this->getCurrentBox()->colLoc;
    int i ,j;
    QString team  = this->getSide();
    i = row - 2;
    j = col - 1;
    if(i >=0 && j>=0 && (game->collection[i][j]->getChessPieceColor() != team) ) {
        location.append(game->collection[i][j]);
        if(location.last()->getHasChessPiece())
            location.last()->setColor(Qt::green);
        else
            location.last()->setColor(Qt::darkGreen);
    }
    i = row - 2;
    j = col + 1;
    if(i >=0 && j<=7 && (game->collection[i][j]->getChessPieceColor() != team) ) {
        location.append(game->collection[i][j]);
        if(location.last()->getHasChessPiece())
            location.last()->setColor(Qt::green);
        else
            location.last()->setColor(Qt::darkGreen);
    }
    i = row + 2;
    j = col - 1;
    if(i <= 7 && j>=0 && (game->collection[i][j]->getChessPieceColor() != team) ) {
        location.append(game->collection[i][j]);
        if(location.last()->getHasChessPiece())
            location.last()->setColor(Qt::green);
        else
            location.last()->setColor(Qt::darkGreen);
    }
    i = row + 2;
    j = col + 1;
    if(i <=7 && j<=7 && (game->collection[i][j]->getChessPieceColor() != team) ) {
        location.append(game->collection[i][j]);
        if(location.last()->getHasChessPiece())
            location.last()->setColor(Qt::green);
        else
            location.last()->setColor(Qt::darkGreen);
    }
    i = row - 1;
    j = col - 2;
    if(i >=0 && j>=0 && (game->collection[i][j]->getChessPieceColor() != team) ) {
        location.append(game->collection[i][j]);
        if(location.last()->getHasChessPiece())
            location.last()->setColor(Qt::green);
        else
            location.last()->setColor(Qt::darkGreen);
    }
    i = row + 1;
    j = col - 2;
    if(i <=7 && j>=0 && (game->collection[i][j]->getChessPieceColor() != team) ) {
        location.append(game->collection[i][j]);
        if(location.last()->getHasChessPiece())
            location.last()->setColor(Qt::green);
        else
            location.last()->setColor(Qt::darkGreen);
    }
    i = row - 1;
    j = col + 2;
    if(i >=0 && j<=7 && (game->collection[i][j]->getChessPieceColor() != team) ) {
        location.append(game->collection[i][j]);
        if(location.last()->getHasChessPiece())
            location.last()->setColor(Qt::green);
        else
            location.last()->setColor(Qt::darkGreen);
    }
    i = row + 1;
    j = col +  2;
    if(i <=7 && j<=7 && (game->collection[i][j]->getChessPieceColor() != team) ) {
        location.append(game->collection[i][j]);
        if(location.last()->getHasChessPiece())
            location.last()->setColor(Qt::green);
        else
            location.last()->setColor(Qt::darkGreen);
    }
}
