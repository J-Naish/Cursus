#pragma once
#ifndef PMERGE_ME_HPP
#define PMERGE_ME_HPP

#include <vector>
#include <deque>
#include <exception>

class PmergeMe {

    public:
        PmergeMe();
        PmergeMe(const PmergeMe& other);
        ~PmergeMe();
        PmergeMe& operator=(const PmergeMe& other);

        PmergeMe(int argc, char** argv);

        void sort();

        void print() const;

        class InvalidInputException : public std::exception {
            public:
                const char* what() const throw();
        };

    private:

        std::vector<int> original_;
        std::vector<int> vec_;
        std::deque<int> deq_;

        double vec_elapsed_time_;
        double deq_elapsed_time_;

        void sort_vector();
        void sort_deque();

};

#endif
