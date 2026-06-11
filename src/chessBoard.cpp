#include <ChessBoard.h>
#include <cstdint>

// constructor
ChessBoard::ChessBoard()
{
	bitboards[whitePawn] = 0x000000000000FF00;
	bitboards[whiteBishop] = 0x0000000000000024;
	bitboards[whiteKnight] = 0x0000000000000042;
	bitboards[whiteQueen] = 0x0000000000000010;
	bitboards[whiteKing] = 0x0000000000000008;
	bitboards[whiteRook] = 0x0000000000000081;

	bitboards[blackPawn] = 0x00ff000000000000;
	bitboards[blackBishop] = 0x2400000000000000;
	bitboards[blackKnight] = 0x4200000000000000;
	bitboards[blackQueen] = 0x1000000000000000;
	bitboards[blackRook] = 0x8100000000000000;
}

// gets the piece from a selected square
uint8_t ChessBoard::getPiece(std::uint8_t square){
	uint64_t mask = uint64_t(1) << square;
	
	for(int i = 0; i < 12; i++){
		if(bitboards[i] & mask){
			return 1;
		}
	}
	
	return empty;
}

// puts a piece on a square/tile
void ChessBoard::setPiece(uint8_t piece, uint8_t square){
	uint64_t mask = uint64_t(1) << square;
	
	bitboards[piece] |= mask;
	
	for(int i = 0; i < 12; i++){
		if(i != piece){
			bitboards[i] &= ~mask;
		}
	}
}
