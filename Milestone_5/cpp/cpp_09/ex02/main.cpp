/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoherfan <yoherfan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 14:42:53 by yoherfan          #+#    #+#             */
/*   Updated: 2026/02/11 17:18:05 by yoherfan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
    std::deque<unsigned int> deq;
    std::vector<unsigned int> vec;
    if (argc < 2)
    {
        std::cout << "Invalid argument: insufficient numbers\n";
        return (1);
    }
    if (check_arguments(argc, argv) == 1)
    {
        std::cout << "Invalid argument: arguments must contain positive integers only\n";
        return (1);      
    }
    fill_deque(&deq, argc, argv);
    fill_vector(&vec, argc, argv);    
    if (check_clones(deq) == 1)
    {
        std::cout << "Invalid argument: duplicates are forbidden\n";
        return (1);        
    }
    long long time = get_time();
    std::deque<unsigned int> dq_sorted = pmerge_dq(deq);
    time = get_time() - time;
    long long time2 = get_time();
    std::vector<unsigned int> vec_sorted = pmerge_dq2(vec);
    time2 = get_time() - time2;
    std::cout << "Before: ";
    showDq(deq);
    std::cout << "\nAfter: ";
    showVector(vec_sorted);
    std::cout << "\n\nTime to process a range of " << argc - 1 << " elements with std::deque : " << time << " us" << std::endl;
    std::cout << "Time to process a range of " << argc - 1 << " elements with std::vector : " << time2 << " us" << std::endl;
    // if (check_sorting2(vec_sorted) == 0)
    //     std::cout << "\nthe numbers are sorted\n";
    // else
    //     std::cout << "\nsorting is failed\n";
}
