#ifndef __OP_HPP__
#define __OP_HPP__

#include "base.hpp"
#include "iterator.hpp"

class Op : public Base
{
public:
    Op(double value) : Base()
    {
        myValue = value;
    }
    virtual double evaluate()
    {
        return myValue;
    }
    virtual std::string stringify()
    {
        return std::to_string(myValue);
    }
    virtual NullIterator *create_iterator()
    {
        return new NullIterator(this);
    }

    virtual Base* get_left()
	{
		return nullptr;
	}
    virtual Base* get_right()
	{
		return nullptr;
	}
    virtual void accept(CountVisitor* numTotalOp)
	{
		numTotalOp -> visit_op();
	}

private:
    double myValue;
};

#endif //__OP_HPP__
