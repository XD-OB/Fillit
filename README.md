# FILLIT

Fillit is a project that let you discover and/or familiarize yourself with a recurring problematic in programming: searching the optimal solution among a huge set of possibilities, in a respectable timing. In this particular project, you will have to find a way to assemble a given Tetriminos set altogether in the smallest possible square.
A Tetriminos is a 4-blocks geometric figure you probably already heard of, thanks to the popular game Tetris.
Fillit is not about recoding Tetris, even if it’s still a variant of this game. Your program will take a file as parameter, which contains a list of Tetriminos, and arrange them in order to create the smallest square possible.
Obviously, your main goal is to find the smallest square in the minimal amount of time,despite an exponentially growing number of possibilities each time a piece is added.

## Compiling
Run `make`

## Usage
`./fillit [file]`

Example:
```
~ ./fillit samples/test_8

.AABB..
AACCB..
.CC.BDD
.EE.DD.
EEFFGG.
.FFGGHH
....HH.
```

# Owners
- Oussama Belouche 1337
- Anas Elouargui   1337
