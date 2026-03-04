/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btc.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoherfan <yoherfan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 13:48:15 by yoherfan          #+#    #+#             */
/*   Updated: 2026/03/04 16:28:41 by yoherfan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BTC_HPP
# define BTC_HPP

#include <string>
#include <ostream>
#include <iostream>
#include <stdexcept>
#include <fstream>
#include <cstdlib>
#include <map>
#include <iomanip>
#include <stdlib.h>

void showMap(std::map<std::string, float>);
std::map<std::string, float> getMap(std::fstream &file, int toggle);
void exec_line(std::map<std::string, float> given_database, std::string line);
void exec_result(std::map<std::string, float> given_database, std::string date, std::string value);

int validate_line(std::string line);
int validate_date(std::string date);
int validate_value(std::string value);

#endif