#include <{{cookiecutter.name}}/version.hpp>

#include <iostream>

int main()
{
    std::cout << {{cookiecutter.name}}::version() << std::endl;

    return 0;
}