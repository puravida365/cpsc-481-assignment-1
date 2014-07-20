/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author irisandradesantos
 */
public class main {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        String puzzle[][] = new String[][]{{"2", "8", "3"},
        {"1", "6", "4"},
        {"7", "e", "5"}};
        String goalPuzzle[][] = new String[][]{{"1", "2", "3"},
        {"4", "5", "6"},
        {"7", "8", "e"}};
        //steepest-descent hill-climbing
        
        Node node = new Node(puzzle, goalPuzzle);
        //substitute for while
        for(int i = 0; i<5; i++){
            
            System.out.println("peso = "+node.getWeight()); 
            
        }
        
        

        
    }
    
}
