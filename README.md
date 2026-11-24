# 🗡️ Shadow Grid

A lightweight, terminal-based grid dungeon and treasure hunt game written in pure **C**. Navigate through walls, collect hidden gems, unlock the exit door, and build toward full dungeon survival—developed step by step to practice core C programming, 2D arrays, pointers, and game state logic.

---

## 🎮 Gameplay Overview

You control the adventurer (`@`) inside a 2D grid dungeon. Collect all gems (`*`) to unlock and reach the exit (`E`) while tracking your live score and remaining gems.

### Map Legend
| Symbol | Meaning | Status |
| :---: | :--- | :--- |
| `@` | Player | Active |
| `#` | Wall (Impassable) | Active |
| `.` | Open Floor | Active |
| `*` | Gem (+10 points; clears tile once collected) | Active |
| `E` | Exit Door (Unlocks once all `*` gems are collected) | Active |
| `^` | Trap / Hazard | Planned (Stage 3) |
| `G` | Patrol Enemy | Planned (Stage 4) |

---

## 🕹️ Controls

| Key | Action |
| :---: | :--- |
| `W` | Move Up |
| `A` | Move Left |
| `S` | Move Down |
| `D` | Move Right |
| `Q` | Quit Game |

*(Note: Press `Enter` after each key input.)*

---

## 🛠️ Roadmap & Features

- [x] **Stage 1:** 2D grid rendering, `WASD` movement, and wall/boundary collision detection
- [x] **Stage 2:** Collectible gems (`*`), live score & remaining gem counter, tile clearing, and gem-gated exit (`E`)
- [ ] **Stage 3:** Traps (`^`), player health (`HP`), and Game Over / Victory screens
- [ ] **Stage 4:** Moving patrol enemies (`G`) with turn-based AI
- [ ] **Stage 5:** Multiple levels and persistent high-score saving via File I/O
- [ ] **Stage 6:** Fog of War (line-of-sight exploration)

---

## 🚀 How to Compile & Run

### Prerequisites
Make sure you have a C compiler installed, such as **GCC** or **Clang**.

### Steps
1. **Clone the repository:**
   ```bash
   git clone [https://github.com/AmeerKhasru/ascii-quest.git](https://github.com/AmeerKhasru/ascii-quest.git)
   cd ascii-quest
