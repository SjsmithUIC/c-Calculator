#include <string>

#pragma once
class Instruction
{
	public:

		//Public methods shared by all instructions
		virtual void execute() = 0;
		virtual std::string print() = 0;
	protected:

		//Variables shared by all instructions
		std::string WholeEquation;
		std::string equl;
		std::string firstOperand;
		std::string Operator;

		double *x_;
		double *y_;
		double *w_;
		double *z_;

	private:
};

