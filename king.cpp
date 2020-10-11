#include "king.h"
#include "game.h"

extern Game *game;
King::King(QString team,QGraphicsItem *parent):ChessPiece(team,parent)
{
    setImage();
}

void King::setImage()
{
    if(side == "白方")
        setPixmap(QPixmap(":/wk.png"));
    else
        setPixmap(QPixmap(":/bk.png"));
}


void King::moves()
{
    game->check->setVisible(false);
    location.clear();
    int row = this->getCurrentBox()->rowLoc;
    int col = this->getCurrentBox()->colLoc;
    QString team = this->getSide();

    if(col > 0 && row > 0 && !(game->collection[row-1][col-1]->getChessPieceColor() == team)) {//up left
        location.append(game->collection[row-1][col-1]);
        game->collection[row-1][col-1]->setColor(Qt::darkGreen);
        if(location.last()->getHasChessPiece()){
            location.last()->setColor(Qt::green);
        }
    }
    if(col < 7 && row > 0 && !(game->collection[row-1][col+1]->getChessPieceColor() == team)) { // up right
        location.append(game->collection[row-1][col+1]);
        game->collection[row-1][col+1]->setColor(Qt::darkGreen);
        if(location.last()->getHasChessPiece()){
            location.last()->setColor(Qt::green);
        }
    }
    if(row>0 && !(game->collection[row-1][col]->getChessPieceColor() == team)) {//up
        location.append(game->collection[row-1][col]);
        game->collection[row-1][col]->setColor(Qt::darkGreen);
        if(location.last()->getHasChessPiece()){
            location.last()->setColor(Qt::green);
        }
    }
    if(row<7 && !(game->collection[row+1][col]->getChessPieceColor() == team)) {//down
        location.append(game->collection[row+1][col]);
        game->collection[row+1][col]->setColor(Qt::darkGreen);
        if(location.last()->getHasChessPiece()){
            location.last()->setColor(Qt::green);
        }
    }
    if(col>0 && !(game->collection[row][col-1]->getChessPieceColor() == team)) {// left
        location.append(game->collection[row][col-1]);
        game->collection[row][col-1]->setColor(Qt::darkGreen);
        if(location.last()->getHasChessPiece()){
            location.last()->setColor(Qt::green);
        }
    }
    if(col<7 && !(game->collection[row][col+1]->getChessPieceColor() == team)) {//right
        location.append(game->collection[row][col+1]);
        game->collection[row][col+1]->setColor(Qt::darkGreen);
        if(location.last()->getHasChessPiece()){
            location.last()->setColor(Qt::green);
        }
    }
    if(col > 0 && row < 7  && !(game->collection[row+1][col-1]->getChessPieceColor() == team)) {//down left
        location.append(game->collection[row+1][col-1]);
        game->collection[row+1][col-1]->setColor(Qt::darkGreen);
        if(location.last()->getHasChessPiece()){
            location.last()->setColor(Qt::green);
        }
    }
    if(col < 7 && row < 7 && !(game->collection[row+1][col+1]->getChessPieceColor() == team)) {//down right
        location.append(game->collection[row+1][col+1]);
        game->collection[row+1][col+1]->setColor(Qt::darkGreen);
        if(location.last()->getHasChessPiece()){
            location.last()->setColor(Qt::green);
        }
    }
}
