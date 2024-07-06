#ifndef PMERGE_ME_HPP
#define PMERGE_ME_HPP

#include <string>
#include <list>
#include <deque>
#include <vector>

class PmergeMe
{
  public:
    PmergeMe(const std::vector<int> &input);
    PmergeMe(const PmergeMe &other);
    PmergeMe &operator = (const PmergeMe &other);
    ~PmergeMe();

    std::vector<int> &deque_merge_insertion_sort();
    std::vector<int> &vector_merge_insertion_sort();
  private:
    PmergeMe();


    void build_jacopsthal_number();
    size_t compute_jacobsthal_number(unsigned int n);
    void save_possible_orphan_number();

    template<typename T>
    void create_pairs(T &container)
    {
      std::vector<unsigned int>::const_iteraor it;
      std::vector<unsigned int>::const_iteraor end = input_.end();

      for (it = input_.begin(); it != end && it + 1 != end; it += 2)
      {
        std::vector<int> pair_to_add;
        pair_to_add.push_back(*it);
        if (pair_to_add.front() > *(it + 1))
          pair_to_add.push_back(*(it + 1));
        else
          pair_to_add.insert(tmp.begin(), *(it + 1));
      }
    }

    std::vector<int> input_;
    size_t size_input_;
    std::list<int> jacobs_thal_number_;

    std::vector<std::vector<unsigned int> > vector_to_sort_;;
    std::deque<std::vector<unsigned int> > deque_to_sort_;
    std::vector<int> sequence_;
    unsigned int orphan_;


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
