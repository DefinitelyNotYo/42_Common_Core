/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoherfan <yoherfan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 09:11:40 by yoherfan          #+#    #+#             */
/*   Updated: 2025/11/13 09:53:29 by yoherfan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP


#include <string>
#include <iostream>
#include "ICharacter.hpp"

class AMateria
{
    protected:

	std::string type;

	AMateria();
	AMateria(AMateria &value);
	~AMateria();
	AMateria &operator=(AMateria const &value);
	
    public:

    AMateria(std::string const & type);
    std::string const &getType() const; //Returns the materia type
    virtual AMateria* clone() const = 0;
    virtual void use(ICharacter& target);
};

#endif