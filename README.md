# Doodlebug-and-Ant
The goal was to create a 2-D predator-prey simulation. In this simulation, the prey are ants and the predators are doodlebugs. These critters live in a world composed of a 20x20 grid of cells. Only one critter may occupy a cell at a time. The grid is enclosed, so a critter is not allowed off the edges of the grid. Time is simulated in iterations. Each critter performs some action every step. The ASCII characters of "o" for an ant and "X" for a doodlebug are used.

The ants behave according to the following model:

Move. Every iteration, randomly try to move up, down, left, or right. If the cell in the selected direction is occupied or would move the ant off the grid, then the ant stays in the current cell.
Breed. If an ant survives for three iterations, then at the end of the third iteration the ant will breed. This is simulated by creating a new ant in the adjacent cell that is empty. If there is no empty cell available, no breeding occurs.
The doodlebugs behave according to the following model:

Move. Same mechanics as the ant, but if an adjacent cell is occupied by an ant, then the doodlebug will move to that cell and eat the ant. Note that a doodlebug cannot eat other doodlebugs.
Breed. If a doodlebug survives for eight iterations, it will spawn a new doodlebug in the same manner as the ant.
Starve. If a doodlebug has not eaten an ant in three iterations, it will starve and die. The doodlebug is then removed from the grid of cells.
