#include "version.hpp"

namespace {{cookiecutter.name}}
{

std::string version()
{
    return std::string{ "{{cookiecutter.version}}"};
}

}