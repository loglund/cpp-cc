module Main (main) where

import System.Exit

import Test.HUnit
import SomeFuncTest



main :: IO ()
main = do
    counts2 <- runTestTT (test [
            someFuncTests
            ])
    if (errors counts2 + failures counts2 == 0)
        then exitSuccess
        else exitFailure