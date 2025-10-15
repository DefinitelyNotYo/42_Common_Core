/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoherfan <yoherfan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 15:08:21 by yoherfan          #+#    #+#             */
/*   Updated: 2025/10/01 16:15:22 by yoherfan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

class Fixed
{
    private:
    int					fixed_point_value;
	static const int	fractional_bits = 8;
    
    public:
	
		Fixed();
		Fixed(Fixed &value);
		Fixed &operator=(Fixed const &fpv);
		~Fixed();

		int getRawBits(void) const;
		void setRawBits(int const raw);
};