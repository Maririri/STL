#include <boost/fusion/include/vector10.hpp>
#include <boost/spirit/include/qi_bool.hpp>
#include <boost/spirit/include/qi_char_.hpp>
#include <boost/spirit/include/qi_grammar.hpp>
#include <boost/spirit/include/qi_operator.hpp>
#include <boost/spirit/include/qi_rule.hpp>
#include <boost/spirit/include/qi_string.hpp>

struct FourBools : boost::spirit::qi::grammar<
		char const*,
		boost::fusion::vector4<bool, bool, bool, bool>()
>
{
	typedef boost::fusion::vector4<bool, bool, bool, bool> attribute_type;

	FourBools() : base_type(start_)
	{
		using boost::spirit::bool_;

		start_
				=   "4bools:"
				>> bool_ >> ','
				>> bool_ >> ','
				>> bool_ >> ','
				>> bool_ >> ';'
				;
	}

private:
	boost::spirit::qi::rule<
			base_type::iterator_type,
			base_type::sig_type
	> start_;
};