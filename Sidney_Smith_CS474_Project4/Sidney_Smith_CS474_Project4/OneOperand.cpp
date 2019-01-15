#include <iostream>
#include "OneOperand.h"

OneOperand::OneOperand()
{
	firstOperand = '!';
	Operator = '!';

	x_ = nullptr;
	y_ = nullptr;
	w_ = nullptr;
	z_ = nullptr;

	equl = "";
}

OneOperand::OneOperand(std::string Whole, std::string Equ, std::string Op, std::string FirstOp, double *X, double *Y, double *W, double *Z, std::vector<Instruction*> *temp, int *Index)
{
	//Set the equation for the entire string
	WholeEquation = Whole;

	//Get a pointer to the register that the expression will equal
	equl = Equ;

	//Get the string representation of the operands and the operator
	firstOperand = FirstOp;
	Operator = Op;

	//get pointers to the registers
	x_ = X;
	y_ = Y;
	w_ = W;
	z_ = Z;

	//Store the execute stack and stack index
	ExecutionStack = temp;
	index = Index;
}

OneOperand::~OneOperand()
{

}

void OneOperand::execute()
{
	double FirstOpNum = 0;
	double *equals = nullptr;

	//set the register that the expression will equal
	if (equl == "x")
	{
		equals = x_;
	}

	else if (equl == "y")
	{
		equals = y_;
	}

	else if (equl == "w")
	{
		equals = w_;
	}

	else if (equl == "z")
	{
		equals = z_;
	}


	//Get the number representation of the first operand
	if (firstOperand == "x")
	{
		FirstOpNum = *x_;
	}

	else if (firstOperand == "y")
	{
		FirstOpNum = *y_;
	}

	else if (firstOperand == "w")
	{
		FirstOpNum = *w_;
	}

	else if (firstOperand == "z")
	{
		FirstOpNum = *z_;
	}

	else
	{
		FirstOpNum = std::stod(firstOperand);
	}

	//Do the computation based on the operator
	if (Operator == "=")
	{
		*equals = FirstOpNum;
		return;
	}

	else if (Operator == "?")
	{
		if (*equals != 0)
		{
			((*ExecutionStack)[FirstOpNum - 1])->execute();
			(*index) = (*index) + 1;
		}
	}
}

std::string OneOperand::print()
{
	return WholeEquation;
}
