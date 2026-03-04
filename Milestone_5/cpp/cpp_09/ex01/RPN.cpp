/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoherfan <yoherfan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 14:57:44 by yoherfan          #+#    #+#             */
/*   Updated: 2026/02/24 12:17:12 by yoherfan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int	check_arguments(int argc, char **argv)
{
    int i = -1;
    while (++i < argc)
    {
        if ((std::string)argv[i] != "+" && (std::string)argv[i] != "-"
            && (std::string)argv[i] != "*" && (std::string)argv[i] != "/"
            && check_number(argv[i]) == 1)
        {
            std::cerr << "Error: just numbers < 10 and +-*/ are allowed\n";
            return (1);            
        }
    }
    return (0);
}

int check_number(char *str)
{
    int i = -1;
    while (str[++i] != '\0')
    {
        if (str[i] > '9' || str[i] < '0')
        {
            if (i == 0 && (str[i] == '-' || str[i] == '+'))
                ;
            else
                return (1);                
        }
    }
    if (atoi(str) > 9)
        return (1);
    return (0);
}

int resolve_exp(int argc, char **argv)
{
    std::stack<int> n_stack;
    int operand_1, operand_2;
    int i = -1;
    while (++i < argc)
    {
        if (atoi(argv[i]) || (std::string)argv[i] == "0")
            n_stack.push(atoi(argv[i]));
        else if ((std::string)argv[i] == "+" || (std::string)argv[i] == "-" ||
                 (std::string)argv[i] == "*" || (std::string)argv[i] == "/")
        {
            if (n_stack.size() > 1)
            {
                operand_2 = n_stack.top();
                n_stack.pop();
                operand_1 = n_stack.top();
                n_stack.pop();
                n_stack.push(operation_handler(operand_1, operand_2, *argv[i]));                
            }
            else
                return (1);
        }
    }
    if (n_stack.size() > 1)
        return (1);
    else
        std::cout << n_stack.top() << std::endl;
    return (0);
}

int operation_handler(int a, int b, int op)
{
    switch (op)
    {
    case 43:
        return (a + b);
        break;
    case 42:
        return (a * b);
        break;
    case 45:
        return (a - b);
        break;
    case 47:
        if (b == 0)
            return (0);
        else
            return (a / b);
        break;    
    default:
        return(0);
        break;
    }
}

char **split(char *argv, int args)
{
    int toggle = 0;
    std::string str = (std::string) argv;
    int i = -1;
    int start = 0;
    int index = 0;
    std::string cut;
    char **ret = new char*[args];
    while (str[++i] != '\0')
    {
        if (str[i] == ' ')
        {
            if (toggle == 1)
            {
                toggle = 0;
                cut = str.substr(start, i - start);
                ret[index] = new char[cut.size() + 1];
                cut.copy(ret[index], cut.size());
                ret[index][cut.size()] = '\0';
                index++;
            }
        }
        else
        {
            if (toggle == 0)
            {
                start = i;
                toggle = 1;
            }
        }
    }
    if (toggle == 1)
    {
        cut = str.substr(start, i - start);
        ret[index] = new char[cut.size() + 1];
        cut.copy(ret[index], cut.size());
        ret[index][cut.size()] = '\0';
    }
    return (ret);
}

int count_args(char *argv)
{
    int toggle = 0;
    std::string str = (std::string) argv;
    int i = -1;
    int k = 0;
    while (str[++i] != '\0')
    {
        if (str[i] == ' ')
        {
            if (toggle == 1)
                k++;            
        }
        else
        {
            if (toggle == 0)
                toggle = 1;            
        }
    }
    if (toggle == 1)
        k++;  
    return (k);    
}
