#include "version.hpp"

namespace {{cookiecutter.namespace}} // namespace
{

inline namespace {{cookiecutter.name|upper}}_VERSION // namespace
{

std::string version()
{
    return std::string{ "{{cookiecutter.version}}"};
}

} // namespace {{cookiecutter.name | upper}}_VERSION

} // namespace {{cookiecutter.namespace}}