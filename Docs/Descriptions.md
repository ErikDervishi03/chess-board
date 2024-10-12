# Project Files

Brief descriptions of the project, each file and how they interact.

## General Structure

### Main Entry Point:

    Python Script: This is the file you launch to start the game. It will handle user interactions, the graphical user interface (GUI), and the game loop.

### Python Side Responsibilities:

    - User Interface: Handling all user interactions (e.g., moving pieces, displaying the board).
    - Game State Management: Keeping track of the current game state, including the positions of all pieces, whose turn it is, and whether the game is over.
    - Input Handling: Capturing user inputs and translating them into function calls or commands for the game logic.
    - Visual Representation: Rendering the chessboard and pieces on the screen.

### C Side Responsibilities:

    - Game Logic: Implementing the core logic for the chess engine, including:
        . Move Generation: Determining all legal moves for a given position.
        . Move Validation: Ensuring moves are legal according to the rules of chess.
        . Game State Evaluation: Assessing the board's state for AI decisions, checking for check, checkmate, stalemate, etc.
    - Performance-Critical Calculations: All heavy computing, so all Algorithms used to create the engine.


## Files

### main.py

    The launch script, only starts everything off. Calls upon gui.py to start the loop.
    [//]: # (The structure will vary, it may not call gui forever.)

### gui.py

    This script initializes the Pygame-based chess game interface, loading the chessboard and pieces, handling user interactions for selecting and moving pieces, and integrating with wrapper.py to make moves and update the game state.

### wrapper.py

    This script serves as the bridge between the Python and the C sides of the project. It imports the shared library and defines wrapper functions usable by other python scripts. It also contains the declaration of pyboard(instead of doing it in chess.py) for conversion reasons.

### chess.py

    Here we have the functions that make up all actions users can take in the game of chess. Some of these function execute a certain step in python and then call the equivalent wrapper.py function for C correspondence.

### utils.py

    utils.py is like the tool-box of the project, a place for useful functions that might be needed anywhere. A good place to look/use if you need something done.


### board.c/.h

    This C file contains the default board configuration and all the board-related functions we may need. board.h also defines a few quick functions for simplicity's sake.

### types.h

    A file containing all types, constants and definitions for the C side of the project. 

### list.c/.h

    Everything about lists you can find here. All sorts of operations on any type of list can be found here. Functions are defined to accomodate any one of the two types of list(piece list and move list).

### stack.c/.h

    An integration on the list functions for list we want to treat as stacks(moves).

### valid.c/.h

    Here we have all validations on moves and positions, defining which moves are legal and which aren't, what moves a piece can make in a given position, if a certain move is a check, and so on.