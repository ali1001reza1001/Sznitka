/**
 * @file SecondFactory.h
 * @author julia
 *
 *
 */
 
#ifndef SECONDFACTORY_H
#define SECONDFACTORY_H
#include <complex.h>

class Actor;

/**
 * Factory class that builds the second character
 */
class SecondFactory {
private:

public:
 std::shared_ptr<Actor> Create(std::wstring imagesDir);
};



#endif //SECONDFACTORY_H
