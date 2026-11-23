# shadow-grid-by-c
A lightweight, terminal-based grid dungeon and treasure hunt game written in pure **C**. Navigate through walls, collect hidden treasures, avoid hazards, and reach the exit door—built step by step to practice core C programming, 2D arrays, pointers, and game loop logic.

---

## 🎮 Gameplay Overview

You control the adventurer (`@`) inside a 2D grid dungeon. Your goal is to explore the map, gather collectibles, survive obstacles, and find the exit (`E`).

### Map Legend
| Symbol | Meaning |
| :---: | :--- |
| `@` | Player |
| `#` | Wall (Impassable) |
| `.` | Open Floor |
| `*` | Treasure / Gem *(Upcoming)* |
| `^` | Trap / Hazard *(Upcoming)* |
| `G` | Patrol Enemy *(Upcoming)* |
| `E` | Exit Door *(Upcoming)* |

---

## 🕹️ Controls

| Key | Action |
| :---: | :--- |
| `W` | Move Up |
| `A` | Move Left |
| `S` | Move Down |
| `D` | Move Right |
| `Q` | Quit Game |

*(Note: In Stage 1, press `Enter` after each key input.)*

---

## 🛠️ Roadmap & Features

- [x] **Stage 1:** 2D grid rendering, `WASD` movement, and wall/boundary collision detection
- [ ] **Stage 2:** Collectible gems (`*`), live score tracking, and level exit (`E`)
- [ ] **Stage 3:** Traps (`^`), player health (`HP`), and Game Over / Victory screens
- [ ] **Stage 4:** Moving patrol enemies (`G`) with turn-based AI
- [ ] **Stage 5:** Multiple levels and persistent high-score saving via File I/O
- [ ] **Stage 6:** Fog of War (line-of-sight exploration)

---

## 🚀 How to Compile & Run

### Prerequisites
Make sure you have a C compiler installed, such as **GCC** or **Clang**
