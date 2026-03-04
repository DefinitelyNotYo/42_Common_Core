/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoherfan <yoherfan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 15:09:00 by yoherfan          #+#    #+#             */
/*   Updated: 2026/02/24 15:07:42 by yoherfan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << "Error: invalid parameters\n";
        return (0);
    }
    int args = count_args(argv[1]);
    char **exp;
    exp = split(argv[1], args);
    if (check_arguments(args, exp) == 0)
        if(resolve_exp(args, exp) == 1)
            std::cout << "Error: invalid expression\n";
    int i = -1;
    while (++i < args)
        delete[] (exp[i]);
    delete[] (exp);
}
