
```
# So_long

So_long is a 2D game development project in C programming language that we did for 42 schools to understand graphical interfaces and mlx library.

## Installation

git clone git@github.com:MeNasy/so_long.git so_long

## Usage

To compile the program, run:

make

To run the program, use one of the following commands:

./so_long maps/map.ber
./so_long maps/mini.ber

After these steps, the game will start.
To finish the game, you just need to collect all the cups and go to the exit door :) good luck...

## Customization

You can also customize the program by using your own images on the screen. To do that, follow these steps:

1 -) Find 5 images for the player, the floor, the wall and the collectible items
2 -) Adjust the size of the photos to 64x64. You can use https://www.iloveimg.com/resize-image
3 -) Convert the images you have adjusted to .xpm file. You can use https://convertio.co/tr/jpg-xpm/
4 -) Name your xpm files as player, wall, coin and empty, just like the files in the so_long/textures directory. The program will not work if the names are different.
5 -) Remove the files in the textures directory and place your own xpm files there.
6 -) Run make and then run the program. You will see your uploaded images on the screen.
```
![Game View](https://github.com/MeNasy/so_long_linux/issues/1#issue-2123498410)
