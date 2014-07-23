using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace NineTileGame_481
{
    public class BreadthFirstSearch
    {
        public bool Search(NineTileGameBoard board, NineTileGameBoard goalBoard, Heuristics.HeuristicTypes heuristicType)
        {
            Heuristics Heuristic = new Heuristics(heuristicType);
            // check board is the goal board
            if (!board.Equals(goalBoard))
            {
                // get childern
                List<NineTileGameBoard> children = board.GetChildren();

                // get heuristic of each child
                foreach (var child in children)
                {
                    child.heuristicValue = Heuristic.GetHeuristicValue(child, goalBoard);
                }

                // use child with best heurisitic value for next iteration
                NineTileGameBoard nextBoard = children.OrderBy(x => x.heuristicValue).First();

                // print to file
                board.PrintBoard(true);
                foreach (var child in children)
                {
                    child.PrintBoard(false);
                }

                // next iteration
                Search(nextBoard, goalBoard, heuristicType);
            }
            else
            {
                board.PrintBoard(true);
                return true;
            }
            return false;
        }


    }
}
