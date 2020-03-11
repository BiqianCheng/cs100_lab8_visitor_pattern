#ifndef __DECORATOR_HPP__
#define __DECORATOR_HPP__

#include "base.hpp"
#include "unary_iterator.cpp"
#include <cmath>

class Decorator : public Base
{
protected:
    Base *deco;

public:
    Decorator(Base *deco) : Base()
    {
        this->deco = deco;
    }
    virtual double evaluate()
    {
        return deco->evaluate();
    }
    virtual std::string stringify(){
        return deco->stringify();
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
};

#endif
