/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoherfan <yoherfan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 09:11:37 by yoherfan          #+#    #+#             */
/*   Updated: 2025/11/13 15:13:15 by yoherfan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria()
{
    
}

AMateria::~AMateria()
{
    
}

AMateria::AMateria(AMateria &value)
{
    (void)value;
}

AMateria &AMateria::operator=(AMateria const &value)
{
    (void)value;
    return (*this);
}

std::string const &AMateria::getType() const
{
    return (type);
}

void AMateria::use(ICharacter& target)
{
    (void)target;
}

AMateria::AMateria(std::string const & type)
{
    this->type = type;
}