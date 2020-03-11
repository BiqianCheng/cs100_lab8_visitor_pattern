#ifndef __RAND_HPP__
#define __RAND_HPP__

#include "base.hpp"
#include "iterator.hpp"

class Rand : public Base
{
public:
    Rand() : Base() {}
    virtual double evaluate()
    {
        return myValue;
    }
    virtual std::string stringify()
    {
        return std::to_string(myValue);
    }
    virtual NullIterator *create_iterator()
    {
        return new NullIterator(this);
    }

    virtual Base *get_left()
    {
        return nullptr;
    }
    virtual Base *get_right()
    {
        return nullptr;
    }
    virtual void accept(CountVisitor* numTimesRand)
	{
		numTimesRand -> visit_rand();
	}

private:
    double myValue = rand() % 100;
};

#endif //__RAND_HPP__
