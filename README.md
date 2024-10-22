
# So_long

So_long is a 2D game development project in C programming language that we did for 42 schools to understand graphical interfaces and mlx library.
## Game View  
[![Game View](https://github.com/menasy/so_long/blob/main/so_long_GameView.png)](https://github.com/menasy/so_long/raw/main/so_long_demo.mov)

_Click the image above to download the demo video!_
## Installation
```bash
git clone git@github.com:MeNasy/so_long.git so_long
```
## Usage

To compile the program, run:
```bash
make
```
To run the program, use one of the following commands:
```bash
./so_long maps/map.ber
./so_long maps/mini.ber
```
After these steps, the game will start.
You can use the W, A, S, D keys or the arrow keys to move the player. To close the programme you can use the ESC key or the window close key.

To finish the game, you just need to collect all the cups and go to the exit door. Good luck ! :)

## Customization

You can also customize the program. You can display your own images on the screen and play the game that way. To do this:

- Find 5 images: player, floor, wall, and collectible items.
- Adjust the size of the photos to 64x64. You can use https://www.iloveimg.com/resize-image
- Convert the images you have adjusted to .xpm file. You can use https://convertio.co/tr/jpg-xpm/
- Name your .xpm files like the files in the so_long/textures directory: player, wall, coin, and empty. The program will not work if the names are not the same.
- After the naming process, remove the files in the textures folder and place your own .xpm files.
- After running the code, the images you uploaded will be on the screen.
