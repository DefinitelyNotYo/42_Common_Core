/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoherfan <yoherfan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 09:27:36 by yoherfan          #+#    #+#             */
/*   Updated: 2025/11/11 14:50:05 by yoherfan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
    private:

    Brain *brain;
    
    public:
    
    void    makeSound() const;

    Dog();
    virtual ~Dog();
    Dog(Dog &c);

    Dog &operator=(Dog const &value);
};

#endif