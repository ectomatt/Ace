#include <stdio.h>
#include <string>
#include <regex>
#include <ctype.h>
#include <vector>

#include "board.h"
#include "defs.h"

using namespace std;

vector<piece_entry> white_pieces;
vector<piece_entry> black_pieces;
int piece_locations[64];

void print_board() {

}

void init_board() {
	parse_FEN("rnbqkbnr/pppppppp/8/8/4P3/8/PPPP1PPP/RNBQKBNR b KQkq e3 0 1");
}

void empty_board() {
	white_pieces.clear();
	black_pieces.clear();
}

void add_piece(int side, int piece, int location) {
	
	piece_entry data;
	data.piece_location = location;

	if (side == WHITE) {
		data.piece_value = piece;
		white_pieces.push_back(data);
	}
	else {
		data.piece_value = -piece;
		black_pieces.push_back(data);
	}
}

void parse_FEN(string fen) {
	
	smatch sm;
	empty_board();

	if (regex_match(fen, sm, regex("([pnbrqkPNBRQK1-8\\/]+)\\s+([wb])\\s+([KQkq-]+)\\s+([-a-h1-8]+)\\s+(\\d+)\\s+(\\d+)"))) {

		string pieces    = sm.str(1);
		string tomove    = sm.str(2);
		string castle    = sm.str(3);
		string enpassant = sm.str(4);
		string halfmove  = sm.str(5);
		string fullmove  = sm.str(6);

		int rank = 7, file = 0;

		for (unsigned i = 0; i < pieces.size(); i++) {
			// do stuff with pieces
			int square = (rank * 8 + file);
			char piece = pieces[i];

			if (isdigit(piece)) {
				file += (piece - '0');
				continue;
			}

			if (piece == '/') {
				rank--;
				file = 0;
				continue;
			}

			int piece_value;

			switch (tolower(piece)) {
				case 'p':
					piece_value = PAWN;
					break;
				case 'n':
					piece_value = KNIGHT;
					break;
				case 'b':
					piece_value = BISHOP;
					break;
				case 'r':
					piece_value = ROOK;
					break;
				case 'q':
					piece_value = QUEEN;
					break;
				case 'k':
					piece_value = KING;
					break;
			}

			add_piece((isupper(piece) ? WHITE : BLACK), piece_value, square);

			printf("%c on %d\n", piece, square);

			file++;
		}
	}
}