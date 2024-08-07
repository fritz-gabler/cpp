#ifndef PMERGE_ME_HPP
#define PMERGE_ME_HPP

#include <string>
#include <list>
#include <deque>
#include <vector>
#include <algorithm>
#include <iostream>


class PmergeMe
{
  public:
    PmergeMe(const std::vector<unsigned int> &input);
    PmergeMe(const PmergeMe &other);
    PmergeMe &operator = (const PmergeMe &other);
    ~PmergeMe();

    std::deque<unsigned int> deque_merge_insertion_sort();
    std::vector<unsigned int> &vector_merge_insertion_sort();
  private:
    PmergeMe();


    void save_possible_orphan_number();
    void create_insertion_order();
    void set_idx_position(std::vector<unsigned int>::const_iterator &,
                                                                    size_t &);
    void build_jacopsthal_number(std::vector<unsigned int> &);
    size_t compute_jacobsthal_number(unsigned int n);

    template<typename T>
    void create_internally_sorted_pairs(T &container);
    template<typename T>
    void sort_pairs(T &container);
    template<typename T, typename S>
    void sort_larger_number_in_sequence(T &container, S &sequence);
    template<typename T, typename S>
    void first_element_insert_in_sequence(T &container, S &sequence);
    template<typename T, typename S>
    void insert_in_sequence(T &container, S &sequence);
    template<typename S>
    void insert_possible_orphan(S &sequence);


    std::vector<unsigned int> input_;
    size_t size_input_;
    std::vector<unsigned int> insertion_order_;

    std::vector<std::vector<unsigned int> > vector_to_sort_;;
    std::deque<std::deque<unsigned int> > deque_to_sort_;
    std::vector<unsigned int> vector_sequence_;
    std::deque<unsigned int> deque_sequence_;
    unsigned int orphan_;
    bool orphan_got_saved_;
};

#endif
/*
input: 7, 8, 3, 9, 2, 1

      0      1       2
1. [7, 8] [3, 9] [2, 1]

      0      1       2
2. [8, 7] [9, 3] [2, 1]

      0      1       2
3. [2, 1] [8, 7] [9, 3]
       _   _   _ 
main  |2| |8| |2|
pand  |1| |7| |3|

S: 1, 2, 3, 7, 8, 9
*/
