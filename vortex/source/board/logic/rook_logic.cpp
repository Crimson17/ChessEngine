#include "vortex.h"


void vtx::get_white_rook_moves(const Board& board, const int x, const int y, std::vector<Board>& out_boards)
{
	const int from_index = get_index(x, y);

	// Right
	for (int i = 1; i < 8; i++) {
		if (!in_board(x + i, y))
			break;

		const int index = get_index(x + i, y);
		if (board[index].is_white())
			break;

		if (board[index].is_black()) {
			out_boards.push_back(board.after_playing(from_index, index, W_ROOK));
			break;
		}
		out_boards.push_back(board.after_playing(from_index, index, W_ROOK));
	}

	// Left
	for (int i = 1; i < 8; i++) {
		if (!in_board(x - i, y))
			break;

		const int index = get_index(x - i, y);
		if (board[index].is_white())
			break;

		if (board[index].is_black()) {
			out_boards.push_back(board.after_playing(from_index, index, W_ROOK));
			break;
		}
		out_boards.push_back(board.after_playing(from_index, index, W_ROOK));
	}

	// Top
	for (int i = 1; i < 8; i++) {
		if (!in_board(x, y + i))
			break;

		const int index = get_index(x, y + i);
		if (board[index].is_white())
			break;

		if (board[index].is_black()) {
			out_boards.push_back(board.after_playing(from_index, index, W_ROOK));
			break;
		}
		out_boards.push_back(board.after_playing(from_index, index, W_ROOK));
	}

	// Bottom
	for (int i = 1; i < 8; i++) {
		if (!in_board(x, y - i))
			break;

		const int index = get_index(x, y - i);
		if (board[index].is_white())
			break;
		
		if (board[index].is_black()) {
			out_boards.push_back(board.after_playing(from_index, index, W_ROOK));
			break;
		}
		out_boards.push_back(board.after_playing(from_index, index, W_ROOK));
	}
}

void vtx::get_black_rook_moves(const Board& board, const int x, const int y, std::vector<Board>& out_boards)
{
	const int from_index = get_index(x, y);

	// Right
	for (int i = 1; i < 8; i++) {
		if (!in_board(x + i, y))
			break;

		const int index = get_index(x + i, y);
		if (board[index].is_black())
			break;

		if (board[index].is_white()) {
			out_boards.push_back(board.after_playing(from_index, index, B_ROOK));
			break;
		}
		out_boards.push_back(board.after_playing(from_index, index, B_ROOK));
	}

	// Left
	for (int i = 1; i < 8; i++) {
		if (!in_board(x - i, y))
			break;

		const int index = get_index(x - i, y);
		if (board[index].is_black())
			break;

		if (board[index].is_white()) {
			out_boards.push_back(board.after_playing(from_index, index, B_ROOK));
			break;
		}
		out_boards.push_back(board.after_playing(from_index, index, B_ROOK));
	}

	// Top
	for (int i = 1; i < 8; i++) {
		if (!in_board(x, y + i))
			break;

		const int index = get_index(x, y + i);
		if (board[index].is_black())
			break;

		if (board[index].is_white()) {
			out_boards.push_back(board.after_playing(from_index, index, B_ROOK));
			break;
		}
		out_boards.push_back(board.after_playing(from_index, index, B_ROOK));
	}

	// Bottom
	for (int i = 1; i < 8; i++) {
		if (!in_board(x, y - i))
			break;

		const int index = get_index(x, y - i);
		if (board[index].is_black())
			break;

		if (board[index].is_white()) {
			out_boards.push_back(board.after_playing(from_index, index, B_ROOK));
			break;
		}
		out_boards.push_back(board.after_playing(from_index, index, B_ROOK));
	}
}
