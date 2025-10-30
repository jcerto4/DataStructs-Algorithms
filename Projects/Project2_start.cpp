// Project2.cpp
//Joe Certo
//9/27/2025
//This program recursively searches for a path through a 2D maze using depth-first search

//Questions-------------------------------------------------------------------------------------------------
  /*
   1) Indicate the exact number of base cases and exact number of recursive cases you implemented in your
    search(...) function. Briefly describe the purpose each in code comments
   
        The exact number of base cases I implemented was four. There are 3 fail base cases, 
    (bounds, wall, visited), and 1 success base case (reached location). The purpose of the three failure 
    base cases is to prevent the algorithm from continuing down invalid paths. They stop recursion when it 
    reaches a condition where no progress can be made. The one success base case identifies when the goal 
    has been reached and signals the recursion to stop exploring further. The exact number of recursive cases  
    I implemented was four. The purpose of the four recursive cases is to allow the algorithm to explore    
    all possible directions from the current cell in the maze. Each recursive call represents moving
    one step in a different direction to continue searching for the goal.

    Base Cases:
        1)Out of Bounds
        2)Wall
        3)Already Visited
        4)Goal Reached
    Recursive Cases (directionally):
        1)North
        2)South
        3)East
        4)West

    2) Your solution found a path through maze1.txt, which is illustrated above. But your classmate’s solution
    found a different valid path through maze1.txt, illustrated below. In one sentence, as a comment in the
    header comments of your code, explain what causes your two solutions to find different initial paths through
    the Maze.

        The reason our two solutions found different intial paths through the maze is due to the order
    of recursive calls. These calls determine which direction is explored first. I verified this by 
    changing the order of calls (can be seen in the function commented out), and was able to get another 
    valid path through the maze. Depth-First Search will always return the first valid path, even if 
    another path is shorter. 
    
    */
//----------------------------------------------------------------------------------------------------------

#include <iostream>
#include "Maze.h"
using namespace std;

// Recrusive depth-first search for a path through a 2D array
bool search(Maze& maze, int r, int c, int targetR, int targetC) {
    
    // YOUR CODE HERE

    // 1. Cannot proceed if (r, c) is out of bounds, a wall, or has already been visited.
    //    Return false.
    if(!maze.inBounds(r, c) || maze.isWall(r, c) || maze.isVisited(r, c)) return false;

    // 2. If we get this far, we can proceed. Mark location as visited.
    maze.visit(r, c);

    // 3. If we've reached our destination. Return true.
    if(targetR == r && targetC == c) return true;

    // 4. Try to search in all four directions. 
    //    Return true if a direction finds the target location. 
    //    Continue searching in next direction if no path found from previous direction.
    if(search(maze, r+1, c, targetR, targetC)) return true;
    if(search(maze, r-1, c, targetR, targetC)) return true;
    if(search(maze, r, c+1, targetR, targetC)) return true; 
    if(search(maze, r, c-1, targetR, targetC)) return true; 

    //Testing different directions, this will produce a different valid path
    // if(search(maze, r, c+1, targetR, targetC)) return true;
    // if(search(maze, r, c-1, targetR, targetC)) return true;
    // if(search(maze, r+1, c, targetR, targetC)) return true; 
    // if(search(maze, r-1, c, targetR, targetC)) return true; 

    // 5. If we get this far, then there is no path found. 
    //    Unvisit this location and return false.
    maze.unvisit(r, c);
    return false;
}

// Helper method that sets default start search to upper left and default taget to lower right.
bool search(Maze& maze) {
    return search(maze, 0, 0, maze.getNRows()-1, maze.getNCols()-1);
}

// > c++ Project2.cpp -o search
// > .\search maze1.txt
int main(int argc, char* argv[]) {
    string filename(argv[1]);

    // Create a Maze from the given file
    Maze* m = new Maze(filename);

    cout << "Initial Maze config" << endl;
    cout << *m << endl;
    bool found = search(*m);

    if (!found) {
        cout << "Cannot find a path through " << filename << endl;
    } else {
        cout << "Found a path through " << filename << endl;
        cout << *m << endl;
    }
}
