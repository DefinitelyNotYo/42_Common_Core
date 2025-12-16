/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoherfan <yoherfan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 09:04:01 by yoherfan          #+#    #+#             */
/*   Updated: 2025/12/05 10:39:35 by yoherfan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("name_placeholder")
{
	grade = 150;
}

Bureaucrat::Bureaucrat(std::string n, int g) : name(n)
{
	if (g > 150)
		throw Bureaucrat::GradeTooLowException();
	if (g < 1)
		throw Bureaucrat::GradeTooHighException();
	grade = g;
}
    
Bureaucrat::Bureaucrat(Bureaucrat &b) : name(b.name)
{
	grade = b.grade;
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &value)
{
	if (this == &value)
		return (*this);
	grade = value.grade;
	return (*this);
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &b)
{
	os << b.getName() << ", bureaucrat grade " << b.getGrade() << std::endl;
	return (os);
}

Bureaucrat::~Bureaucrat()
{
	
}
	
std::string Bureaucrat::getName() const
{
	return name;
}

int Bureaucrat::getGrade() const
{
	return grade;
}

void Bureaucrat::inc_grade()
{
	if (grade - 1 < 0)
		throw Bureaucrat::GradeTooHighException();
	grade -= 1;
}

void Bureaucrat::dec_grade()
{
	if (grade + 1 > 150)
		throw Bureaucrat::GradeTooLowException();
	grade += 1;
}

void Bureaucrat::signForm(Form &f)
{
	try
	{
		f.beSigned(*this);
		std::cout << "Bureaucrat " << name << " signed " << f.getName() << " form\n";
	}
	catch(const std::exception &e)
	{
		std::cout << "Bureaucrat " << name << " couldn't sign " << f.getName()
		<< " form because his grade is lower than the grade required\n";
	}
	// if (f.getStatus() == true)

	// else
	// {
	// 	std::cout << "Bureaucrat " << name << " couldn't sign " << f.getName()
	// 	<< " form because his grade is lower than the grade required\n";		
	// }
}


const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade too high\n");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade too low\n");
}