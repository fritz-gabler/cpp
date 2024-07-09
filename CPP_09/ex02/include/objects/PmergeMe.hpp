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

    std::vector<unsigned int> &deque_merge_insertion_sort();
    std::vector<unsigned int> &vector_merge_insertion_sort();
  private:
    PmergeMe();

    std::vector<unsigned int> input_;
    size_t size_input_;
    std::vector<unsigned int> insertion_order;

    std::vector<std::vector<unsigned int> > vector_to_sort_;;
    std::deque<std::vector<unsigned int> > deque_to_sort_;
    std::vector<unsigned int> sequence_;
    unsigned int orphan_;

    void save_possible_orphan_number();
    void create_insertion_order();
    void build_jacopsthal_number(std::vector<unsigned int> &);
    size_t compute_jacobsthal_number(unsigned int n);
    void set_idx_position(std::vector<unsigned int>::const_iterator &,
                                                                    size_t &);

    template<typename T>
    void create_internally_sorted_pairs(T &container)
    {
      std::vector<unsigned int>::const_iterator it;
      std::vector<unsigned int>::const_iterator end_node = input_.end();

      for (it = input_.begin(); it != end_node && it + 1 != end_node; it += 2)
      {
        std::vector<unsigned int> pair_to_add;
        pair_to_add.push_back(*it);
        if (pair_to_add.front() > *(it + 1))
          pair_to_add.push_back(*(it + 1));
        else
          pair_to_add.insert(pair_to_add.begin(), *(it + 1));
        container.push_back(pair_to_add);
      }
    }

    template<typename T>
    void sort_pairs(T &container)
    {
      if (container.size() == 1)
        return;

      size_t mid = container.size() / 2;
      T left(container.begin(), container.begin() + mid);
      T right(container.begin() + mid, container.end());
      sort_pairs(left);
      sort_pairs(right);

      std::merge(left.begin(), left.end(), right.begin(), right.end(),
                                                           container.begin());
    }

    template<typename T>
    void sort_larger_number_in_sequence(T &container)
    {
      typename T::const_iterator it;

      for (it = container.begin(); it != container.end(); it++)
      {
        sequence_.push_back((*it).front());
      }
    }

    template<typename T>
    void first_element_insert_in_sequence(T &container)
    {
      sequence_.push_back(container[0][1]);
    }

    template<typename T>
    void insert_in_sequence(T &container)
    {
      std::vector<unsigned int>::iterator position_insertion;
      int amount_inserted_elements = 1; // -1 | 0 1 2
      for(unsigned int idx = 0; idx != container.size() - 1; idx++)
      {
        int window = (insertion_order[idx] - 1) + amount_inserted_elements;

        int insertion_idx = insertion_order[idx];

        int element_to_insert = container[insertion_idx][1];

        position_insertion = std::upper_bound(sequence_.begin(),
                                  sequence_.begin() + window, element_to_insert);

        sequence_.insert(position_insertion, element_to_insert);
        amount_inserted_elements++;
      }
    }
    void insert_possible_orphan();


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
