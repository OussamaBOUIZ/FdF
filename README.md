# FdF Wireframe Model or 'Fil de Fer'

This C project is about devising a program which overall displays a **3D representation**,
precisely a wirefram model of a given map. Essentially, it converts an ordinary text file (so-called : Map) into a visual material in a window using the 42 school graphical library: the MiniLibx. Its a discovery of basics of **graphics programming**, notably how to position dots in space and how to link them.

## The program consists of three major steps:
### Parsing the Map:
The program reads the Map after primarly assuring its validity and produces an organized data structure upon which relies the drawing functions. How is that done ? Let's see first what is Map

	0 0 1 2 3 4 5 6 7 8 9
	0 0 0 1 2 3 4 5 6 7 8
	0 0 0 0 1 2 3 4 5 6 7
	0 0 0 0 0 1 2 3 4 5 6
	0 0 0 0 0 0 1 2 3 4 5
	0 0 0 0 0 0 0 1 2 3 4
	0 0 0 0 0 0 0 0 1 2 3
	0 0 0 0 0 0 0 0 0 1 2
	0 0 0 0 0 0 0 0 0 0 1

For each single string in this map, the program forms a structure as below:

	typedef struct s_iso
	{
		double	x;
		double	y;
		int		clr;
	}				t_iso;




