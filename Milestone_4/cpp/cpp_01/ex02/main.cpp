/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoherfan <yoherfan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 15:13:07 by yoherfan          #+#    #+#             */
/*   Updated: 2025/09/25 11:17:17 by yoherfan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

int main()
{
    std::string str = "HI THIS IS BRAIN";
    std::string *stringPTR = &str;
    std::string &stringREF = str;

    std::cout << "memory address of the string variable: "
              << &str << std::endl
              << "memory address held by stringPTR: "
              << stringPTR << std::endl
              << "memory address held by stringREF: "
              << &stringREF << std::endl << std::endl
              << "value of the string variable: "
              << str << std::endl
              << "The value pointed to by stringPTR: "
              << *stringPTR << std::endl
              << "The value pointed to by stringREF: "
              << stringREF << std::endl;
}
