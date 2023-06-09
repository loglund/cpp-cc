#pragma once

#include <string>

namespace {{cookiecutter.namespace}} // namespace
{

#define {{cookiecutter.version_namespace}} v_0_0_0

inline namespace {{cookiecutter.version_namespace}} // namespace
{

    std::string version();

}
}