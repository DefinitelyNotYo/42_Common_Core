/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoherfan <yoherfan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 14:57:47 by yoherfan          #+#    #+#             */
/*   Updated: 2026/02/24 12:14:37 by yoherfan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ostream"
#include "stdlib.h"
#include "stack"

int	check_arguments(int argc, char **argv);
int resolve_exp(int argc, char **argv);
int check_number(char *str);
int operation_handler(int a, int b, int op);
int count_args(char *argv);
char **split(char *argv, int args);