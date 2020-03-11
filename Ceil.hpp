#ifndef __CEIL_HPP__
#define __CEIL_HPP__

#include "decorator.hpp"
#include "iterator.hpp"
#include "visitor.hpp"
#include <cmath>

class Ceiling : public Decorator
{
public:
	Ceiling(Base *deco) : Decorator(deco) {}
	virtual double evaluate()
	{
		return ceil(deco->evaluate());
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

	virtual void accept(CountVisitor* totalNumCeil)
	{
		totalNumCeil -> visit_ceil();
	}
};

#endif
