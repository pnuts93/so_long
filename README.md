# so_long
42 Curriculum (Level 2) - Create a small videogame in C language

## Use

Note: you may need to install additional packages:  
`sudo apt-get update && sudo apt-get install xorg libxext-dev zlib1g-dev`  
  
  
`git clone` this repository  
  
`make` to compile the binary  
  
`./so_long map.ber` to start playing  
  
Use `W``A``S``D` to move around, collect the objects and use the exit.  
You may also modify the map, it just needs to follow some rules: it needs to be rectangular, it needs to be enclosed in walls (1), it needs at least one exit (E) and one player (P). Whereas the map you created is not parsable, an error message is going to be printed on the output.
