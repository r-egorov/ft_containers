#ifndef MYCLASS_HPP
# define MYCLASS_HPP

# include <string>

class MyClass
{
    private:
        int         _n;
        std::string _s;

    public:
        MyClass(void);
        MyClass(int n, std::string s);
        MyClass(const MyClass& other);
        ~MyClass();

        MyClass&    operator=(const MyClass& other);

        int         getN(void) const;
        std::string getS(void) const;

        void    setN(int n);
        void    setS(std::string s);

        class CustomException : public std::exception
        {
            public:
                const char	*what(void) const throw();
        };
};

std::ostream	&operator << (std::ostream &o, MyClass const &obj);

#endif