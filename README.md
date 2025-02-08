# So_long
<div align="center">
  <img src="https://img.shields.io/badge/norminette-passing-success"/>
  <img src="https://img.shields.io/badge/42-project-000000"/>
</div>

## 💡 About
> A small 2D game where the player must collect all items and reach the exit to win.

This project is an introduction to computer graphics using the MiniLibX library. The player controls a character who must collect all collectibles on the map before reaching the exit, while avoiding walls. The game features basic gameplay elements and graphics management.

## 🛠️ Usage
### Requirements
- MinilibX library
- X11 include files (xorg)
- XShm extension (libxext-dev)
- GCC compiler
- Make

### Instructions
**1. Compiling**
```shell
$ git clone https://github.com/wdaoudi-/so_long
$ cd so_long
$ make
```

**2. Running the game**
```shell
$ ./so_long maps/map.ber
```

## 📋 Features
### Core Features
| Feature | Description |
|---------|-------------|
| Map Parsing | Validates and loads maps from .ber files |
| Player Movement | WASD or arrow keys for character control |
| Collectibles | Items that must be gathered before completion |
| Exit | Accessible only after collecting all items |
| Graphics | Sprite-based 2D graphics using MinilibX |

## 🎮 Game Controls
- W/↑: Move Up
- S/↓: Move Down
- A/←: Move Left
- D/→: Move Right
- ESC: Quit Game

## Map Requirements
- Files must have `.ber` extension
- Must be rectangular
- Must be surrounded by walls ('1')
- Must contain:
  - One start position ('P')
  - One exit ('E')
  - At least one collectible ('C')
  - Valid path to all collectibles and exit
- Valid characters:
  - '1': Wall
  - '0': Empty space
  - 'P': Player starting position
  - 'E': Exit
  - 'C': Collectible

## Error Management
- Invalid map format or extension
- Missing map elements
- Invalid path to collectibles/exit
- Multiple players or exits
- Non-rectangular map
- Map not surrounded by walls
- Memory allocation failures

## Implementation Details
- Written in C
- Follows 42 School's Norm (norminette)
- Uses MinilibX graphics library
- No memory leaks
- Error messages for invalid inputs

---
Made with ❤️ by wdaoudi-
