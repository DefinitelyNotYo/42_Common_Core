/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoherfan <yoherfan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 09:04:04 by yoherfan          #+#    #+#             */
/*   Updated: 2025/12/05 10:39:43 by yoherfan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include <ostream>
#include <stdexcept>
#include "Form.hpp"

class Form;

class Bureaucrat
{
    private:
    
    std::string const	name;
    int         		grade;

	public:

	Bureaucrat();
	Bureaucrat(std::string n, int g);
	Bureaucrat(Bureaucrat &b);
	Bureaucrat &operator = (Bureaucrat const &value);
	~Bureaucrat();
	
	std::string getName() const;
	int			getGrade() const;

	void		inc_grade();
	void		dec_grade();

	void		signForm(Form &f);
	
	class GradeTooHighException : public std::exception
	{
		public:
		
		const char *what() const throw();
	};
	
	class GradeTooLowException : public std::exception
	{
		public:
		
		const char *what() const throw();
	};
};

std::ostream &operator << (std::ostream &os, const Bureaucrat &b);

#endif