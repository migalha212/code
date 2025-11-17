dec2int :: Integral a => [a] -> a
dec2int = foldl (\acc x -> acc * 10 + x) 0

dec2int1 :: Integral a => [a] -> a
dec2int1 = foldl (\acc -> (+) (acc * 10)) 0

dec2int2 :: Integral a => [a] -> a
dec2int2 = foldl ((+) . (*10)) 0

-- eta reductions /\

myReverse :: [a] -> [a]
myReverse = foldl (\acc x -> x:acc) []

goodLuck :: [a] -> [a]
goodLuck = foldl (flip (:)) []

