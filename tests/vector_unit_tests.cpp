#define BOOST_TEST_MAIN
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE ft_containers
#include <boost/test/included/unit_test.hpp>
#include <boost/test/test_case_template.hpp>
#include <boost/mpl/list.hpp>

#include <memory>
#include <vector>
#include <stack>
#include "../src/vector/vector.hpp"

typedef boost::mpl::list<int, float, double, char> test_types;

const unsigned int count_small = 5;
const unsigned int count_mid = 15;
const unsigned int count_big = 30;

// ****************************************************************************
// *                              UNIT TESTS                                  *
// ****************************************************************************

BOOST_AUTO_TEST_SUITE(vector_tests)

BOOST_AUTO_TEST_CASE_TEMPLATE(default_constructor_capacity, T, test_types)
{
    ft::vector<T>  v0;
    std::vector<T> v1;
    BOOST_CHECK_EQUAL( v0.capacity(), v1.capacity() );
}

BOOST_AUTO_TEST_CASE_TEMPLATE(default_constructor_size, T, test_types)
{
    ft::vector<T>  v0;
    std::vector<T> v1;
    BOOST_CHECK_EQUAL( v0.size(), v1.size() );
}

BOOST_AUTO_TEST_CASE_TEMPLATE(default_constructor_empty, T, test_types)
{
    ft::vector<T>  v0;
    std::vector<T> v1;
    BOOST_CHECK_EQUAL( v0.empty(), v1.empty() );
}

BOOST_AUTO_TEST_CASE_TEMPLATE(copy_constructor_capacity, T, test_types)
{
    ft::vector<T>  ft_v0;
    ft::vector<T>  ft_v1(ft_v0);
    std::vector<T> std_v0;
    std::vector<T> std_v1(std_v0);
    BOOST_CHECK_EQUAL( ft_v1.capacity(), std_v1.capacity() );
}

BOOST_AUTO_TEST_CASE_TEMPLATE(copy_constructor_size, T, test_types)
{
    ft::vector<T>  ft_v0;
    ft::vector<T>  ft_v1(ft_v0);
    std::vector<T> std_v0;
    std::vector<T> std_v1(std_v0);
    BOOST_CHECK_EQUAL( ft_v1.size(), std_v1.size() );
}

BOOST_AUTO_TEST_CASE_TEMPLATE(copy_constructor_empty, T, test_types)
{
    ft::vector<T>  ft_v0;
    ft::vector<T>  ft_v1(ft_v0);
    std::vector<T> std_v0;
    std::vector<T> std_v1(std_v0);
    BOOST_CHECK_EQUAL( ft_v1.empty(), std_v1.empty() );
}

BOOST_AUTO_TEST_CASE_TEMPLATE(constructor_with_values, T, test_types)
{
    ft::vector<T>  v0(count_small);
    std::vector<T> v1(count_small);
    BOOST_CHECK_EQUAL( v0.size(), v1.size() );
    BOOST_CHECK_EQUAL( v0.capacity(), v1.capacity() );
}

BOOST_AUTO_TEST_CASE_TEMPLATE(assign, T, test_types)
{
    ft::vector<T>  v0;
    std::vector<T> v1;
    v0.assign( count_small, T() );
    v1.assign( count_small, T() );

    for (size_t i = 0; i < count_small; i++)
        BOOST_TEST(v0[i] == v1[i]);
}

BOOST_AUTO_TEST_CASE(assign_iterators)
{
    std::vector<int>  v_source(count_big, 0);

    ft::vector<int>  v0;
    std::vector<int> v1;

    v0.assign( v_source.begin(), v_source.end() );
    v1.assign( v_source.begin(), v_source.end() );

    BOOST_CHECK_EQUAL( v0.size(), v1.size() );
    BOOST_CHECK_EQUAL( v0.capacity(), v1.capacity() );

    for (size_t i = 0; i < v0.size(); i++)
        BOOST_CHECK_EQUAL( v0[i], v1[i] );
}

BOOST_AUTO_TEST_CASE(assign_iterators_2)
{
    std::vector<int>  v_source(count_small, 0);

    ft::vector<int>  v0(count_big, 1);
    std::vector<int> v1(count_big, 1);

    v0.assign( v_source.begin(), v_source.end() );
    v1.assign( v_source.begin(), v_source.end() );

    BOOST_CHECK_EQUAL( v0.size(), v1.size() );
    BOOST_CHECK_EQUAL( v0.capacity(), v1.capacity() );

    for (size_t i = 0; i < v0.size(); i++)
        BOOST_CHECK_EQUAL( v0[i], v1[i] );
}

BOOST_AUTO_TEST_CASE_TEMPLATE(front, T, test_types)
{
    ft::vector<T>  v0(2);
    std::vector<T> v1(2);

    BOOST_CHECK_EQUAL( v0.front(), v1.front() );
}

BOOST_AUTO_TEST_CASE_TEMPLATE(back, T, test_types)
{
    ft::vector<T>  v0(2);
    std::vector<T> v1(2);

    BOOST_CHECK_EQUAL( v0.back(), v1.back() );
}

BOOST_AUTO_TEST_CASE(square_brackets)
{
    ft::vector<int>  v0(count_small);
    std::vector<int> v1(count_small);

    for (int i = 0; i < count_small; i++)
    {
        v0[i] = i;
        v1[i] = i;
    }
    for (int i = 0; i < count_small; i++)
        BOOST_CHECK_EQUAL( v0[i], v1[i] );
}

BOOST_AUTO_TEST_CASE(at)
{
    ft::vector<int>  v0(count_mid);
    std::vector<int> v1(count_mid);

    for (int i = 0; i < count_mid; i++)
    {
        v0[i] = i;
        v1[i] = i;
    }
    for (int i = 0; i < count_mid; i++)
        BOOST_CHECK_EQUAL( v0[i], v1[i] );
}

BOOST_AUTO_TEST_CASE(data)
{
    ft::vector<int>  v0(2);
    v0[0] = 0;

    int* p0 = v0.data();
    *(p0 + 1) = 1;

    BOOST_CHECK_EQUAL( v0[1], 1 );
}

BOOST_AUTO_TEST_CASE(begin)
{
    ft::vector<int> v(2);
    v[0] = 0;
    v[1] = 1;

    BOOST_CHECK_EQUAL( *(v.begin()), 0 );
}

BOOST_AUTO_TEST_CASE(end)
{
    ft::vector<int> v(2);
    v[0] = 0;
    v[1] = 1;

    BOOST_CHECK_EQUAL( *(v.end() - 1), 1 );
}

BOOST_AUTO_TEST_CASE(iterator)
{
    int i;
    ft::vector<int>  v0(count_big);
    std::vector<int> v1(count_big);

    i = 0;
    for (ft::vector<int>::iterator it = v0.begin(); it != v0.end(); it++)
        *it = (i++);
    i = 0;
    for (std::vector<int>::iterator it = v1.begin(); it != v1.end(); it++)
        *it = (i++);

    i = 0;
    for (; i != count_big; i++)
        BOOST_CHECK_EQUAL( v0[i], v1[i] );
}

BOOST_AUTO_TEST_CASE(rbegin)
{
    ft::vector<int> v(2);
    v[0] = 0;
    v[1] = 1;

    BOOST_CHECK_EQUAL( *(v.rbegin()), 1 );
}

BOOST_AUTO_TEST_CASE(rend)
{
    ft::vector<int> v(2);
    v[0] = 0;
    v[1] = 1;

    BOOST_CHECK_EQUAL( *(v.rend()), 0 );
}

BOOST_AUTO_TEST_CASE(reverse_iterator)
{
    int i;
    ft::vector<int>  v0(count_big);
    std::vector<int> v1(count_big);

    i = 0;
    for (ft::vector<int>::reverse_iterator it = v0.rbegin(); it != v0.rend(); it++)
        *it = (i++);
    i = 0;
    for (std::vector<int>::reverse_iterator it = v1.rbegin(); it != v1.rend(); it++)
        *it = (i++);

    i = 0;
    for (; i != count_big; i++)
        BOOST_CHECK_EQUAL( v0[i], v1[i] );
}

BOOST_AUTO_TEST_CASE_TEMPLATE(max_size, T, test_types)
{
    ft::vector<T>  v0;
    std::vector<T> v1;

    BOOST_CHECK_EQUAL( v0.max_size(), v1.max_size() );
}

BOOST_AUTO_TEST_CASE_TEMPLATE(reserve, T, test_types)
{
    ft::vector<T>  v0(count_small);
    std::vector<T> v1(count_small);

    v0.reserve(count_big);
    v1.reserve(count_big);

    BOOST_CHECK_EQUAL( v0.capacity(), v1.capacity() );
}

BOOST_AUTO_TEST_CASE(clear)
{
    ft::vector<int>  v(count_small);
    v.clear();

    BOOST_TEST( v.size() == 0 );
}

BOOST_AUTO_TEST_CASE(push_back)
{
    ft::vector<int>  v0;
    std::vector<int> v1;

    for (int i = 0; i < count_mid; i++)
    {
        v0.push_back(i);
        v1.push_back(i);
    }

    for (int i = 0; i < count_mid; i++)
        BOOST_CHECK_EQUAL( v0.at(i), v1.at(i) );
}

BOOST_AUTO_TEST_CASE(erase)
{
    ft::vector<int>  v0;
    std::vector<int> v1;

    for (int i = 0; i < count_mid; i++)
    {
        v0.push_back(i);
        v1.push_back(i);
    }
    v0.erase( v0.begin() + 1 );
    v1.erase( v1.begin() + 1 );
    v0.erase( v0.end() - 1 );
    v1.erase( v1.end() - 1 );

    for (int i = 0; i < ( count_mid - 2 ); i++)
        BOOST_CHECK_EQUAL( v0.at(i), v1.at(i) );
}

BOOST_AUTO_TEST_CASE(pop_back)
{
    ft::vector<int> v;
    v.push_back(0b100);
    v.push_back(0b1000);
    v.push_back(0b1111);
    v.push_back(0b10000);
    v.push_back(0b10111);
    v.push_back(0b101010);

    v.pop_back();

    BOOST_TEST( v.size() == 5 );
    BOOST_TEST( v.capacity() == 5 );
}

BOOST_AUTO_TEST_CASE(resize)
{
    ft::vector<int>  v0;
    std::vector<int> v1;

    for (int i = 0; i < count_small; i++)
    {
        v0.push_back(i);
        v1.push_back(i);
    }

    v0.resize(count_small - 1);
    v1.resize(count_small - 1);

    BOOST_CHECK_EQUAL( v0.capacity(), v1.capacity() );

    v0.resize(count_mid);
    v1.resize(count_mid);

    BOOST_CHECK_EQUAL( v0.capacity(), v1.capacity() );
}

BOOST_AUTO_TEST_CASE(swap)
{
    ft::vector<int> v0;
    v0.push_back(0);
    v0.push_back(1);

    ft::vector<int> v1;
    v1.swap(v0);

    BOOST_CHECK_EQUAL( v1[0], 0 );
    BOOST_CHECK_EQUAL( v1[1], 1 );
}

BOOST_AUTO_TEST_SUITE_END()
