/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoherfan <yoherfan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 14:54:57 by yoherfan          #+#    #+#             */
/*   Updated: 2025/12/05 15:25:14 by yoherfan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

class AForm;
class PresidentialPardonForm;
class ShrubberyCreationForm;
class RobotomyRequestForm;

class Intern
{
    public:

    Intern();
    Intern(Intern &i);
	Intern &operator = (Intern const &value);
    ~Intern();

    AForm *makeForm(std::string form_name, std::string target);

    class InvalidForm : public std::exception
	{
		public:
		
		const char *what() const throw();
	};
};

#endif