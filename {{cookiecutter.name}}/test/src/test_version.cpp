// Copyright (c) Steinwurf ApS 2020.
// All Rights Reserved
//
// Distributed under the "BSD License". See the accompanying LICENSE.rst file.

#include <gtest/gtest.h>
#include <{{cookiecutter.name}}/version.hpp>

TEST(test_some, return_value_of_some_method) {
  auto version = {{cookiecutter.namespace}}::version();
  EXPECT_EQ(version, "{{cookiecutter.version}}");
}