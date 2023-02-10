module {{cookiecutter.module}}Spec (main, spec) where

import Test.Hspec
import Test.QuickCheck

import {{cookiecutter.module}}

main :: IO ()
main = hspec spec

spec :: Spec
spec = do
  describe "someFunc" $ do
    it "prints 'someFunc'" $ do
        someFunc `shouldReturn` ()