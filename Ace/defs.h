#ifndef __INC_DEFS_H__
#define __INC_DEFS_H__

enum { WHITE, BLACK };
enum { PAWN = 1, KNIGHT, BISHOP, ROOK, QUEEN, KING };

typedef struct {
	int piece_value;    // 1=pawn ... 6=king
	int piece_location; // where the piece is on the board
} piece_entry;

typedef struct {
	int from; // from square
	int to; // to square
	int halfmove;
} history_entry;

#endif