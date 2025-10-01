propDivs :: Integer -> [Integer]
propDivs n = [x | x <- [1..(n -1)], rem n x == 0]