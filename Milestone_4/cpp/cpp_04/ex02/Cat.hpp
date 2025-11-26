/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoherfan <yoherfan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 09:27:31 by yoherfan          #+#    #+#             */
/*   Updated: 2025/11/11 14:12:48 by yoherfan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
    private:

    Brain *brain;

    public:
    
    void    makeSound() const;

    Cat();
    virtual ~Cat();
    Cat(Cat &c);

    Cat &operator=(Cat const &value);
};

#endif