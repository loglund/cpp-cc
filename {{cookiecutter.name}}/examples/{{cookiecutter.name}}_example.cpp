#include <{{cookiecutter.name}}/version.hpp>

#include <iostream>

int main()
{
    std::cout << {{cookiecutter.namespace}}::version() << std::endl;

    return 0;
}