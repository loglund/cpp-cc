#include "version.hpp"

namespace {{cookiecutter.name}} // namespace
{

std::string version()
{
    return std::string{ "{{cookiecutter.version}}"};
}

} // namespace {{cookiecutter.namespace}}