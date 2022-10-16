# FdF Wireframe Model or 'Fil de Fer'

This C project is about devising a program which overall displays a **3D representation**,
precisely a wirefram model of a given map. Essentially, it converts an ordinary text file (so-called : Map) into a visual material in a window using the 42 school graphical library: the MiniLibx. Its a discovery of basics of **graphics programming**, notably how to position dots in space and how to link them.

## The program consists of Two major steps:
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
	}		t_iso;

This structure composes an element of a 2D array. 
As We are building a **3D representation (isometric projection)**, from each single number in the map, the program retrieves the x, y, z and color values. The **x** is the position of the string horizantally, the **y** is its  position vertically, the **z** its value, and the color in case there is one, which is usually added after a **","** to the number, otherwise there's a default color declared in the header file. Indeed, the wireframe is displayed in a window which is obviously 2D. So to get this 3d illusion in 2D plan, We take the 3 coordinates and deduce from them the convenient 2 values for a 2D plan, by converting from **Cartesian** to **Isometric** which I have done this way;

	iso_X = X + Y;
	iso_Y = (X + Y) * 3 / 4 - Z;

By The end of this process, we get a decent compound data structure containing basically the coordinates of all the dots composing the map, so in order to get the whole wireframe we should connect the dots, which takes us to the second step.

### Linking The Dots:
 Practically each dot gets linked to its **right neighbor** and its **south neighbor**. Connecting two points is basically drawing a **line segment** in which those two points both are starting and stopping points and this drawing is implemented through the [*Bresenham Algorithm*](https://en.wikipedia.org/wiki/Bresenham%27s_line_algorithm).
<br/>
The reader may be wondering: *What about these ending points in the map which don't have neighbors?*

The answer:
Too simply, the program determines the position of a given dot, and decides upon that if it should be linked to its neighbor or not.




