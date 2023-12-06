# classic-snake
The classic snake game, written in C/C++ and SDL2!

# Building
## Dependencies
### Arch Linux
```bash
sudo pacman -S git sdl2
```

## Process
```bash
# Clone the repository using Git:
git clone https://github.com/krillissue/classic-snake

# Build:
cd classic-snake
make -j$(nproc --all)

# Launch:
./bin/classic-snake

# (Optional) Install:
sudo make install
```
