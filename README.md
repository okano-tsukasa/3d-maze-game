# 3D Maze Game

A simple first-person 3D maze game built with C and raylib.

![Game Screenshot](https://via.placeholder.com/800x600.png?text=3D+Maze+Game+Screenshot)

## Overview

This is an educational 3D maze game where you navigate through a maze from a first-person perspective to reach the goal. The game demonstrates basic 3D graphics programming using the raylib library.

## Features

- First-person 3D view
- WASD keyboard controls for movement
- Mouse controls for camera rotation
- Goal detection system
- Simple and clean UI
- Lightweight (~135KB executable)

## Screenshots

(screenshots/gameplay.png)


## Requirements

### For Running
- Windows 10/11
- OpenGL 3.3 compatible GPU
- raylib DLL (included with MSYS2 installation)

### For Building
- Windows 10/11
- MSYS2
- GCC compiler (15.2.0 or later)
- raylib library

## Installation

### Option 1: Download Pre-built Binary (Coming Soon)

1. Download `maze_game.exe` from the releases page
2. Double-click to run

### Option 2: Build from Source

1. Install MSYS2 from [https://www.msys2.org/](https://www.msys2.org/)

2. Open MSYS2 UCRT64 terminal and install dependencies:
```bash
pacman -S mingw-w64-ucrt-x86_64-gcc
pacman -S mingw-w64-ucrt-x86_64-raylib
```

3. Clone this repository:
```bash
git clone https://github.com/yourusername/3d-maze-game.git
cd 3d-maze-game
```

4. Build the game:
```bash
gcc -std=c99 -Wall -O2 -I/c/msys64/ucrt64/include \
    -o maze_game.exe src/main.c \
    -L/c/msys64/ucrt64/lib -lraylib -lopengl32 -lgdi32 -lwinmm
```

5. Run the game:
```bash
./maze_game.exe
```

## Controls

| Key/Action | Function |
|------------|----------|
| `W` | Move forward |
| `S` | Move backward |
| `A` | Move left |
| `D` | Move right |
| `Mouse` | Look around |
| `ESC` | Exit game |

## How to Play

1. Launch `maze_game.exe`
2. Use WASD keys to move through the maze
3. Use your mouse to look around
4. Find the green cube (goal) to complete the maze
5. Press ESC to exit

## Project Structure

```
3d-maze-game/
├── docs/
│   ├── 要件定義書.txt          # Requirements document
│   ├── 設計書.txt              # Design document
│   ├── 動作テスト手順書.txt    # Test procedure
│   └── テスト結果レポート.txt  # Test results
├── src/
│   └── main.c                  # Main source code
├── tests/                      # Test directory
├── Makefile                    # Build configuration
├── README.md                   # This file
└── LICENSE                     # License file

```

## Technical Details

- **Language**: C (C99 standard)
- **Graphics Library**: raylib
- **Compiler**: GCC
- **Platform**: Windows (portable to Linux/macOS with minor modifications)
- **Maze Size**: 10x10 grid
- **Target FPS**: 60
- **Window Size**: 800x600 pixels

## Development

### Building with Make

If you have `make` installed:

```bash
make all    # Build the game
make run    # Build and run
make clean  # Clean build artifacts
make help   # Show help
```

### Code Structure

The game is implemented in a single file (`src/main.c`) for simplicity:

- Maze data: 2D integer array (1=wall, 0=path)
- Camera: First-person view using raylib's Camera3D
- Game loop: Standard init-update-draw pattern
- Goal detection: Distance-based calculation

## Known Limitations

- Collision detection is simplified (may pass through walls)
- Mouse sensitivity is fixed
- Single maze layout (no level selection)
- No sound effects

## Future Enhancements

- [ ] Improved collision detection
- [ ] Multiple maze levels
- [ ] Adjustable mouse sensitivity
- [ ] Timer and score system
- [ ] Sound effects
- [ ] Minimap display
- [ ] External maze file loading

## Contributing

Contributions are welcome! Please feel free to submit issues or pull requests.

1. Fork the repository
2. Create your feature branch (`git checkout -b feature/AmazingFeature`)
3. Commit your changes (`git commit -m 'Add some AmazingFeature'`)
4. Push to the branch (`git push origin feature/AmazingFeature`)
5. Open a Pull Request

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## Acknowledgments

- [raylib](https://www.raylib.com/) - Amazing game development library
- [MSYS2](https://www.msys2.org/) - Development environment

## Author

Created with Claude Code

## Support

If you encounter any issues or have questions:
- Open an issue on GitHub
- Check the documentation in the `docs/` folder

## Changelog

### Version 1.0 (2025-11-20)
- Initial release
- Basic 3D maze navigation
- First-person controls
- Goal detection system

---

**Enjoy the maze!**
