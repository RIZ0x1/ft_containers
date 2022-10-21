#define BOOST_TEST_MAIN
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE ft_containers
#include <boost/test/included/unit_test.hpp>
#include <boost/test/test_case_template.hpp>
#include <boost/mpl/list.hpp>

#include <memory>
#include <vector>
#include <stack>
#include "../src/map/map.hpp"

typedef boost::mpl::list<int, float, double, char> test_types;

const unsigned int count_small = 5;
const unsigned int count_mid = 15;
const unsigned int count_big = 30;

// ****************************************************************************
// *                              UNIT TESTS                                  *
// ****************************************************************************

BOOST_AUTO_TEST_SUITE(map_tests)

BOOST_AUTO_TEST_CASE_TEMPLATE(default_constructor_size, T, test_types)
{
	ft::map<int, T>  m0;
	std::map<int, T> m1;
	BOOST_CHECK_EQUAL( m0.size(), m1.size() );
}

BOOST_AUTO_TEST_CASE_TEMPLATE(default_constructor_max_size, T, test_types)
{
	ft::map<int, T>  m0;
	std::map<int, T> m1;
	BOOST_CHECK_EQUAL( m0.max_size(), m1.max_size() );
}
