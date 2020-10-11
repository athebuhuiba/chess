#include "bishop.h"
#include <QDebug>
#include "game.h"
extern Game *game;

Bishop::Bishop(QString team,QGraphicsItem *parent):ChessPiece(team,parent)
{
    setImage();
}

void Bishop::setImage()
{
    if(side == "白方")
        setPixmap(QPixmap(":/wb.png"));
    else
        setPixmap(QPixmap(":/bb.png"));
}


void Bishop::moves()
{
    location.clear();
    int row = this->getCurrentBox()->rowLoc;
    int col = this->getCurrentBox()->colLoc;
    QString team = this->getSide();
    //For upper Left
    for(int i = row-1,j = col-1; i >= 0 && j >=0; i--,j--) {
        if(game->collection[i][j]->getChessPieceColor() == team ) {
            break;
        }else{
            location.append(game->collection[i][j]);
            if(boxSetting(location.last()) ){
                break;
            }
        }
    }

    //For upper right
    for(int i = row-1,j = col+1; i >= 0 && j <= 7; i--,j++) {
        if(game->collection[i][j]->getChessPieceColor() == team ) {
            break;
        }
        else
        {
            location.append(game->collection[i][j]);
            if(boxSetting(location.last())){
                break;
            }
        }
    }
    for(int i = row+1,j = col+1; i <= 7 && j <= 7; i++,j++) {
        if(game->collection[i][j]->getChessPieceColor() == team ) {
            break;
        }
        else
        {
            location.append(game->collection[i][j]);
            if(boxSetting(location.last())){
                break;
            }
        }
    }
    for(int i = row+1,j = col-1; i <= 7 && j >= 0; i++,j--) {
        if(game->collection[i][j]->getChessPieceColor() == team ) {
            break;
        }
        else
        {
            location.append(game->collection[i][j]);
            if(boxSetting(location.last())){
                break;
            }
        }
    }
}
