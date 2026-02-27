#include <fstream>
#include <string>
#include <iostream>

class  Replace 
{
    private:
        std::string filename;
        std::string s1;
        std::string s2;
    public:
        Replace (std::string &f, std::string &s1 ,std::string &s2);
        Replace();
        ~Replace ();
        void ft_replace(void);
};