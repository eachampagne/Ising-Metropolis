# Ising-Metropolis
Class Project for University of Arizona PHYS 426

Summary:

For this project, we were assigned to simulate the flipping of magnetic spins using the metropolis algorithm. I chose to use C++ because it is faster than Python, and because I prefer strongly typed languages. Additionally, I chose to write an ensemble class with the 1d and 2d ensembles as children because I like OOP, and I'd been meaning to learn how classes work in C++ for a while and this seemed like a good time. Most of my files are dealing with these 3 classes. 1d.cpp and 2d.cpp contain the main functions. initcompiler.bat is the (very poor) batch file I wrote so that I could use the Visual Studio C++ compiler in the VS code terminal. I used GNUPlot (via Windows Subsystem for Linux) to produce my graphs.



Note that the GitHub user VenatorUmbrarum is listed as a collaborator on this project. That is my personal account (for my vague game dev aspirations) and it's included here because I was having issues with GitHub permissions and VS Code. Adding my other account as a collaborator was not the "right" way to fix this but it was the easiest.

~

The rest of the readme contains notes for myself, plus a rather out of date todo list.

~

TODO:

-Write summary of project above

-Fix my makefile to make the compilation process better 

-Create function to find neighbors of a given spin

-Find formulae for entropy, energy, etc.

-Create function to determine whether to flip a given spin

-Rest of the project

-For saving data, I could probably find an existing xml library to help

~

Running list of questions for this project:

-Generally make certain I know what I'm doing

-Can I post ANY of this to GitHub? - yes

-Can I post the instructions pdf to GitHub since this is resume material? Forgot to ask

-Can we/Should we give the link to the GitHub repository?

-Do we turn in code or just results? Makefiles? Does that mean energy, or the actual sequence of states?

-Do we have to have charts or our lattices? It would be nice but might be hard to accomplish...

-A way to save data would be nice, but would definitely affect effiency

--Save data! Energy, Cv, etc. Graphs are good.

-Any preferences on coding style? Is using classes okay? Inheritence? Does code optimization count for anything?

--Classes are fine

-Is there a definite size for lattice? Apparently 32; 32x32

-Any advice for randomly assigning the initial state?

--Also interesting to see particular starting conditions, all aligned, half and half, temperature

--High temp -> all aligned, low temp -> more random

-We have to do both 1D and 2D? (I think so)

-I assume there's a paper to answer questions, discuss results. Any particular formatting? Should we explicitly number the questions we are given?

--Doesn't care on formatting

-If you flip multiple spins at a time, do you either accept/reject all of them or accept/reject individually? What if some of the selected spins are neighbors?

--Same decision for all, definitely read the thing, they will be neighbors

--Can apply this algorithm to 1D

-What is J? How does J depend on T?

-There's a Cv equation from the 10/14 lecture that's probably useful

numba - Python library to compile functions in advance (Apparently Python is bad with nested loops, but I'm not using Python)

Done:
-Figure out random number generation
-Change current Ensemble class to a parent class with 1d and 2d children
--2d done, need to create 1d
-Create init functions for various starting configurations