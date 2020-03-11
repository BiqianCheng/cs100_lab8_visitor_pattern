#ifndef __ADD_HPP__
#define __ADD_HPP__

#include "base.hpp"
#include "iterator.hpp"
#include "visitor.hpp"

class Add : public Base
{
public:
    Add(Base *Tx, Base *Ty) : Base()
    {
        x = Tx;
        y = Ty;
    }
    virtual double evaluate()
    {
        return x->evaluate() + y->evaluate();
    }
    virtual std::string stringify()
    {
        return x->stringify() + " + " + y->stringify();
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
    virtual void accept(CountVisitor* totalNumbersAdd)
	{
		totalNumbersAdd -> visit_add();
	}

private:
    Base *x;
    Base *y;
};

#endif //