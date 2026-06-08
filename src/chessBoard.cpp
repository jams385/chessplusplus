#include <chessBoard.h>
#include <cstdint>

// gets the piece from a selected square
int8_t chessBoard::getPiece(std::uint8_t square){
	uint64_t mask = uint64_t(1) << square;
	
	for(int i = 0; i < 12; i++){
		if(bitboard[i] & mask){
			return 1;
		}
	}
	
	return EMPTY;
}

// puts a piece on a square/tile
void chessBoard::setPiece(uint8_t piece, uint8_t square){
	uint64_t mask = uint64_t(1) << square;
	
	bitboards[piece] |= mask;
	
	for(int i = 0; i < 12; i++){
		if(i != piece){
			bitboards[i] &= ~mask;
		}
	}
}


Chessboard::chessBoard()
{
	bitboards[WHITE_PAWN]   = 0x00ff000000000000;
	bitboards[WHITE_KNIGHT] = 0x2400000000000000;
	bitboards[WHITE_BISHOP] = 0x4200000000000000;
	bitboards[WHITE_ROOK]   = 0x8100000000000000;
	bitboards[WHITE_QUEEN]  = 0x0800000000000000;
	bitboards[WHITE_KING]   = 0x1000000000000000;
	bitboards[BLACK_PAWN]   = 0x000000000000ff00;
	bitboards[BLACK_KNIGHT] = 0x0000000000000024;
	bitboards[BLACK_BISHOP] = 0x0000000000000042;
	bitboards[BLACK_ROOK]   = 0x0000000000000081;
	bitboards[BLACK_QUEEN]  = 0x0000000000000008;
	bitboards[BLACK_KING]   = 0x0000000000000010;
}