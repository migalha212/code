isPrimeFast :: Integer -> Bool
isPrimeFast n
    | n <= 1    = False
    | otherwise = all (\d -> n `mod` d /= 0) [2 .. limit]
    where   limit = floor (sqrt (fromIntegral n))