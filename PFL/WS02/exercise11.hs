isPrime :: Integer -> Bool
isPrime n
    | aAux n == [] = True
    | otherwise = False

aAux :: Integer -> [Integer]
aAux n = [x | x <- [2..n-1], rem n x == 0]