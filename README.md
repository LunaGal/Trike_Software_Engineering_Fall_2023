# Trike Game Documentation

## Introduction

Welcome to the Trike Game! This manual provides guidance on gameplay, rules, and interactions to enhance your gaming experience. The Trike Game is played on an equilateral triangle of varying sizes. The first player initiates the game by placing a neutral piece on the board, which becomes the focal point for subsequent moves. Players take turns moving the neutral piece, leaving markers behind. The game continues until the neutral piece can no longer move. Victory is achieved by having more game pieces surrounding the neutral piece, including the neutral piece itself.

## Documentation
Refer to [User's Manual](https://drive.google.com/file/d/1ErduxQA-KEXT_SOIUXBgVOiB4H4i7MGN/view) for a full documentation on how to play the game.

## Installation

To install the game, visit the [GitHub repository](https://github.com/LunaGal/Trike_Software_Engineering_Fall_2023) and clone the code using your preferred method. Use the SSH key for optimal installation. After downloading, navigate to the project folder in your terminal and run the game using the provided make file. On Windows, adjust the make file for your preferred compiler if needed. To start the game subsequently, use the terminal command `./main`.

## Game Structure

**Various Inputs Needed:**
- Size of the board.
- Choosing "up" or "down" orientation.
- Determining who goes first.
- Providing movement inputs (direction and distance).
- Confirming AI’s and player’s turns.

**Winning Scenarios:** The player with more markers adjacent to and under the neutral piece at the end of the game wins.

**Starting a New Game:** After the game ends, initiate a new game by following the initialization steps.

**Stuck?** If stuck, input any character and press enter. Simply clicking enter without a character input will do nothing.

## Game Play

**Gameplay Tutorial:**
1. **Board Initialization:** Enter the board size (2 to 40) and choose the orientation ("up" or "down").
2. **Choose Who Goes First:** Decide whether you want to go first or let the AI place the neutral piece automatically.
3. **AI Makes a Turn:** Enter any input to pass the turn to the AI.
4. **Neutral Piece:** When moved, the current neutral piece becomes lowercase, while the newly placed one is represented in uppercase.
5. **Player’s Move:** Specify the move direction (UL, UR, DL, DR, L, or R) and distance.
6. **Continue the Game:** Follow the prompts until the neutral piece cannot move. The winner is the player with the most pieces surrounding the neutral piece (including the neutral piece).

## 5 User FAQs

**Q: Is there a multi-player option?**
**A:** No, the game currently supports only single-player mode against the built-in AI.

**Q: How does the AI move?**
**A:** The AI moves randomly, taking one step in a random direction. The AI's behavior is consistent in the same situation.

**Q: How does the board size work?**
**A:** You can choose any board size between 2 and 40, representing the side length of the triangle-shaped board.

**Q: How do the columns work?**
**A:** Count the spaces from left to right starting at 1 to determine the column for piece placement within a row.
