#include "PmergeMe.hpp"
#include <cctype>
#include <limits>
#include <cstdlib>
#include <string>
#include <iostream>
#include <ctime>
#include <utility>
#include <cstddef>

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

    size_t jacobsthal(size_t n) {
        if (n == 0) return 0;
        if (n == 1) return 1;

        size_t prev = 0;
        size_t curr = 1;
        for (size_t i = 2; i <= n; ++i) {
            size_t next = curr + 2 * prev;
            prev = curr;
            curr = next;
        }
        return curr;
    }

    void build_insertion_order_vector(size_t pair_count, std::vector<size_t>& order) {
        if (pair_count < 2) return;

        size_t inserted_until = 1;
        size_t jacobsthal_index = 3;
        while (inserted_until < pair_count) {
            size_t end = jacobsthal(jacobsthal_index);
            if (end > pair_count) end = pair_count;

            for (size_t b = end; b > inserted_until; --b) {
                order.push_back(b - 1);
            }
            inserted_until = end;
            ++jacobsthal_index;
        }
    }

    void build_insertion_order_deque(size_t pair_count, std::deque<size_t>& order) {
        if (pair_count < 2) return;

        size_t inserted_until = 1;
        size_t jacobsthal_index = 3;
        while (inserted_until < pair_count) {
            size_t end = jacobsthal(jacobsthal_index);
            if (end > pair_count) end = pair_count;

            for (size_t b = end; b > inserted_until; --b) {
                order.push_back(b - 1);
            }
            inserted_until = end;
            ++jacobsthal_index;
        }
    }

    size_t upper_bound_index_vector(const std::vector<int>& c, int value, size_t end) {
        size_t low = 0;
        size_t high = end;
        while (low < high) {
            size_t mid = low + (high - low) / 2;
            if (value < c[mid])
                high = mid;
            else
                low = mid + 1;
        }
        return low;
    }

    size_t upper_bound_index_deque(const std::deque<int>& c, int value, size_t end) {
        size_t low = 0;
        size_t high = end;
        while (low < high) {
            size_t mid = low + (high - low) / 2;
            if (value < c[mid])
                high = mid;
            else
                low = mid + 1;
        }
        return low;
    }

    void ford_johnson_vector(std::vector<int>& values) {
        if (values.size() <= 1) return;

        std::vector<std::pair<int, int> > pairs;
        pairs.reserve(values.size() / 2);

        for (size_t i = 0; i + 1 < values.size(); i += 2) {
            int a = values[i];
            int b = values[i + 1];
            if (a >= b)
                pairs.push_back(std::make_pair(a, b));
            else
                pairs.push_back(std::make_pair(b, a));
        }

        bool has_leftover = values.size() % 2 == 1;
        int leftover = has_leftover ? values.back() : 0;

        std::vector<int> sorted_bigs;
        sorted_bigs.reserve(pairs.size());
        for (size_t i = 0; i < pairs.size(); ++i) {
            sorted_bigs.push_back(pairs[i].first);
        }
        ford_johnson_vector(sorted_bigs);

        std::vector<std::pair<int, int> > sorted_pairs;
        sorted_pairs.reserve(pairs.size());
        std::vector<bool> used(pairs.size(), false);
        for (size_t i = 0; i < sorted_bigs.size(); ++i) {
            for (size_t j = 0; j < pairs.size(); ++j) {
                if (!used[j] && pairs[j].first == sorted_bigs[i]) {
                    sorted_pairs.push_back(pairs[j]);
                    used[j] = true;
                    break;
                }
            }
        }

        std::vector<int> chain;
        chain.reserve(values.size());
        chain.push_back(sorted_pairs[0].second);
        for (size_t i = 0; i < sorted_pairs.size(); ++i) {
            chain.push_back(sorted_pairs[i].first);
        }

        std::vector<size_t> insertion_order;
        build_insertion_order_vector(sorted_pairs.size(), insertion_order);
        for (size_t i = 0; i < insertion_order.size(); ++i) {
            size_t pair_index = insertion_order[i];
            int value = sorted_pairs[pair_index].second;
            int upper_value = sorted_pairs[pair_index].first;
            size_t limit = upper_bound_index_vector(chain, upper_value, chain.size());
            size_t pos = upper_bound_index_vector(chain, value, limit);
            chain.insert(chain.begin() + pos, value);
        }

        if (has_leftover) {
            size_t pos = upper_bound_index_vector(chain, leftover, chain.size());
            chain.insert(chain.begin() + pos, leftover);
        }

        values = chain;
    }

    void ford_johnson_deque(std::deque<int>& values) {
        if (values.size() <= 1) return;

        std::deque<std::pair<int, int> > pairs;

        for (size_t i = 0; i + 1 < values.size(); i += 2) {
            int a = values[i];
            int b = values[i + 1];
            if (a >= b)
                pairs.push_back(std::make_pair(a, b));
            else
                pairs.push_back(std::make_pair(b, a));
        }

        bool has_leftover = values.size() % 2 == 1;
        int leftover = has_leftover ? values.back() : 0;

        std::deque<int> sorted_bigs;
        for (size_t i = 0; i < pairs.size(); ++i) {
            sorted_bigs.push_back(pairs[i].first);
        }
        ford_johnson_deque(sorted_bigs);

        std::deque<std::pair<int, int> > sorted_pairs;
        std::deque<bool> used(pairs.size(), false);
        for (size_t i = 0; i < sorted_bigs.size(); ++i) {
            for (size_t j = 0; j < pairs.size(); ++j) {
                if (!used[j] && pairs[j].first == sorted_bigs[i]) {
                    sorted_pairs.push_back(pairs[j]);
                    used[j] = true;
                    break;
                }
            }
        }

        std::deque<int> chain;
        chain.push_back(sorted_pairs[0].second);
        for (size_t i = 0; i < sorted_pairs.size(); ++i) {
            chain.push_back(sorted_pairs[i].first);
        }

        std::deque<size_t> insertion_order;
        build_insertion_order_deque(sorted_pairs.size(), insertion_order);
        for (size_t i = 0; i < insertion_order.size(); ++i) {
            size_t pair_index = insertion_order[i];
            int value = sorted_pairs[pair_index].second;
            int upper_value = sorted_pairs[pair_index].first;
            size_t limit = upper_bound_index_deque(chain, upper_value, chain.size());
            size_t pos = upper_bound_index_deque(chain, value, limit);
            chain.insert(chain.begin() + pos, value);
        }

        if (has_leftover) {
            size_t pos = upper_bound_index_deque(chain, leftover, chain.size());
            chain.insert(chain.begin() + pos, leftover);
        }

        values = chain;
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
        if (val <= 0)
            throw InvalidInputException();

        if (is_over_int_max(val))
            throw InvalidInputException();

        original_.push_back(static_cast<int>(val));
    }
}


void PmergeMe::sort_vector() {
    ford_johnson_vector(vec_);
}

void PmergeMe::sort_deque() {
    ford_johnson_deque(deq_);
}


void PmergeMe::sort() {

    std::clock_t start = std::clock();
    vec_.assign(original_.begin(), original_.end());
    sort_vector();
    std::clock_t end = std::clock();
    vec_elapsed_time_ = static_cast<double>(end - start) * 1e6 / CLOCKS_PER_SEC;

    start = std::clock();
    deq_.assign(original_.begin(), original_.end());
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
