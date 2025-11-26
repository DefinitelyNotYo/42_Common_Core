/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoherfan <yoherfan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 09:12:28 by yoherfan          #+#    #+#             */
/*   Updated: 2025/11/13 13:31:56 by yoherfan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
    public:
    
    AMateria *materia_tab[4];
    int       materia_tab_pin;
    
    MateriaSource();
    ~MateriaSource();
    MateriaSource(MateriaSource &m);
    MateriaSource &operator=(MateriaSource const &value);
    
    void learnMateria(AMateria*);
    AMateria* createMateria(std::string const & type);
};


#endif