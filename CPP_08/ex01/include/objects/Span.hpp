#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>

class Span
{
  public:
    Span(const Span &other);
    Span &operator = (const Span &other);
    explicit Span(unsigned int N);
    ~Span();

    void add_number(int N);
    int longest_span();
    int shortest_span();
    void add_range_of_numbers(size_t range_numbers);

    template <typename InputIterator>
    void insert (InputIterator &fist, InputIterator &last)
    {
      if (std::distance(fist, last) + numbers_.size() > static_cast<int>(size_))
        throw no_space_left_in_span_class();
      numbers_.insert(numbers_.end(), fist, last);
    }
    class no_space_left_in_span_class : public std::exception 
    {
      virtual const char *what() const throw();
    };
    class less_than_two_elements_no_span_calc_possible : public std:: exception
    {
      virtual const char *what() const throw();
    };
  private:
    std::vector<int> numbers_;
    size_t size_;
};

#endif
