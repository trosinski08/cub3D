# Cub3D

## Raycasting 3D Engine Project

A 3D maze exploration game built using raycasting techniques, created as part of the 42 school curriculum. This project implements a basic 3D renderer similar to early FPS games like Wolfenstein 3D.

## Features

- **Real-time 3D rendering** using raycasting algorithm
- **Textured walls** with different textures for each cardinal direction
- **Smooth player movement** with WASD controls
- **Mouse look** rotation system
- **Optimized performance** with efficient memory management
- **42 Norm compliant** code structure

## Technical Details

### Performance Optimizations
- **Reduced resolution**: 970x540 for optimal frame rate
- **Stack allocation**: Eliminated malloc/free from render loop
- **Optimized texture mapping**: Enhanced wall texture coordinate calculation
- **Memory leak reduction**: From ~809KB to ~2.5KB

### Rendering Pipeline
1. **Ray casting**: Cast rays from player position across field of view
2. **Wall detection**: Calculate intersections with grid-based map
3. **Distance calculation**: Apply perspective correction
4. **Texture mapping**: Map wall textures based on hit position
5. **Pixel drawing**: Render column by column to screen

## Compilation

```bash
make
```

## Usage

```bash
./cub3D [map_file.cub]
```

### Controls
- **W/A/S/D**: Move forward/left/backward/right
- **Mouse**: Look around
- **ESC**: Exit game

### Map Format
Maps use `.cub` extension with the following specifications:
- **NO/SO/WE/EA**: Texture paths for North/South/West/East walls
- **F/C**: Floor/Ceiling colors (RGB format)
- **Map grid**: 1 for walls, 0 for empty space, N/S/E/W for player spawn

## Project Structure

```
cub3D/
├── src/
│   ├── raytrace.c          # Main raycasting engine
│   ├── render_utils.c      # Texture rendering utilities
│   ├── parser.c            # Map and config parsing
│   ├── draw.c              # Drawing primitives
│   └── ...
├── maps/                   # Example map files
├── textures/               # Wall texture assets
└── Makefile
```

## Technical Implementation

### Raycasting Algorithm
The engine uses a DDA (Digital Differential Analyzer) approach:
1. Cast rays at regular angular intervals
2. Step through grid intersections
3. Calculate wall distances using Euclidean geometry
4. Apply fish-eye correction for perspective

### Memory Management
- **Zero malloc** in render loop for 60+ FPS performance
- **Garbage collector** system for texture cleanup
- **Stack-based** texture structures

## Allowed Functions
- `open`, `close`, `read`, `write`
- `printf`, `malloc`, `free`, `perror`, `strerror`, `exit`
- Math library functions (`-lm`)
- MLX42 graphics library functions

## Author
**Tomasz Rosiński** - 42 Heilbronn student

*Created during the magical journey at 42 Heilbronn coding school*
