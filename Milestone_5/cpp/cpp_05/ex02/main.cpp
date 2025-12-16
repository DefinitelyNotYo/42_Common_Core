/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoherfan <yoherfan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 09:04:06 by yoherfan          #+#    #+#             */
/*   Updated: 2025/12/05 14:34:24 by yoherfan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

int main()
{
    try
    {
        srand((unsigned) time(NULL));
        // Form a;
        // // Form b("test", 10, 200);
        // // Form c("test", -500, 10);
    
        // PresidentialPardonForm d("Test");
        // PresidentialPardonForm e(d);
        // Bureaucrat f("Filippo", 1);
        // f.signForm(e);
        // f.executeForm(e);
        // // e.execute(f);

        // ShrubberyCreationForm d("Test");
        // ShrubberyCreationForm e(d);
        // Bureaucrat f("Filippo", 25);
        // f.signForm(e);
        // f.executeForm(e);
        // // e.execute(f);

        // RobotomyRequestForm d("Test");
        // RobotomyRequestForm e(d);
        // Bureaucrat f("Filippo", 25);
        // f.signForm(e);
        // f.executeForm(e);

    }
    catch(const std::exception &e)
    {
        std::cerr << e.what();
    }
}
