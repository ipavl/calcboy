CalcBoy
=======

A basic calculator for the Nintendo Game Boy.

Compilation
-----------

You'll need a set of the Game Boy header files and a compiler such as 
`lcc`. Luckily, all you need to do to get these is download a copy of 
[GBDK](http://gbdk.sourceforge.net/).

Set up GBDK, and then edit the `makefile`/`make.bat` file (depending on 
your system) to reflect the location of `lcc` - you can optionally add it to 
your system's PATH variable if you think you'll be doing a lot of GB 
development of your own. The default location for `lcc` in the makefile 
is `../../bin/lcc` from the project's working directory as my set up 
was to have a "projects" directory with a sub-directory for each 
project below the main "gbdk" directory.

The version of GBDK at the time this program was created was 
**2.95-3**.

Usage
=====

Once you compile the `calcboy.c` file, you should have a `calcboy.gb` 
file. This file is suitable for use on an emulator, such as VBA-M, or 
(theoretically), a real Game Boy. I don't have all of the tools 
required to test on a real system, however.

Once starting the "game", you'll be immediately greeted with the 
calculator itself. The controls are:

* Left: Decrease input 1's value

* Right: Increase input 1's value

* Up: Increase input 2's value

* Down: Decrease input 2's value

* Select: Cycle operations

* Start: Process calculation (input1 OPERATION input2 -> answer)

Features
--------

* Addition

* Subtraction

* Multiplication

* Division

Bugs/Missing features
---------------------

* Division produces integers instead of numbers with decimals (e.g. 
18/15 = 1 instead of 1.2)

* Overflow is not really handled (careful with negatives and anything 
resulting in or involving numbers >65535)

* Input selection is a bit difficult if you're trying to 
increment/decrement a number by small values (e.g. 1) as each press 
alters the number by much more than that due to the way input is 
handled

These might be fixed some day.
