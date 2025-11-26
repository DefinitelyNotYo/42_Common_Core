/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoherfan <yoherfan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 09:12:09 by yoherfan          #+#    #+#             */
/*   Updated: 2025/11/13 10:35:08 by yoherfan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

class Ice : public AMateria
{
    public:

    Ice();
    ~Ice();
	Ice(Ice &value);
	Ice &operator=(Ice const &value);

    Ice *clone() const;
    void use(ICharacter& target);
};