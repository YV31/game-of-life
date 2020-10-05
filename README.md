# Conway's Game of Life
Conway's Game of Life implementation in C++ with [raylib](https://github.com/raysan5/raylib).

**Compilation:**

Link the [raylib](https://github.com/raysan5/raylib) librarie with the pkg-config or link it with whatever thing you use.

*Example:*
```bash
clang++ game-of-life.cpp `pkg-config --static --libs raylib`
```
**Change the settings:**

Change the number of columns, rows or the size of the cell in the code and recompile.

*Default settings:*
```cpp
const int cell_size = 4;

const int rows = 150;
const int columns = 150;
```
