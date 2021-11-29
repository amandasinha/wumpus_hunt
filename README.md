# wumpus_hunt
A text-based game in which the user attempts to enter and leave a cave, with their loot and the head of the wumpus.

The user enters a grid system of caves, each of which can be empty or contain one of a few events:
 --> bats which move the user (2 per cave system)
 --> a pit which kills the user (2 per cave system)
 --> the wumpus which can kill the user (1 p
 --> the gold which can be picked up

If the user dies within the caves, then they lose; alternatively, if the user can escape with the gold, they win.
The user can do one thing every turn; they can either move up, down, left, or right, or they can shoot an arrow, of which they have three. These arrows can fly through three rooms, or until they hit a wall (no Scooby Doo logic!).

The user is assisted by "precepts" which indicate that some event is nearby--though not which direction.
The size of the cave system can be determined by the user. Additionally, a debug mode is available.
