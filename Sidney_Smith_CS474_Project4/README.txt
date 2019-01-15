Object Oriented Langueges and Environments - CS474
Sidney Smith - Project 4

----Installation----
This project was completed in visual studio. If you are using visual studio, just open the project file (.sln)
Otherwise, The following files need to be compiled together in order for the project to work

	----.cpp----
	Instruction.cpp
	main.cpp
	OneOperand.cpp
	TwoOperands.cpp

	-----.h-----
	Instruction.cpp
	OneOperand.cpp
	TwoOperands.cpp

These files can be found in the folder Sidney_Smith_CS474_Project4

The following files are resource files, make sure to have them in the same directory
	----.txt----
	test.txt
	test2.txt
	test100.txt



----Features----

	Legal commands:
	- i: Input file - Specify a file to read commands from
	- d: Debug - Execute on instruction at a time and display the value of the registers
	- r: Run - Execute an instruction sequence (up to 100 instructions)
	- c: Continue - Continues execution for an additional 100 instrucitons if 100 instructions are read
	- p: Print - Print the instruction sequece and the value of the registers
	- q: Quit - Exist the PC

For the structure of the input file, please refer to any of the resource files
