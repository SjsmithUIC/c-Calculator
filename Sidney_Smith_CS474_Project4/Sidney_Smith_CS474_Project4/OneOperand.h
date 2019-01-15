#include <string>
#include <vector>
#include "Instruction.h"

#pragma once
class OneOperand : public Instruction
{
	public:
		OneOperand();
		OneOperand(std::string Whole, std::string Equ, std::string Op, std::string FirstOp, double *X, double *Y, double *W, double *Z, std::vector<Instruction*> *temp, int *Index);
		void execute();
		std::string print();
		~OneOperand();
	protected:
	private:
		std::vector<Instruction*> *ExecutionStack;
		int *index;
};

