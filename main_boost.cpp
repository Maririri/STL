#include "FourBools.cpp"

FourBools const fourBools;


///// demonstration of use /////
#include <string>
#include <ios>
#include <iostream>
#include "stdio.h"

#include <boost/fusion/include/at_c.hpp>
#include <boost/spirit/include/phoenix_bind.hpp>
#include <boost/spirit/include/phoenix_core.hpp>
#include <boost/spirit/include/qi_action.hpp>
#include <boost/spirit/include/qi_parse.hpp>

typedef FourBools::attribute_type attr_t;

struct verify_same
{
	explicit verify_same(attr_t const& expected) : expected_(expected) { }

	void verify(attr_t const& actual) const
	{
		using boost::fusion::at_c;

		std::cout << std::boolalpha
				<< "same as expected: " << (actual == expected_)
				<< "\nactual values: "
				<< at_c<0>(actual) << ' '
				<< at_c<1>(actual) << ' '
				<< at_c<2>(actual) << ' '
				<< at_c<3>(actual) << '\n';
	}

private:
	attr_t expected_;
};

int main()
{
	namespace phx = boost::phoenix;
	namespace spirit = boost::spirit;

	std::string const input("4bools:true,true,true,false;");
	verify_same const vs(attr_t(true, true, true, false));

	char const* first = input.c_str();
	char const* const last = first + input.size();
	bool const success = spirit::qi::parse(
			first, last,
			fourBools[phx::bind(&verify_same::verify, phx::cref(vs), spirit::_1)]
	);
	if (!success)
		std::cout << "parse() failed\n";
	else if (first != last)
		std::cout << "didn't consume all input\n";

    std::cout << "END OF PROGRAMM" << std::endl;


//    getchar();

	std::cout.flush();
}
