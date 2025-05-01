# 🐍 Snake Game in C

A simple yet fun **console-based Snake Game** implemented in C. Navigate your snake through the grid, gobble up food, and try to grow as long as possible—just don't crash into the walls!

---

## 🎮 Overview

This project is a command-line Snake game where you control a snake that grows longer each time it eats food. The goal is to score as high as possible without crashing into the boundaries. The game runs in real-time and offers a basic but entertaining gameplay experience directly in the terminal.

---

## ✨ Features

- 🕹️ **Real-time gameplay** in the console.
- 🎯 **Simple controls** using keyboard input.
- 🍎 **Food-based growth system** – snake grows longer with every bite.
- 🧮 **Score display** to keep track of your progress.
- 💥 **Game over condition** – when the snake hits the wall.

---

## 📜 Rules

- The game area has boundaries (represented by `*`).
- Food appears randomly within the game area (represented by `@`).
- Each time the snake eats food:
  - It grows by one unit.
  - You earn **10 points**.
- The game ends when the snake collides with the wall or itself.

---

## 🎮 Controls

Use the following keys to control the snake:

| Key | Action     |
|-----|------------|
| `u` | Move Up    |
| `d` | Move Down  |
| `r` | Move Right |
| `l` | Move Left  |

---

## 🛠️ Compilation and Execution

To compile and run the game, use any C compiler like `gcc`:

```bash
gcc snake.c -o snake
./snake
```

## 🚀 Future Improvements (Optional Ideas)

If you're feeling adventurous, here are some fun things to add:

- 💀 Snake collision with itself.
- 🧱 Obstacles within the game area.
- ⏱️ Increasing speed as the game progresses.
- 💾 High score saving system.

---

## 📂 File Structure

```bash
.
├── snake.c        # Main source file
├── README.md      # Project documentation
```
