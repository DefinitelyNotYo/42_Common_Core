/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoherfan <yoherfan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 14:42:58 by yoherfan          #+#    #+#             */
/*   Updated: 2026/02/11 17:06:42 by yoherfan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iterator>
#include <deque>
#include <vector>
#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <sys/time.h>
#include <cstdlib>
#include <unistd.h>

// int binarySearch(std::deque<unsigned int> deq, unsigned int n, unsigned int min, unsigned int max);
void insertNode(std::deque<unsigned int> *deq, unsigned int index, unsigned int n);
void binaryInsert(std::deque<unsigned int> *deq, unsigned int n, unsigned int min, unsigned int max);
std::deque<unsigned int> jacobsthalSeq(unsigned int max);
std::deque<unsigned int> pmerge_dq(std::deque<unsigned int> dq);
void showDq(std::deque<unsigned int> dq);
int check_clones(std::deque<unsigned int> dq);
int check_sorting(std::deque<unsigned int> dq);
void fill_deque(std::deque<unsigned int> *dq, int argc, char **argv);

long long get_time();
int check_arguments(int argc, char **argv);

void insertNode2(std::vector<unsigned int> *deq, unsigned int index, unsigned int n);
void binaryInsert2(std::vector<unsigned int> *deq, unsigned int n, unsigned int min, unsigned int max);
std::vector<unsigned int> jacobsthalSeq2(unsigned int max);
std::vector<unsigned int> pmerge_dq2(std::vector<unsigned int> dq);
void showVector(std::vector<unsigned int> dq);
int check_clones2(std::vector<unsigned int> dq);
int check_sorting2(std::vector<unsigned int> dq);
void fill_vector(std::vector<unsigned int> *dq, int argc, char **argv);

#endif