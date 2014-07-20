/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author irisandradesantos
 */
public class Heuristics {
    
    public Heuristics() {
    }

    public int coutingOutOfPlacedTiles(String[][] puzzle, String[][] goalPuzzle) {
        int count = 0;
        for (int i = 0; i < puzzle.length; i++) {
            for (int j = 0; j < puzzle[i].length; j++) {
                if (puzzle[i][j] != goalPuzzle[i][j]) {
                    count += 1;
                }

            }
        }

        return count;
    }
}
