#include "PmergeMe.hpp"
#include <cctype>
#include <limits>
#include <cstdlib>
#include <string>
#include <iostream>
#include <ctime>
#include <utility>

namespace {
    bool is_unsigned_digit_string(const std::string& s) {
        if (s.empty())
            return false;
        for (size_t i = 0; i < s.size(); ++i) {
            if (!std::isdigit(static_cast<unsigned char>(s[i])))
                return false;
        }
        return true;
    }

    bool fits_int_digits(const std::string& s) {
        return s.size() <= 10;
    }

    bool is_over_int_max(long v) {
        return v > std::numeric_limits<int>::max();
    }

    template <typename Container>
    void print_elements(const std::string& label, const Container& c) {
        std::cout << label;
        typename Container::const_iterator it = c.begin();
        for (; it != c.end(); ++it) {
            std::cout << " " << *it;
        }
        std::cout << std::endl;
    }
}

const char* PmergeMe::InvalidInputException::what() const throw() {
    return "invalid input";
}

PmergeMe::PmergeMe()
    : vec_elapsed_time_(0.0), deq_elapsed_time_(0.0) {}

PmergeMe::PmergeMe(const PmergeMe& other) :
    original_(other.original_),
    vec_(other.vec_),
    deq_(other.deq_),
    vec_elapsed_time_(other.vec_elapsed_time_),
    deq_elapsed_time_(other.deq_elapsed_time_) {}

PmergeMe::~PmergeMe() {}

PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
    if (this != &other) {
        original_ = other.original_;
        vec_ = other.vec_;
        deq_ = other.deq_;
        vec_elapsed_time_ = other.vec_elapsed_time_;
        deq_elapsed_time_ = other.deq_elapsed_time_;
    }
    return *this;
}


PmergeMe::PmergeMe(int argc, char** argv)
    : vec_elapsed_time_(0.0), deq_elapsed_time_(0.0) {

    for (int i = 1; i < argc; ++i) {
        std::string token(argv[i]);

        if (!is_unsigned_digit_string(token))
            throw InvalidInputException();

        if (!fits_int_digits(token))
            throw InvalidInputException();

        long val = std::atol(token.c_str());
        if (is_over_int_max(val))
            throw InvalidInputException();

        original_.push_back(static_cast<int>(val));
    }
    vec_.assign(original_.begin(), original_.end());
    deq_.assign(original_.begin(), original_.end());
}


void PmergeMe::sort_vector() {
    if (vec_.size() <= 1) return;

    std::vector<std::pair<int, int> > pairs;
    bool has_leftover = vec_.size() % 2 == 1;
    int leftover = 0;

    for (size_t i = 0; i + 1 < vec_.size(); i += 2) {
        int a = vec_[i];
        int b = vec_[i + 1];
        if (a >= b)
            pairs.push_back(std::make_pair(a, b));
        else
            pairs.push_back(std::make_pair(b, a));
    }
    if (has_leftover)
        leftover = vec_.back();

    std::sort(pairs.begin(), pairs.end());

    std::vector<int> chain;
    chain.reserve(pairs.size() + 1 + (has_leftover ? 1 : 0));
    chain.push_back(pairs[0].second);
    for (size_t i = 0; i < pairs.size(); ++i) {
        chain.push_back(pairs[i].first);
    }

    for (size_t i = 1; i < pairs.size(); ++i) {
        int b = pairs[i].second;
        std::vector<int>::iterator pos = std::lower_bound(chain.begin(), chain.end(), b);
        chain.insert(pos, b);
    }

    if (has_leftover) {
        std::vector<int>::iterator pos = std::lower_bound(chain.begin(), chain.end(), leftover);
        chain.insert(pos, leftover);
    }

    vec_ = chain;
}

void PmergeMe::sort_deque() {
    if (deq_.size() <= 1) return;

    std::deque<std::pair<int, int> > pairs;
    bool has_leftover = deq_.size() % 2 == 1;
    int leftover = 0;

    for (size_t i = 0; i + 1 < deq_.size(); i += 2) {
        int a = deq_[i];
        int b = deq_[i + 1];
        if (a >= b)
            pairs.push_back(std::make_pair(a, b));
        else
            pairs.push_back(std::make_pair(b, a));
    }
    if (has_leftover)
        leftover = deq_.back();

    std::sort(pairs.begin(), pairs.end());

    std::deque<int> chain;
    chain.push_back(pairs[0].second);
    for (size_t i = 0; i < pairs.size(); ++i) {
        chain.push_back(pairs[i].first);
    }

    for (size_t i = 1; i < pairs.size(); ++i) {
        int b = pairs[i].second;
        std::deque<int>::iterator pos = std::lower_bound(chain.begin(), chain.end(), b);
        chain.insert(pos, b);
    }

    if (has_leftover) {
        std::deque<int>::iterator pos = std::lower_bound(chain.begin(), chain.end(), leftover);
        chain.insert(pos, leftover);
    }

    deq_ = chain;
}


void PmergeMe::sort() {

    std::clock_t start = std::clock();
    sort_vector();
    std::clock_t end = std::clock();
    vec_elapsed_time_ = static_cast<double>(end - start) * 1e6 / CLOCKS_PER_SEC;

    start = std::clock();
    sort_deque();
    end = std::clock();
    deq_elapsed_time_ = static_cast<double>(end - start) * 1e6 / CLOCKS_PER_SEC;
}

void PmergeMe::print() const {
    print_elements("Before: ", original_);
    print_elements("After:  ", vec_);

    std::cout << "Time to process a range of " << original_.size()
              << " elements with std::vector : "
              << vec_elapsed_time_ << " us" << std::endl;
    std::cout << "Time to process a range of " << original_.size()
              << " elements with std::deque  : "
              << deq_elapsed_time_ << " us" << std::endl;
}
