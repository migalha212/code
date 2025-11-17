divisors :: Integer -> [Integer]
divisors n = [d | d<-[1..n], mod n d == 0]

divisors' :: Integer -> [Integer]
divisors' n = filter (\x -> mod n x == 0) [1..n] 