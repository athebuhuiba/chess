#include "pawn.h"
#include "game.h"
#include <QDebug>
#include "king.h"
#include "chessboard.h"
#include "chessbox.h"
#include "game.h"
#include "queen.h"
#include "rook.h"
#include "knight.h"
#include "bishop.h"
extern Game * game;
Pawn::Pawn(QString team,QGraphicsItem *parent):ChessPiece(team,parent)
{
    setImage();
    firstMove = true;
}

void Pawn::setImage()
{
    if(side == "白方")
        setPixmap(QPixmap(":/wp.png"));
    else
        setPixmap(QPixmap(":/bp.png"));
}
void Pawn::moves()
{
    location.clear();

    int row = this->getCurrentBox()->rowLoc;

    int col = this->getCurrentBox()->colLoc;
    if(this->getSide() == "白方")  {
        if(col > 0 && row > 0 && game->collection[row-1][col-1]->getChessPieceColor() == "黑方") {
            location.append(game->collection[row-1][col-1]);
            boxSetting(location.last());
        }
        if(col < 7 && row > 0 && game->collection[row-1][col+1]->getChessPieceColor() == "黑方") {
            location.append(game->collection[row-1][col+1]);
            boxSetting(location.last());
        }
        if(row>0 && (!game->collection[row-1][col]->getHasChessPiece())) {
            location.append(game->collection[row-1][col]);
            boxSetting(location.last());
            if(firstMove && !game->collection[row-2][col]->getHasChessPiece()){
                location.append(game->collection[row-2][col]);
                boxSetting(location.last());
            }
        }


    }
    else{
        if(col > 0 && row < 7 && game->collection[row+1][col-1]->getChessPieceColor() == "白方") {//left
            location.append(game->collection[row+1][col-1]);
            boxSetting(location.last());
        }
        if(col < 7 && row <  7 && game->collection[row+1][col+1]->getChessPieceColor() == "白方") {//right
            location.append(game->collection[row+1][col+1]);
            boxSetting(location.last());
        }
        if(row<7 && (!game->collection[row+1][col]->getHasChessPiece())) {
            location.append(game->collection[row+1][col]);
            boxSetting(location.last());
            if(firstMove && !game->collection[row+2][col]->getHasChessPiece()){
                location.append(game->collection[row+2][col]);
                boxSetting(location.last());
            }

        }

    }

}
