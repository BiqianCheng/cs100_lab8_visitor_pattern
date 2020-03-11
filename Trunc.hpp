#ifndef __TRUNC_HPP__
#define __TRUNC_HPP__

#include "decorator.hpp"
#include "iterator.hpp"
#include "visitor.hpp"
#include <cmath>

class Trunc : public Decorator
{
public:
    Trunc(Base *deco) : Decorator(deco){};

    virtual std::string stringify()
    {
        return std::to_string(deco->evaluate());
    }
    virtual UnaryIterator *create_iterator()
    {
        return new UnaryIterator(this);
    }

    virtual Base* get_left()
	{
		return deco;
	}
    virtual Base* get_right()
	{
		return nullptr;
	}

    virtual void accept(CountVisitor* totalNumTrunc)
	{
		totalNumTrunc -> visit_abs();
	}
};


#endif
