#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include "Instruction.h"
#include "OneOperand.h"
#include "TwoOperands.h"

//Forward declarations of main methods
void FileInput(std::vector<Instruction *> &temp,int &Index, double *x, double *y, double *w, double *z);
void RunSequence(std::vector<Instruction *> &temp, int &Index, double &x, double &y, double &w, double &z);
void DebugSequence(std::vector<Instruction *> &temp, int &Index, double &x, double &y, double &w, double &z);

int main()
{
	//Variable for the instruction stack and user input
	int StackIndex = 0;
	std::vector<Instruction*> InstructionStack;
	std::string UserInput;

	//Register variables
	double x = 0;
	double y = 0;
	double w = 0;
	double z = 0;

	//Read command loop
	while (UserInput != "q")
	{
		std::cout << "Welcome to the Programmable calculator! \n";
		std::cout << "Legal commands: \n\n";
		std::cout << "- i: Input file - Specify a file to read commands from\n";
		std::cout << "- d: Debug - Execute on instruction at a time and display the value of the registers \n";
		std::cout << "- r: Run - Execute an instruction sequence (up to 100 instructions)\n";
		std::cout << "- c: Continue - Continues execution for an additional 100 instrucitons if 100 instructions are read\n";
		std::cout << "- p: Print - Print the instruction sequece and the value of the registers \n";
		std::cout << "- q: Quit - Exist the PC \n";
		std::cout << "\n:";

		std::getline(std::cin, UserInput);

		if (UserInput == "i")
		{
			FileInput(InstructionStack, StackIndex, &x, &y, &w, &z);
		}

		else if (UserInput == "d")
		{
			system("CLS");
			if (InstructionStack.size() == 0)
			{
				std::cout << "No instructions loaded \n\n";
			}

			else
			{
				DebugSequence(InstructionStack, StackIndex, x, y, w, z);
			}
		}

		else if (UserInput == "r")
		{
			system("CLS");
			if (InstructionStack.size() == 0)
			{
				std::cout << "No instructions loaded \n\n";
			}

			else
			{
				RunSequence(InstructionStack, StackIndex, x, y, w, z);
			}
		}

		else if (UserInput == "c")
		{
			system("CLS");
			std::cout << "This is only a valid command after running 100 instructions \n";
		}

		else if (UserInput == "p")
		{
			system("CLS");
			int i = 0;
			while (i < InstructionStack.size())
			{
				std::cout << (i + 1) << ": " << InstructionStack[i]->print() << "\n";
				i++;
			}

			std::cout << "x:" << x << " y:" << y << " w:" << w << " z:" << z << "\n\n";
		}

		else if (UserInput == "q")
		{
			std::cout << "Bye!";
			return 0;
		}

		else
		{
			system("CLS");
		}
	}

	return 0;
}

//Opens a specified file and reads commands from it
void FileInput(std::vector<Instruction *> &temp, int &Index, double *x, double *y, double *w, double *z)
{
	temp.clear();
	//Get the file name from input
	std::string fileInput;
	system("CLS");
	std::cout << "Please enter a file including the .txt extention (EX: test.txt): ";
	std::getline(std::cin, fileInput);

	//Attempt to open the file
	std::ifstream InstFile;
	InstFile.open(fileInput);

	if (InstFile.is_open())
	{
		//Get the instructions from the file
		std::string InstrInput;
	
		while (std::getline(InstFile, InstrInput))
		{
			//Save the string to store in the equation
			std::string Save = InstrInput;

			//get rid of the period
			InstrInput.erase(std::remove(InstrInput.begin(), InstrInput.end(), '.'), InstrInput.end());

			std::string del = " ";
			std::string token;
			size_t pos = 0;

			//separate the string by spaces and put each item in a vector
			std::vector<std::string> Inputs;
			while ((pos = InstrInput.find(del)) != std::string::npos)
			{
				token = InstrInput.substr(0, pos);
				Inputs.push_back(token);
				InstrInput.erase(0, pos + del.length());
			}

			Inputs.push_back(InstrInput);

			//If the vecotr has five items, it must have two operands
			if (Inputs.size() == 5)
			{	
				TwoOperands *tempI = new TwoOperands(Save, Inputs[0], Inputs[2], Inputs[3], Inputs[4], x, y, w, z);
				temp.push_back(tempI);
			}

			//If the vector has three items, it must have only one operand
			else if (Inputs.size() == 3)
			{
				OneOperand *tempI = new OneOperand(Save, Inputs[0], Inputs[1], Inputs[2], x, y, w, z, &temp, &Index);
				temp.push_back(tempI);
			}
		}

		std::cout << "File loaded successfully! \n\n";
		Index = 0;
		return;
	}

	std::cout << "ERROR: Could not open file \n\n";
}

void RunSequence(std::vector<Instruction *> &temp, int &Index, double &x, double &y, double &w, double &z)
{
	int j = 1;

	while (Index < temp.size())
	{
		//Execute the instruction
		temp[Index]->execute();

		//If the instruction is the 100th. ask the user to continue
		if (j % 100 == 0 && j)
		{
			std::string input;
			std::cout << "100 instructions reached. To continue computation, enter c. To dubug, enter d: ";
			std::getline(std::cin, input);

			//If the user inputs c, continue
			if (input == "c")
			{
				//Continue the operations
			}

			//If the user inputs d, enter debug mode at the index
			else if (input == "d")
			{
				DebugSequence(temp, Index, x, y, w, z);
				return;
			}

			//if anything else is entered, return
			else
			{
				std::cout << "\nInstruction sequence stoped and saved at index \n\n";
				return;
			}
		}

		Index = Index + 1;
		j = j + 1;
	}

	std::cout << "x:" << x << " y:" << y << " w:" << w << " z:" << z << "\n";
	std::cout << "\nInstruction sequence complete! Sequence reset\n\n";
	Index = 0;
	return;
}

void DebugSequence(std::vector<Instruction *> &temp, int &Index, double &x, double &y, double &w, double &z) 
{
	std::string wait;
	while (Index < temp.size())
	{
		std::cout << temp[Index]->print() << "\n";
		temp[Index]->execute();
		std::cout << "x:" << x << " y:" << y << " w:" << w << " z:" << z << " Index Position: " << Index << "\n\n";

		std::cout << "enter r to run from index, or any other button to continue: ";
		std::getline(std::cin, wait);

		//Move to the next index
		Index = Index + 1;

		if (wait == "r")
		{
			RunSequence(temp, Index, x, y, w, z);
			return;
		}
	}

	std::cout << "\nInstruction sequence complete! Sequence reset \n\n";
	Index = 0;
	return;
}