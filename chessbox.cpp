#include "chessbox.h"
#include "game.h"
#include <QDebug>

extern Game *game;
ChessBox::ChessBox(QGraphicsItem *parent):QGraphicsRectItem(parent)
{
    setRect(0,0,100,100);
    brush.setStyle(Qt::SolidPattern);
    setZValue(-1);
    setHasChessPiece(false);
    setChessPieceColor("NONE");
    currentPiece = NULL;
}

ChessBox::~ChessBox()
{
    delete this;
}

void ChessBox::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(currentPiece == game->pieceToMove && currentPiece){
        currentPiece->mousePressEvent(event);
        return;
    }
    if(game->pieceToMove){
        if(this->getChessPieceColor() == game->pieceToMove->getSide())
            return;
        QList <ChessBox *> movLoc = game->pieceToMove->moveLocation();
        int check = 0;
        for(size_t i = 0, n = movLoc.size(); i < n;i++) {
            if(movLoc[i] == this) {
                check++;
            }
        }
        if(check == 0)
            return;
        game->pieceToMove->decolor();
        game->pieceToMove->firstMove = false;
        if(this->getHasChessPiece()){
            this->currentPiece->setIsPlaced(false);
            this->currentPiece->setCurrentBox(NULL);
            game->placeInDeadPlace(this->currentPiece);

        }
        game->pieceToMove->getCurrentBox()->setHasChessPiece(false);
        game->pieceToMove->getCurrentBox()->currentPiece = NULL;
        game->pieceToMove->getCurrentBox()->resetOriginalColor();
        placePiece(game->pieceToMove);
        game->pieceToMove = NULL;
        game->changeTurn();
    }
    else if(this->getHasChessPiece())
    {
        this->currentPiece->mousePressEvent(event);
    }
}

void ChessBox::setColor(QColor color)
{
    brush.setColor(color);
    setBrush(color);
}

void ChessBox::placePiece(ChessPiece *piece)
{

    piece->setPos(x()+50- piece->pixmap().width()/2  ,y()+50-piece->pixmap().width()/2);
    piece->setCurrentBox(this);
    setHasChessPiece(true,piece);
    currentPiece = piece;


}

void ChessBox::resetOriginalColor()
{
    setColor(originalColor);
}



void ChessBox::setOriginalColor(QColor value)
{
    originalColor = value;
    setColor(originalColor);
}

bool ChessBox::getHasChessPiece()
{
    return hasChessPiece;
}

void ChessBox::setHasChessPiece(bool value, ChessPiece *piece)
{
    hasChessPiece = value;
    if(value)
        setChessPieceColor(piece->getSide());
    else
        setChessPieceColor("NONE");
}

QString ChessBox::getChessPieceColor()
{
    return chessPieceColor;
}

void ChessBox::setChessPieceColor(QString value)
{
    chessPieceColor = value;
}
