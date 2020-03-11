#ifndef __ABS_HPP__
#define __ABS_HPP__

#include "decorator.hpp"
#include "iterator.hpp"
#include "visitor.hpp"
#include <cmath>

class Absolute : public Decorator
{
public:
	Absolute(Base *deco) : Decorator(deco){};
	virtual double evaluate()
	{
		return fabs(deco->evaluate());
	}
	virtual UnaryIterator* create_iterator()
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

	virtual void accept(CountVisitor* absValue)
	{
		absValue -> visit_abs();
	}
};

#endif
