/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoherfan <yoherfan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 09:27:25 by yoherfan          #+#    #+#             */
/*   Updated: 2025/12/03 08:55:10 by yoherfan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <string>
#include <iostream>

class Animal
{    
    
    protected:

    std::string type;

    public:
    
    Animal();
    Animal(Animal &a);
    
    virtual void        makeSound() const = 0;
    std::string getType() const;
    
    virtual ~Animal();

    Animal &operator=(Animal const &value);
};

#endif