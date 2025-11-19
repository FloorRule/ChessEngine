# ChessEngine

A full chess engine implementation with a **C++ backend** for game logic and a **C# frontend** for board visualization and user interaction.
The engine supports standard movement rules, turn handling, captures, checks, and checkmates, and communicates with the UI through a custom pipe protocol.

---

## Overview

The backend handles all game logic:

* Board representation
* Movement validation for all pieces
* Capture handling
* Turn-based gameplay
* Check and checkmate detection
* Move execution and board updates

The frontend (`chessGraphics.exe`) displays the board, highlights moves, and sends player actions to the backend.

**Note:** Pawn promotion, castling, and en passant are not implemented.

---

## Features

### Implemented

* Full piece movement rules
* Turn management
* Legal/illegal move detection
* Capture logic
* Check & checkmate detection
* Console-hidden backend with pipe communication
* C# graphical board display
* Complete playable chess match

### Not Implemented

* Castling
* Pawn promotion
* En passant
* Stalemate/draw detection

---

## Backend (C++)

The engine includes classes for every chess piece:

* `King`
* `Queen`
* `Rook`
* `Bishop`
* `Knight`
* `Pawn`

Along with:

* `Board` – manages the 8×8 board
* `Pipe` – handles communication between backend and frontend

The backend launches the UI automatically and waits for it to connect:

```cpp
system("start ./chessGraphics.exe");
Pipe p;
p.connect();
```

Moves are received from the UI as 4-character strings (e.g., `"e2e4"`), processed, validated, and the engine responds with result codes.

---

## Frontend (C#)

The C# graphical application (`chessGraphics.exe`) displays:

* The board
* All pieces
* User-selected moves
* Move result feedback (illegal, check, etc.)

It sends moves to the backend via `Pipe`, receives updates, and redraws the board accordingly.

---

## Communication Protocol

The engine sends and receives messages using the `Pipe` class.

### UI → Engine

* Move commands (e.g., `"e2e4"`)
* `"quit"` to exit

### Engine → UI

* Initial board layout string
* Move result codes:

| Code | Meaning                   |
| ---- | ------------------------- |
| 0    | Valid move                |
| 1    | Valid move + CHECK        |
| 2    | No piece at source square |
| 3    | Illegal move              |
| 6    | This piece cannot move    |
| 8    | Game over (king captured) |

---

## How to Run

### 1. Build the backend

Compile the C++ source files using Visual Studio or another compiler:

```sh
g++ main.cpp -o ChessEngine.exe
```

Ensure all `.cpp` and `.h` files are included.

### 2. Place the frontend in the same folder

```
ChessEngine/
├── ChessEngine.exe
└── chessGraphics.exe
```

### 3. Run the backend

```
ChessEngine.exe
```

The frontend will open automatically and start the game.

---

---

## Future Improvements

* Implement castling
* Implement pawn promotion
* Implement en passant
* Add stalemate/draw detection
* Add AI (minimax + evaluation)
* Add move history and notation
