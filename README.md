# 🌲 Timber Game (SFML)

A simple Timber-style 2D game built using **SFML** (Simple and Fast Multimedia Library) in C++. Inspired by classic arcade gameplay, the objective is to chop down as much of the tree as possible while avoiding falling branches!

## 🎮 Gameplay

- The player chops the tree by pressing left or right arrow keys.
- Each chop makes the tree shorter and moves a branch down.
- If the branch hits the player — game over.
- Score increases with each successful chop.

---

## 🛠️ Tech Stack

- **C++**
- **SFML (Simple and Fast Multimedia Library)**

---

## 🚀 Getting Started

### Prerequisites

- C++ compiler (e.g., g++)
- [SFML Library](https://www.sfml-dev.org/download.php)

### Clone the repo

```bash
git clone https://github.com/Hiranmaya2004/Timber.git
cd Timber
```
Build and Run (on Windows with g++)
```bash
g++ main.cpp -o Timber -lsfml-graphics -lsfml-window -lsfml-system
./Timber
```
Make sure SFML libraries are linked correctly based on your system.

📁 Project Structure

Timber/
├── .vscode/         # VSCode settings (gitignored)
├── .history/        # Editor history (gitignored)
├── main.cpp         # Game logic and SFML rendering
├── assets/          # Game assets (fonts, textures, etc.)
└── README.md        # This file
🧩 Features
Responsive keyboard controls

Simple score counter

Fast-paced arcade experience

Classic timber mechanic logic

📸 Screenshot


📜 License
This project is open source and available under the MIT License.

🙌 Credits
Made with 💚 using SFML by Hiranmaya
