/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoherfan <yoherfan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 10:55:36 by yoherfan          #+#    #+#             */
/*   Updated: 2025/12/05 14:07:41 by yoherfan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

#include <string>
#include <ostream>
#include <iostream>
#include <stdexcept>
#include <fstream>
#include <cstdlib>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
    private:

    std::string const	name;
    bool            	is_signed;
	int	const			grade_to_sign;
	int	const			grade_to_execute;

	public:
	
    AForm();
	AForm(AForm &f);
	AForm(std::string n, int gs, int ge);
	AForm &operator = (AForm const &value);
	~AForm();
	
	std::string getName() const;
	bool		getStatus() const;
	int			getGradeToSign() const;
	int			getGradeToExecute() const;

	void		beSigned(Bureaucrat b);
	virtual void execute(Bureaucrat const & executor) const = 0;

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

std::ostream &operator << (std::ostream &os, const AForm &b);


#endif