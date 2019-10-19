# Descrition
Fillit is not about recoding Tetris, even if it’s still a variant of this game. Your program will take a file as parameter, which contains a list of Tetriminos, and arrange themin order to create the smallest square possible.

Obviously, your main goal is to find the smallest square in the minimal amount of time,despite an exponentially growing number of possibilities each time a piece is added.

You should think carefully about how you will structure your data and how to solvethis problem, if you want your program answers before the next millenium.

## Examples

Install program using `make`, executable file will have name `fillit`.
After installing you have to create file with figure valid* figures like this `example.txt`:
```
....
.##.
.#..
.#..

.#..
.##.
.#..
....

....
.#..
##..
.#..

.#..
.##.
.#..
....

..#.
.##.
.#..
....
```
\*Valid means that every figure has size 4x4 and consists of 4 '#' with shape as in real tetris

After creating a file you can use program to find the smallest square to place all the input figures.
Example:
```
>./fillit example.txt

AACB.
ACCBB
ADCBE
.DDEE
.D.E.
```
Program numerate the figures in input order.
