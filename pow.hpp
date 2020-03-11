#ifndef __POW_HPP__
#define __POW_HPP__

#include "base.hpp"
#include "iterator.hpp"
#include "visitor.hpp"
#include <math.h>

class Pow : public Base
{
public:
    Pow(Base *Tx, Base *Ty) : Base()
    {
        x = Tx;
        y = Ty;
    }
    virtual double evaluate()
    {
        return pow(x->evaluate(), y->evaluate());
    }
    virtual std::string stringify()
    {
        return x->stringify() + " ** " + y->stringify();
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

    virtual void accept(CountVisitor* numTimesPow)
	{
		numTimesPow -> visit_pow();
	}

private:
    Base *x;
    Base *y;
};

#endif //