/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoherfan <yoherfan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 09:12:26 by yoherfan          #+#    #+#             */
/*   Updated: 2025/12/03 10:09:49 by yoherfan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
    materia_tab_pin = 0;
    materia_tab[0] = NULL;
    materia_tab[1] = NULL;
    materia_tab[2] = NULL;
    materia_tab[3] = NULL;
}

MateriaSource::MateriaSource(MateriaSource &m)
{
    *this = m;
}

MateriaSource::~MateriaSource()
{
    // int i = -1;
    // while (++i < 4)
    // {
    //     if (materia_tab[i])
    //         delete (materia_tab[i]);
    // }
}

MateriaSource &MateriaSource::operator=(MateriaSource const &value)
{
    (void)value;
    return (*this);
}

void MateriaSource::learnMateria(AMateria* m)
{
    int i = -1;
    while (++i < 4)
        if (materia_tab[i])
            if (materia_tab[i]->getType() == m->getType())
            {
                delete m;
                return ;
            }
    materia_tab[materia_tab_pin] = m->clone();
    if (materia_tab_pin == 3)
        materia_tab_pin = 0;
    else
        materia_tab_pin++;
    delete m;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
    int i = 0;
    while (i < 4 && materia_tab[i])
    {
        if (materia_tab[i]->getType() == type)
            return (materia_tab[i]);
        i++;       
    }
    return (0);
}