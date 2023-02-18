module SomeFuncTest where

import Test.HUnit

import {{cookiecutter.module}}

testSomeFunc :: Test
testSomeFunc = TestCase (assertEqual "someFunc" ("someFunc") (someFunc ()))

someFuncTests :: Test
someFuncTests = test [ "testSomeFunc" ~: "someFunc" ~: ("someFunc") ~?= (someFunc ()) ]

