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

    void add_number(size_t N);
    void shortest_span();
    void longest_span();
    void add_range_of_numbers(size_t range_numbers);
  private:
    Span();
    std::vector<int> numbers_;
    size_t size_;
};

#endif
