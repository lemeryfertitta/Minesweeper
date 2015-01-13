# Minesweeper
Minesweeper in C++.

A small project I put together quickly to learn some C++. Built using [OpenGL](https://www.opengl.org/) for graphics, [GLFW](http://www.glfw.org/) for window and input managment, and Lode Vandevenne's [LodePNG](http://lodev.org/lodepng/) for texture loading.

## Planned Features
* GUI
  * New game dialog with options
  * Timer
  * Highscores
* Gameplay
  * Flagging
  * Generate only solvable boards (by creating an AI solver)
  * Generate more consistent board difficulty (according to [3BV](http://www.minesweeper.info/wiki/3BV))
* Graphics
  * Tiles with improved clarity, especially with lower tile dimensions
  * Flag and mine graphics
  * Hovered tile effect
  
## Known Issues
* vector out of range crash, seems to be caused by clicking quickly after opening.
