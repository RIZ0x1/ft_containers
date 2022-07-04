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
    ft::vector<int>  v0(1);
    std::vector<int> v1(1);

    BOOST_CHECK_EQUAL( v0[0], v1[0] );
}

BOOST_AUTO_TEST_SUITE_END()
