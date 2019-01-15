#include "TwoOperands.h"
#include <math.h>

TwoOperands::TwoOperands()
{
	firstOperand = '!';
	secondOperand = '!';
	Operator = '!';

	x_ = nullptr;
	y_ = nullptr;
	w_ = nullptr;
	z_ = nullptr;

	equl = "";
}

TwoOperands::TwoOperands(std::string Whole, std::string Equ, std::string FirstOp, std::string Op, std::string SecondOp, double *X, double *Y, double *W, double *Z)
{
	//Set the equation for the entire string
	WholeEquation = Whole;

	//Get a pointer to the register that the expression will equal
	equl = Equ;

	//Get the string representation of the operands and the operator
	firstOperand = FirstOp;
	Operator = Op;
	secondOperand = SecondOp;

	//get pointers to the registers
	x_ = X;
	y_ = Y;
	w_ = W;
	z_ = Z;
}

TwoOperands::~TwoOperands()
{

}

void TwoOperands::execute()
{
	double FirstOpNum = 0;
	double SecondOpNum = 0;
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

	//Get the number representation of the second operand
	if (secondOperand == "x")
	{
		SecondOpNum = *x_;
	}

	else if (secondOperand == "y")
	{
		SecondOpNum = *y_;
	}

	else if (secondOperand == "w")
	{
		SecondOpNum = *w_;
	}

	else if (secondOperand == "z")
	{
		SecondOpNum = *z_;
	}

	else
	{
		SecondOpNum = std::stod(secondOperand);
	}


	//Do the computation based on the operator
	if (Operator == "+")
	{
		*equals = FirstOpNum + SecondOpNum;
		return;
	}

	else if (Operator == "-")
	{
		*equals = FirstOpNum - SecondOpNum;
		return;
	}

	else if (Operator == "*")
	{
		*equals = FirstOpNum * SecondOpNum;
		return;
	}

	else if (Operator == "/")
	{
		*equals = FirstOpNum / SecondOpNum;
		return;
	}

	else if (Operator == "**")
	{
		*equals = pow(FirstOpNum, SecondOpNum);
		return;
	}
}

std::string TwoOperands::print()
{
	return WholeEquation;
}
