/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoherfan <yoherfan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 10:55:36 by yoherfan          #+#    #+#             */
/*   Updated: 2025/12/05 10:39:52 by yoherfan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include <string>
#include <ostream>
#include <iostream>
#include <stdexcept>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
    private:

    std::string const	name;
    bool            	is_signed;
	int	const			grade_to_sign;
	int	const			grade_to_execute;

	public:
	
    Form();
	Form(std::string n, int gs, int ge);
	Form(Form &f);
	Form &operator = (Form const &value);
	~Form();
	
	std::string getName() const;
	bool		getStatus() const;
	int			getGradeToSign() const;
	int			getGradeToExecute() const;

	void		beSigned(Bureaucrat b);

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

std::ostream &operator << (std::ostream &os, const Form &b);


#endif