#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>

std::string		to_upper(std::string str)
{
	int		i = str.length();

	while (i >= 0)
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] -= 32;
		i--;
	}
	return str;
}

int		main(int ac, char **av)
{
	int				i;
	std::string		str;

	if (ac < 2)
		return 0;
	i = 1;
	while (av[i])
	{
		str = std::string(av[i]);

		std::ofstream	output ((str + std::string(".hpp")).c_str());
		output << "#ifndef " << to_upper(str) << "_HPP\n\n# define " << to_upper(str)
		<< "_HPP\n\n#include <iostream>\n#include <string>\n\n"
		<< "class\t" << str << "\n{\n\tpublic:\n"
		<< "\t\t" << str << "();\n"
		<< "\t\t~" << str << "();\n"
		<< "\t\t" << str << "( const " << str << " & );\n"
		<< "\t\t" << str << " &\toperator = ( const " << str << " & );\n"
		<< "};\n\n" << "#endif" << std::endl;

		std::ofstream	output2 ((str + std::string(".cpp")).c_str());
		output2 << "#include \"" << str << ".hpp\"\n\n"
		<< str << "::" << str << "()\n{\n\t\n}\n\n"
		<< str << "::~" << str << "()\n{\n\t\n}\n\n"
		<< str << "::" << str << "( const " << str << " & cpy )\n{\n\t*this = cpy;\n}\n\n"
		<< str << " &\t" << str << "::operator = ( const " << str << " & cpy )\n{\n\treturn *this;\n}";

		i++;
	}
	return 0;
}
