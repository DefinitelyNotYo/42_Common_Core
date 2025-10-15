/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoherfan <yoherfan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 15:08:21 by yoherfan          #+#    #+#             */
/*   Updated: 2025/10/02 16:45:37 by yoherfan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <cmath>

class Fixed
{
    private:
    int					fixed_point_value;
	static const int	fractional_bits = 8;

    public:

		Fixed();
		Fixed(Fixed const &value);
		Fixed(const int value);
		Fixed(const float value);

		Fixed &operator=(Fixed const &fpv);

		bool	operator>(Fixed const &fpv);
		bool	operator<(Fixed const &fpv);
		bool	operator>=(Fixed const &fpv);
		bool	operator<=(Fixed const &fpv);
		bool	operator==(Fixed const &fpv);
		bool	operator!=(Fixed const &fpv);

		Fixed	operator+(Fixed const &fpv);
		Fixed	operator-(Fixed const &fpv);
		Fixed	operator*(Fixed const &fpv);
		Fixed	operator/(Fixed const &fpv);

		Fixed	&operator++();
		Fixed	operator++(int);
		Fixed	&operator--();
		Fixed	operator--(int);

		static Fixed		&min(Fixed &a, Fixed &b);
		static Fixed const	&min(Fixed const &a, Fixed const &b);
		static Fixed		&max(Fixed &a, Fixed &b);
		static Fixed const	&max(Fixed const &a, Fixed const &b);

		~Fixed();

		int 	getRawBits(void) const;
		void 	setRawBits(int const raw);
		float	toFloat() const;
		int		toInt() const;
};

std::ostream &operator<<(std::ostream &os, const Fixed &value);