/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoherfan <yoherfan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 09:12:26 by yoherfan          #+#    #+#             */
/*   Updated: 2025/11/13 13:44:43 by yoherfan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
    materia_tab_pin = 0;
}

MateriaSource::MateriaSource(MateriaSource &m)
{
    *this = m;
}

MateriaSource::~MateriaSource()
{
    
}

MateriaSource &MateriaSource::operator=(MateriaSource const &value)
{
    return (*this);
}

void MateriaSource::learnMateria(AMateria* m)
{
    materia_tab[materia_tab_pin] = m;
    if (materia_tab_pin == 3)
        materia_tab_pin = 0;
    else
        materia_tab_pin++;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
    int i = -1;
    while (++i < 4)
        if (materia_tab[i]->getType() == type)
            return (materia_tab[i]);
    return (0);
}