/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoherfan <yoherfan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 13:59:49 by yoherfan          #+#    #+#             */
/*   Updated: 2025/12/05 13:58:33 by yoherfan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
    private:

    std::string _target;
    
    public:
    
    RobotomyRequestForm();
    RobotomyRequestForm(RobotomyRequestForm &f);
    RobotomyRequestForm(std::string target);
	RobotomyRequestForm &operator = (RobotomyRequestForm const &value);
    ~RobotomyRequestForm();

    void execute(Bureaucrat const & executor) const;

	class InvalidExecuteRequest : public std::exception
	{
		public:
		
		const char *what() const throw();
	};
};

#endif