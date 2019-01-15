#include <string>
#include "Instruction.h"

#pragma once
class TwoOperands: public Instruction
{
	public:
		TwoOperands();
		TwoOperands(std::string Whole, std::string Equ, std::string FirstOp, std::string Op, std::string SecondOp, double *X, double *Y, double *W, double *Z);
		void execute();
		std::string print();
		~TwoOperands();
	private:
		std::string secondOperand;

	protected:
};

