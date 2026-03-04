/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btc.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoherfan <yoherfan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 13:48:18 by yoherfan          #+#    #+#             */
/*   Updated: 2026/03/04 17:21:06 by yoherfan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "btc.hpp"

void showMap(std::map<std::string, float> map)
{
    std::map<std::string, float>::iterator it = map.begin();
    std::map<std::string, float>::iterator ite = map.end();
    while (it != ite)
    {
        std::cout << it->first << " " << it->second << std::endl;
        it++;        
    }    
}

std::map<std::string, float> getMap(std::fstream &file, int toggle)
{
	std::string line;
    std::string date;
    float value;
    std::map<std::string, float> res_map;
    
    if (toggle == 1)
    {
        getline(file, line);     
    }
	while(std::getline(file, line))
	{
		int i = -1;
        int start = 0;
        while (line[++i] != '\0')
        {
            if (line[i] == ',')
            {
                date = line.substr(start, i - start);
                start = i + 1;            
            }
        }
        value = std::strtof (line.substr(start, i - start).c_str(), NULL);
        res_map[date] = value;
	}
    return (res_map);
}

int validate_line(std::string line)
{
    if (line.size() < 14)
        return (0);
    if (line[4] != '-' || line [7] != '-' || line[10] != ' ' || line[11] != '|' || line[12] != ' ')
        return (0);
    return (1);
}

int validate_value(std::string str)
{
    int i = -1;
    int toggle = 0;
    while(str[++i] != '\0')
    {
        if (str[i] > 57 || str[i] < 48)
        {
            if (i == 0 && str[i] == '-')
                return (std::cerr << "Error: not a positive number\n", 0);
            if (str[i] == '.')
            {
                if (toggle == 0)
                    toggle = 1;
                else
                    return (std::cerr<< "Error: bad input 1 => " << str << std::endl, 0);             
            }
            else
                return (std::cerr<< "Error: bad input 2 => " << str << std::endl, 0);
        }  
    }
    float f = std::strtof(str.c_str(), NULL);
    if (f > 1000)
            return (std::cerr << "Error: too large number\n", 0);
    return (1);
}

void exec_line(std::map<std::string, float> given_database, std::string line)
{
    std::string date;
    std::string value;
    int i = 13;
    if (validate_line(line) == 0)
    {
        std::cerr << "Error: bad input => " << line << std::endl;
        return ;
    }
    date = line.substr(0, 10);
    while(line[i] != '\0')
        i++;
    value = line.substr(13, i - 13);
    if (validate_date(date) == 1 && validate_value(value) == 1)
    {
        exec_result(given_database, date, value);        
    }
}

void exec_result(std::map<std::string, float> given_database, std::string date, std::string value)
{
    // showMap(given_database);
    std::map<std::string, float>::iterator it = given_database.begin();
    std::map<std::string, float>::iterator it_prec = given_database.begin();
    std::map<std::string, float>::iterator ite = given_database.end();
    float result;
    float value_float = std::strtof(value.c_str(), NULL);
    if (date == it->first)
    {
        result = it->second * value_float;
        // std::cout << "it->first: " << it->first << std::endl;        
        // std::cout << "it->second: " << it->second << std::endl;
        // std::cout << "value: " << value.c_str() << std::endl; 
        std::cout << date << " => " << value << " = " << result << std::endl;
        return ;
    }
    it++;
    while (it != ite)
    {
        if (date == it->first)
        {
            result = it->second * value_float;
            // std::cout << "it->first: " << it->first << std::endl;        
            // std::cout << "it->second: " << it->second << std::endl;
            // std::cout << "value: " << value.c_str() << std::endl; 
            std::cout << date << " => " << value << " = " << result << std::endl;
            break;
        }
        else if (date < it->first)
        {
            result = it_prec->second * value_float;
            // std::cout << "it_prec->first: " << it->first << std::endl;        
            // std::cout << "it_prec->second: " << it_prec->second << std::endl;
            // std::cout << "value: " << value.c_str() << std::endl; 
            std::cout << date << " => " << value << " = " << result << std::endl;
            break;
        }
        it++;
        it_prec++;
    }
    if (it == ite)
    {
        result = it_prec->second * value_float;
        // std::cout << "it_prec->first: " << it->first << std::endl;        
        // std::cout << "it_prec->second: " << it_prec->second << std::endl;
        // std::cout << "value: " << value.c_str() << std::endl; 
        std::cout << date << " => " << value << " = " << result << std::endl;
    }    
}

int validate_date(std::string date)
{
    int year = atoi(date.substr(0, 4).c_str());
    int month = atoi(date.substr(5, 2).c_str());
    int day = atoi(date.substr(8, 2).c_str());

    if (year < 2009 || (year == 2009 && month == 1 && day == 1))
        return (std::cerr << "Error: invalid date => bitcoins didn't exist before 2009-01-02\n", 0);
    if (month < 1 || month > 12)
        return (std::cerr << "Error: invalid month\n", 0);
    if (day < 1 || day > 28)
    {
        if (day == 0 || day > 31)
            return (std::cerr << "Error: invalid day\n", 0);
        else if (day == 29 && month == 2 && !(year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)))
            return (std::cerr << "Error: invalid date => month of 28 days\n", 0);
        else if (day > 29 && month == 2)
            return (std::cerr << "Error: invalid date => month of 28 days\n", 0);            
        else if (day == 31 && (month == 4 || month == 6 || month == 9 || month == 11))
            std::cerr << "Error: invalid date => month of 30 days\n";
        return (std::cerr << "Error: invalid date => month of 30 days\n", 0);            
    }
    return (1);
}
