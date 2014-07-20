/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author irisandradesantos
 */
public class Node {
    private String [][] actualPuzzle;
    private int weight;
    private String [][] goalPuzzle; 
    Heuristics heuristic = new Heuristics();
    
    public Node(String [][]  puzzle, String [][] goalPuzzle) {
        this.actualPuzzle = puzzle;
        
        this.weight = heuristic.coutingOutOfPlacedTiles(puzzle, goalPuzzle);
        this.goalPuzzle = goalPuzzle;
    }

    public String[][] getActualPuzzle() {
        return actualPuzzle;
    }

    public int getWeight() {
        return weight;
    }
    public void findBestChild(){
       //compare children
       //if()
    
    }

}
