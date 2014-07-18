#include "stdafx.h"

class Board
{
	private:
		static const int NumRows = 3;
		static const int NumCols = 3;

		bool IsValidRowCol(int row, int col)
		{
			if (row >= 0 && col >= 0 && row<NumRows && col<NumCols) {
				return true;
			}
			return false;
		}

	public:
		// the board is initilized with the solution/goal
		int _board[NumRows][NumCols] = { { 1, 2, 3 }, { 8, 0, 4 }, { 7, 6, 5 } };

		// returns a pointer to the array board of this object
		int* GetBoard()
		{
			return * this->_board;
		}

		// sets the board (array) of this object to the argument
		void SetBoard(int board[NumRows][NumCols])
		{
			for (int i = 0; i<NumRows; i++) {
				for (int j = 0; j<NumCols; j++) {
					this->_board[i][j] = board[i][j];
				}
			}
		}

		// returns an array of boards (2d arrays) that are the possible next moves
		// from the current board of this object
		int* GetLegalNextMoves()
		{
			int currentEmptyRow = -1;
			int currentEmptyCol = -1;
			int responseBoards[NumRows][NumCols][4] = { -1 };
			int validMovesFound = 0;

			// find current position of the empty space
			for (int i = 0; i<NumRows; i++) {
				for (int j = 0; j<NumCols; j++) {
					if (this->_board[i][j] == 0) {
						currentEmptyRow = i;
						currentEmptyCol = j;
						break;
					}
				}
			}

			// see what move is valid out of the four possible
			// check up
			if (IsValidRowCol(currentEmptyRow - 1, currentEmptyCol)) {
				// get copy of the board
				for (int i = 0; i<NumRows; i++) {
					for (int j = 0; j<NumCols; j++) {
						responseBoards[i][j][validMovesFound] = this->_board[i][j];
					}
				}
				// move the tile
				responseBoards[currentEmptyRow][currentEmptyCol][validMovesFound] = responseBoards[currentEmptyRow - 1][currentEmptyCol][validMovesFound];
				responseBoards[currentEmptyRow - 1][currentEmptyCol][validMovesFound] = 0;
				validMovesFound++;
			}

			// check right
			if (IsValidRowCol(currentEmptyRow, currentEmptyCol + 1)) {
				// get copy of the board
				for (int i = 0; i<NumRows; i++) {
					for (int j = 0; j<NumCols; j++) {
						responseBoards[i][j][validMovesFound] = this->_board[i][j];
					}
				}
				// move the tile
				responseBoards[currentEmptyRow][currentEmptyCol][validMovesFound] = responseBoards[currentEmptyRow][currentEmptyCol + 1][validMovesFound];
				responseBoards[currentEmptyRow][currentEmptyCol + 1][validMovesFound] = 0;
				validMovesFound++;
			}

			// check down
			if (IsValidRowCol(currentEmptyRow + 1, currentEmptyCol)) {
				// get copy of the board
				for (int i = 0; i<NumRows; i++) {
					for (int j = 0; j<NumCols; j++) {
						responseBoards[i][j][validMovesFound] = this->_board[i][j];
					}
				}
				// move the tile
				responseBoards[currentEmptyRow][currentEmptyCol][validMovesFound] = responseBoards[currentEmptyRow + 1][currentEmptyCol][validMovesFound];
				responseBoards[currentEmptyRow + 1][currentEmptyCol][validMovesFound] = 0;
				validMovesFound++;
			}

			// check left
			if (IsValidRowCol(currentEmptyRow, currentEmptyCol - 1)) {
				// get copy of the board
				for (int i = 0; i<NumRows; i++) {
					for (int j = 0; j<NumCols; j++) {
						responseBoards[i][j][validMovesFound] = this->_board[i][j];
					}
				}
				// move the tile
				responseBoards[currentEmptyRow][currentEmptyCol][validMovesFound] = responseBoards[currentEmptyRow][currentEmptyCol - 1][validMovesFound];
				responseBoards[currentEmptyRow][currentEmptyCol - 1][validMovesFound] = 0;
				validMovesFound++;
			}

			return responseBoards;
		}

};