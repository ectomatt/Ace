#ifndef __INC_BOARD_H__
#define __INC_BOARD_H__

#include <string>
using namespace std;

void print_board();
void init_board();
void empty_board();
void add_piece(int side, int piece, int location, int index);
void parse_FEN(string fen);

#endif