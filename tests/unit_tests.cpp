#define BOOST_TEST_MAIN
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE ft_containers
#include <boost/test/included/unit_test.hpp>
#include <boost/test/test_case_template.hpp>
#include <boost/mpl/list.hpp>

#include <vector>
#include <stack>
// #include <map>
#include "../src/vector/vector.hpp"
#include "../src/stack/stack.hpp"
// #include "../src/map/map.hpp"

typedef boost::mpl::list<int, float, double, char> test_types;

const unsigned int count_small = 5;
const unsigned int count_mid = 15;
const unsigned int count_big = 30;

// ****************************************************************************
// *                                VECTOR                                    *
// ****************************************************************************

BOOST_AUTO_TEST_SUITE(vector_tests)

BOOST_AUTO_TEST_CASE_TEMPLATE(default_constructor_capacity, T, test_types)
{
    ft::vector<T>  v0;
    std::vector<T> v1;
    BOOST_REQUIRE_EQUAL( v0.capacity(), v1.capacity() );
}

BOOST_AUTO_TEST_CASE_TEMPLATE(default_constructor_size, T, test_types)
{
    ft::vector<T>  v0;
    std::vector<T> v1;
    BOOST_REQUIRE_EQUAL( v0.size(), v1.size() );
}

BOOST_AUTO_TEST_CASE_TEMPLATE(default_constructor_empty, T, test_types)
{
    ft::vector<T>  v0;
    std::vector<T> v1;
    BOOST_REQUIRE_EQUAL( v0.empty(), v1.empty() );
}

BOOST_AUTO_TEST_CASE_TEMPLATE(copy_constructor_capacity, T, test_types)
{
    ft::vector<T>  ft_v0;
    ft::vector<T>  ft_v1(ft_v0);
    std::vector<T> std_v0;
    std::vector<T> std_v1(std_v0);
    BOOST_REQUIRE_EQUAL( ft_v1.capacity(), std_v1.capacity() );
}

BOOST_AUTO_TEST_CASE_TEMPLATE(copy_constructor_size, T, test_types)
{
    ft::vector<T>  ft_v0;
    ft::vector<T>  ft_v1(ft_v0);
    std::vector<T> std_v0;
    std::vector<T> std_v1(std_v0);
    BOOST_REQUIRE_EQUAL( ft_v1.size(), std_v1.size() );
}

BOOST_AUTO_TEST_CASE_TEMPLATE(copy_constructor_empty, T, test_types)
{
    ft::vector<T>  ft_v0;
    ft::vector<T>  ft_v1(ft_v0);
    std::vector<T> std_v0;
    std::vector<T> std_v1(std_v0);
    BOOST_REQUIRE_EQUAL( ft_v1.empty(), std_v1.empty() );
}

BOOST_AUTO_TEST_CASE_TEMPLATE(constructor_with_values, T, test_types)
{
    ft::vector<T>  v0( count_small, T() );
    std::vector<T> v1( count_small, T() );
    BOOST_REQUIRE_EQUAL( v0.size(), v1.size() );
    BOOST_REQUIRE_EQUAL( v0.capacity(), v1.capacity() );
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

BOOST_AUTO_TEST_SUITE_END()

// ****************************************************************************
// *                                 STACK                                    *
// ****************************************************************************
