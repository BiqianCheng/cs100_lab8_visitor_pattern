#ifndef __PAREN_HPP__
#define __PAREN_HPP__

#include "decorator.hpp"
#include "iterator.hpp"
#include "visitor.hpp"
#include <cmath>

class Paren : public Decorator
{
public:
	Paren(Base *deco):Decorator(deco){};

	virtual std::string stringify()
	{
		return "(" + deco -> stringify()+")";
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
	virtual void accept(CountVisitor* totalNumParen)
	{
		totalNumParen -> visit_paren();
	}

};

#endif
