/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoherfan <yoherfan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 09:11:53 by yoherfan          #+#    #+#             */
/*   Updated: 2025/11/13 10:40:57 by yoherfan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

class Cure : public AMateria
{
    public:

    Cure();
    ~Cure();
	Cure(Cure &value);
	Cure &operator=(Cure const &value);

    Cure *clone() const;
    void use(ICharacter& target);
};