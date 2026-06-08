#pragma once
#include <cstdint>

#define whitePawn = 0;
#define whiteKing = 1;
#define whiteQueen = 2;
#define whiteBishop = 3;
#define whiteHorse = 4;
#define whiteRook = 5;
#define blackPawn = 6;
#define blackKing = 7;
#define blackQueen = 8;
#define blackBishop = 9;
#define blackHorse = 10;
#define blackRook = 11;
#define empty = 12;

class chessBoard{
public:

    // gets a piece then sets it to a specific square
    uint8_t getPiece(std::uint8_t square);
    void setPiece(std::uint8_t piece, std::uint8_t square);

    chessBoard(); //constructor
    
private:

    // stores bitmap for every piece
    uint64_t chessboards[12];
};