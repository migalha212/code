-- lista infinita de todos os números primos
primos :: [Integer]
primos = crivo [2..]
    where
     crivo (p:xs) = p : filter (\x -> x`mod`p /= 0) (crivo xs)

-- contar primos entre a e b
listarPrimos :: Integer -> Integer -> [Integer]
listarPrimos a b = takeWhile (<=b) (dropWhile (<a) (primos))

-- 3) listar *todos* os pares de primos gémeos
gemeos :: [(Integer,Integer)]
gemeos = [(p1, p2)| (p1, p2) <- zip primos (tail primos),p2 - p1 == 2]


