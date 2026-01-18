Tetris-SFML: Modern Arcade Reimagined
A high-performance, feature-complete recreation of the classic puzzle game. Developed in C++ using the SFML library, this project features a sleek, modern UI with smooth animations, responsive controls, and a robust backend architecture.

✨ Key Features
Polished UI: Beautifully designed menus, vibrant game boards, and clear typography.

Smooth Mechanics: Includes professional-grade logic like ghost-piece projection, wall kicks, and hard drops.

Dynamic Scoring: Experience a classic leveling system where the speed increases as you master the game.

Audio/Visuals: Integrated sound effects and high-fidelity 2D textures for an immersive experience.

🛠️ Technical Details
Language: C++

Graphics Library: SFML (Simple and Fast Multimedia Library)

Architecture: Clean Object-Oriented Programming (OOP).

Board: Handles grid logic and line clearing.

Piece: Manages tetromino shapes, rotations, and movement.

GameEngine: The core loop managing events, updates, and rendering.

📦 Prerequisites & Installation
To run this project, you need the SFML (Simple and Fast Multimedia Library) installed on your machine.

1. Download SFML
You can download the library directly from the official website: 👉 Download SFML Library

Note: Ensure you download the version that matches your compiler (e.g., MinGW, Visual C++, etc.).

2. Setting Up
Clone this repository to your local machine.

Extract your SFML folder (e.g., to C:\SFML-2.4.2-windows-gcc-6.1.0-mingw-32-bit).

🚀 How to Compile and Run
Open your terminal or command prompt and use the following commands. Adjust the paths if your SFML folder is located elsewhere.

Step 1: Compile the Source
This command compiles your main.cpp and links the SFML headers.

Bash
g++ -c main.cpp -I"C:\SFML-2.4.2-windows-gcc-6.1.0-mingw-32-bit\SFML-2.4.2\include"
Step 2: Link the Libraries
This step links the object file to the SFML graphics, window, and system libraries to create the executable.

Bash
g++ main.o -o main -L"C:\SFML-2.4.2-windows-gcc-6.1.0-mingw-32-bit\SFML-2.4.2\lib" -lsfml-graphics -lsfml-window -lsfml-system
Step 3: Run the Game
Simply execute the generated file:

Bash
./main
🎮 Controls
Left/Right Arrow: Move Piece

Up Arrow: Rotate Piece

Down Arrow: Soft Drop

Spacebar: Hard Drop

P: Pause Game

🤝 Contributing
Contributions are what make the open-source community such an amazing place to learn, inspire, and create. Any contributions you make are greatly appreciated.

Fork the Project

Create your Feature Branch (git checkout -b feature/AmazingFeature)

Commit your Changes (git commit -m 'Add some AmazingFeature')

Push to the Branch (git push origin feature/AmazingFeature)

Open a Pull Request

Developed with ❤️ using C++ and SFML.
