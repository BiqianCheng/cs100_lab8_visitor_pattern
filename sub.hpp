#ifndef __SUB_HPP__
#define __SUB_HPP__

#include "base.hpp"
#include "sub.hpp"
#include "binary_iterator.cpp"

class Sub : public Base
{
public:
    Sub(Base *Tx, Base *Ty) : Base()
    {
        x = Tx;
        y = Ty;
    }
    virtual double evaluate()
    {
        return x->evaluate() - y->evaluate();
    }
    virtual std::string stringify()
    {
        return x->stringify() + " - " + y->stringify();
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
    virtual void accept(CountVisitor* numTimesSub)
	{
		numTimesSub -> visit_sub();
	}

private:
    Base *x;
    Base *y;
};

#endif //