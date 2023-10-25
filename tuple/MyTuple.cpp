// Tuple implementation using variadic templates
// std::tuple should be used in practice. This is intended as an academic exercise
// to get familiar with new C++11 and C++14 concepts (idea from C++ Templates, D. Vandevoorde)

#include <cassert>
#include <functional>
#include <iostream>
#include <string>
#include <utility>

template <typename... Types>
class Tuple;

template <typename Head, typename... Tail>
class Tuple<Head, Tail...>
{
private:
    Head head;
    Tuple<Tail...> tail;

public:
    Tuple() = default;

    Tuple(const Head &head, const Tuple<Tail...> &tail)
        : head(head), tail(tail)
    {
    }

    Tuple(const Head &head, const Tail &... tail)
        : head(head), tail(tail...)
    {
    }

    Head& getHead() { return head; }
    const Head& getHead() const { return head; }
    Tuple<Tail...>& getTail() { return tail; }
    const Tuple<Tail...>& getTail() const { return tail; }
};

// Base case with zero template arguments
template <>
class Tuple<>
{
};

// index into tuple during compilation and return head of current tail
template <unsigned N>
struct TupleGet
{
    template <typename Head, typename... Tail>
    static auto apply(Tuple<Head, Tail...> const &t)
    {
        return TupleGet<N - 1>::apply(t.getTail());
    }
};

template <>
struct TupleGet<0>
{
    template <typename Head, typename... Tail>
    static const Head & apply(Tuple<Head, Tail...> const &t)
    {
        return t.getHead();
    }
};

// retrieve element by index, analogous to std::get
template <unsigned N, typename... Types>
auto get(Tuple<Types...> const &t)
{
    return TupleGet<N>::apply(t);
}

void testTuple()
{
    // extract via head/tail
    Tuple<int, double, std::string> t(17, 3.14, "Hello");
    assert(t.getHead() == 17);
    Tuple <double, std::string> t2 = t.getTail();
    assert(t2.getHead() == 3.14);
    Tuple <std::string> t3 = t2.getTail();
    assert(t3.getHead() == "Hello");
    Tuple<> t4 = t3.getTail();
    // Empty tuple t4 has no methods

    // extract by index
    assert(get<0>(t) == 17);
    assert(get<1>(t) == 3.14);
    assert(get<2>(t) == "Hello");
    assert(get<0>(t3) == "Hello");

    // invalid indexes yield compile errors:
    //assert(get<3>(t) == "Hello"); // <- compile error!
}

int main()
{
    testTuple();

    std::cout << std::endl << __FILE__ " tests passed!" << std::endl;
    return 0;
}
