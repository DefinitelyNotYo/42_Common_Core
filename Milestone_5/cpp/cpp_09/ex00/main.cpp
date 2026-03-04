/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoherfan <yoherfan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 13:48:13 by yoherfan          #+#    #+#             */
/*   Updated: 2026/03/04 17:24:33 by yoherfan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "btc.hpp"

    
int main(int argc, char **argv)
{
    if (argc != 2)
        return (std::cerr << "Error: could not open file\n", 0);
    
    std::fstream file;
    std::string name = "data.csv";
    
    file.open((name).c_str(), std::ios::in);
    if (!file)
        return (std::cerr << "Error: Given database not found\n", 0);

    std::map<std::string, float> given_database = getMap(file, 1);
    // showMap(given_database);

    file.close();

    name = argv[1];
    file.open((name).c_str(), std::ios::in);
    if (!file) 
        return (std::cerr << "Error: could not open file\n", 0);
    
    std::string line;
    while(std::getline(file, line))
        exec_line(given_database, line);
    file.close();
}




