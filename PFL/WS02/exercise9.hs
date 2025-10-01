perfects :: Integer -> [Integer]
perfects n = [x | x <- [1..n], (sum (propDivs x)) == x]

propDivs :: Integer -> [Integer]
propDivs n = [x | x <- [1..(n -1)], rem n x == 0]