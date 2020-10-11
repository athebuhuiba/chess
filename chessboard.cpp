#include "chessboard.h"
#include "chessbox.h"
#include "game.h"
#include "queen.h"
#include "rook.h"
#include "pawn.h"
#include "king.h"
#include "knight.h"
#include "bishop.h"
extern Game *game;
ChessBoard::ChessBoard()
{
    setUpBlack();
    setUpWhite();
}
void ChessBoard::drawBoxes(int x,int y)
{
    int SHIFT = 100;
    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 8; j++)
        {
            ChessBox *box = new ChessBox();
            game->collection[i][j] = box;
            box->rowLoc = i;
            box->colLoc = j;
            box->setPos(x+SHIFT*j,y+SHIFT*i);
            if((i+j)%2==0)
                box->setOriginalColor(Qt::white);
            else
                box->setOriginalColor(Qt::lightGray);
            game->addToScene(box);
        }
    }
}


void ChessBoard::addChessPiece() {
    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 8; j++)
        {

            ChessBox *box =game->collection[i][j];
            if(i < 2) {
                static int k;
                box->placePiece(black[k]);
                game->addToScene(black[k++]);
            }
            if(i > 5) {
                static int h;
                box->placePiece(white[h]);
                game->addToScene(white[h++]);
            }

        }
    }
}

void ChessBoard::setUpWhite()
{
    ChessPiece *piece;
    for(int i = 0; i < 8; i++) {
        piece = new Pawn("白方");
        white.append(piece);
    }
    piece = new Rook("白方");
    white.append(piece);
    piece = new Knight("白方");
    white.append(piece);
    piece = new Bishop("白方");
    white.append(piece);
    piece = new Queen("白方");
    white.append(piece);
    piece = new King("白方");
    white.append(piece);
    piece = new Bishop("白方");
    white.append(piece);
    piece = new Knight("白方");
    white.append(piece);
    piece = new Rook("白方");
    white.append(piece);
}
void ChessBoard::setUpBlack()
{
    ChessPiece *piece;
    piece = new Rook("黑方");
    black.append(piece);
    piece = new Knight("黑方");
    black.append(piece);
    piece = new Bishop("黑方");
    black.append(piece);
    piece = new Queen("黑方");
    black.append(piece);
    piece = new King("黑方");
    black.append(piece);
    piece = new Bishop("黑方");
    black.append(piece);
    piece = new Knight("黑方");
    black.append(piece);
    piece = new Rook("黑方");
    black.append(piece);
    for(int i = 0; i < 8; i++) {
        piece = new Pawn("黑方");
        black.append(piece);
    }
}
