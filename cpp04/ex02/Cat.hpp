#ifndef CAT_HPP
#define CAT_HPP

#include "AAnimal.hpp"

class Cat : public AAnimal
{
private:
    Brain* brain;
public:
    Cat();
    Cat(std::string name);
    Cat(const Cat& other);
    Cat& operator=(const Cat& other);
    ~Cat();

public:
    void makeSound( void ) const ;
    Brain* getBrain() const;
    void setIdea(int index, std::string idea);
    std::string getIdea(int index) const;
};


#endif