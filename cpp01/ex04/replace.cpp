#include "replace.hpp"


void Replace::ft_replace(void)
{
    std::ifstream infile(filename.c_str());
    std::string line;
    size_t found;
    size_t pos;
    if (!infile)
    {
        std::cerr << "Error: Cannot open file " << filename << "\n";
        return ;
    }
    std::ofstream outfile((filename + ".replace").c_str());
    while (std::getline(infile, line))
    {
        std::string result;
        pos = 0;
        while ((found = line.find(s1, pos)) != std::string::npos)
        {
            result += line.substr(pos, found - pos); 
            result += s2; 
            pos = found + s1.length(); 
        }
        result += line.substr(pos); 
        outfile << result << "\n"; 
    }
    std::cout << "Replacement done!" << std::endl;
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