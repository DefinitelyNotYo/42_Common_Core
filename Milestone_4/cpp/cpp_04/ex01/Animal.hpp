/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoherfan <yoherfan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 09:27:25 by yoherfan          #+#    #+#             */
/*   Updated: 2025/11/11 14:54:04 by yoherfan         ###   ########.fr       */
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
    
    virtual void        makeSound() const;
    std::string getType() const;
    
    Animal();
    virtual ~Animal();
    Animal(Animal &a);

    Animal &operator=(Animal const &value);
};

#endif