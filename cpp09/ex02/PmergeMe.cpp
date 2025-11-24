/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleoni <nleoni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 18:54:30 by nleoni            #+#    #+#             */
/*   Updated: 2025/06/12 09:39:21 by nleoni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {
	
}

PmergeMe::PmergeMe(const PmergeMe& other) {
	(void)other;
}

PmergeMe PmergeMe::operator=(const PmergeMe& other) {
	(void)other;
	return *this;
}

PmergeMe::~PmergeMe() {
	
}

template <typename T>
void printArray(T& array) {
	typename T::iterator ite = array.end();
	for (typename T::iterator it = array.begin(); it != ite; ++it) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

void PmergeMe::initVector(char **av) {
	for (int i = 1; av[i]; i++) {
		this->vector.push_back(std::atoi(av[i]));
	}
	printArray(this->vector);
	std::vector<int> main;
	std::vector<int> pend;
	algo(this->vector, 1, main, pend);
	binaryInsert(main, pend, this->vector);
}

void PmergeMe::initDeque(char **av) {
	for (int i = 1; av[i]; i++) {
		this->deque.push_back(std::atoi(av[i]));
	}
	std::deque<int> main;
	std::deque<int> pend;
	algo(this->deque, 1, main, pend);
	binaryInsert(main, pend, this->deque);
}

std::vector<std::string> split(const std::string& str) {
	std::vector<std::string> tokens;
    std::istringstream iss(str);
    std::string token;

    while (iss >> token) {
        tokens.push_back(token);
    }
    return tokens;
}

bool hasDuplicates(const std::vector<int>& numbers) {
	std::set<int> seen;
    for (size_t i = 0; i < numbers.size(); ++i) {
        if (seen.count(numbers[i]) > 0)
            return true;
        seen.insert(numbers[i]);
    }
    return false;
}

int parse(char **av) {
    std::vector<int> parsedNumbers;
    for (int i = 0; av[i]; ++i) {
        std::string arg(av[i]);
        std::vector<std::string> tokens = split(arg);
        for (size_t k = 0; k < tokens.size(); ++k) {
            const std::string& token = tokens[k];
            for (size_t j = 0; j < token.length(); ++j) {
                if (!std::isdigit(token[j]))
                    return -1;
            }
            std::istringstream iss(token);
            long num;
            iss >> num;
            if (iss.fail() || !iss.eof() || num > INT_MAX)
                return -1;

            parsedNumbers.push_back(static_cast<int>(num));
        }
    }
    if (hasDuplicates(parsedNumbers))
        return -1;
    return 0;
}

template <typename T>
void PmergeMe::binaryInsert(T& main, T& pend, T& array)
{
    typedef typename T::iterator Iterator;
	for (Iterator it = pend.begin(); it != pend.end(); ++it) {
        Iterator pos = std::lower_bound(main.begin(), main.end(), *it);
        main.insert(pos, *it);
    }
    Iterator array_it = array.begin();
    Iterator main_it = main.begin();
    while (main_it != main.end() && array_it != array.end()) {
        *array_it = *main_it;
        ++main_it;
        ++array_it;
    }
	return ;
}

template <typename T>
void jacobsthalInsert(T& main, T&pend) {
	while (1) {
		std::sort(main.begin(), main.end());
		int prev_j = jacobsthal(1);
		int inserted = 0;
		for (int k = 2; ; ++k) {
			int curr_j = jacobsthal(k);
			unsigned long diff = curr_j - prev_j;
			if (diff > pend.size())
				break ;
			for (unsigned long i = 0; i < diff; ++i) {
				int pend_idx = inserted + i;
				int bound_idx = curr_j + inserted;
				typename T::iterator insert_pos = std::upper_bound(main.begin(), main.begin() + std::min(bound_idx, static_cast<int>(main.size())), pend[pend_idx]);
				main.insert(insert_pos, pend[pend_idx]);				
			}
			inserted = 2;
			if (static_cast<unsigned long>(inserted) < pend.size())
				pend.erase(pend.begin(), pend.begin() + std::min(inserted, (int)pend.size()));
			prev_j = curr_j;
			inserted = 0;
		}
		break ;
	}
}

template <typename T>
void createMainPend(T& array, int rec_level, T& main, T& pend) {
	main.clear();
	pend.clear();

	typename T::iterator itp = array.end();
	typename T::iterator itpstart = array.begin();
	std::advance(itpstart, array.size() - (array.size() % rec_level));
	if (rec_level <= 0 || rec_level > static_cast<int>(array.size())) {
		std::cerr << "Invalid rec_level: " << rec_level << std::endl;
		return;
	}
	while (itpstart != itp) {
		pend.push_back(*itpstart);
		itpstart++;
	}
	size_t main_count = array.size() - (array.size() % rec_level);
	typename T::iterator it = array.begin();
	for (size_t i = 0; i < array.size(); ++i, ++it) {
		if (i < main_count)
			main.push_back(*it);
		else
			pend.push_back(*it);
	}
	jacobsthalInsert(main, pend);
}

template <typename T>
void PmergeMe::algo(T& array, int rec_level, T& main, T& pend) {
	int pairNumbers = array.size() / rec_level;
	if (pairNumbers < 2)
		return ;
	bool oddNbr = pairNumbers % 2 == 1;
	typename T::iterator its = array.begin();
	typename T::iterator itn = array.begin();
	std::advance(itn, rec_level * pairNumbers);
	typename T::iterator ite = itn;
	std::advance(ite, -(oddNbr * rec_level));
	int next = 2 * rec_level;
	for (typename T::iterator it = its; it != ite; std::advance(it, next)) {
		typename T::iterator first = it;
		std::advance(first, rec_level - 1);
		typename T::iterator second = it;
		std::advance(second, rec_level * 2 - 1);
		if (*second < *first) {
			typename T::iterator itstart = first;
			std::advance(itstart, -rec_level + 1);
			typename T::iterator itend = itstart;
			std::advance(itend, rec_level);
  			while (itstart != itend) {
				typename T::iterator itstarts = itstart;
				std::advance(itstarts, rec_level);
    		    std::iter_swap(itstart, itstarts);
				itstart++;
			}
		}
	}
	algo(array, rec_level * 2, main, pend);
	createMainPend(array, rec_level, main, pend);
}
