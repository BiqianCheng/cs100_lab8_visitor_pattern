#ifndef __FLOOR_HPP__
#define __FLOOR_HPP__

#include "decorator.hpp"
#include "iterator.hpp"
#include "visitor.hpp"
#include <cmath>

class Floor : public Decorator
{
public:
	Floor(Base *deco) : Decorator(deco) {}
	virtual double evaluate()
	{
		return floor(deco->evaluate());
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
	virtual void accept(CountVisitor* numTotalFloor)
	{
		numTotalFloor -> visit_floor();
	}
};

#endif
