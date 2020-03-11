#ifndef __DIV_HPP__
#define __DIV_HPP__

#include "iterator.hpp"
#include "base.hpp"

class Div : public Base
{
public:
    Div(Base *Tx, Base *Ty) : Base()
    {
        x = Tx;
        y = Ty;
    }
    virtual double evaluate()
    {
        return x->evaluate() / y->evaluate();
    }
    virtual std::string stringify()
    {
        return x->stringify() + " / " + y->stringify();
    }
    virtual BinaryIterator *create_iterator()
    {
        return new BinaryIterator(this);
    }
    virtual Base* get_left()
	{
		return x;
	}
    virtual Base* get_right()
	{
		return y;
	}

    virtual void accept(CountVisitor* numTimesDiv)
	{
		numTimesDiv -> visit_div();
	}

private:
    Base *x;
    Base *y;
};

#endif