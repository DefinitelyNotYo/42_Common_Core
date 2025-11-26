/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoherfan <yoherfan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 09:27:40 by yoherfan          #+#    #+#             */
/*   Updated: 2025/11/11 11:46:52 by yoherfan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include <string>
#include <iostream>

class WrongAnimal
{
    protected:
    
    std::string type;

    public:
    
    void    makeSound() const;
    std::string getType() const;
    
    WrongAnimal();
    ~WrongAnimal();
    WrongAnimal(WrongAnimal &a);

    WrongAnimal &operator=(WrongAnimal const &value);
};

#endif