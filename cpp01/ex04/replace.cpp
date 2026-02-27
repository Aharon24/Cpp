#include "replace.hpp"


void Replace::ft_replace(void)
{
    std::ifstream infile(filename.c_str());
    if (!infile)
    {
        std::cerr << "Error: Cannot open file " << filename << "\n";
        return ;
    }
}


Replace::Replace()
{

}
Replace::Replace (std::string &f, std::string &s_1 ,std::string &s_2): filename(f),s1(s_1), s2(s_2)
{
}
Replace::~Replace ()
{

}