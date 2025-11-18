{-
We want to implement a safetail :: [a] -> [a] function that behaves
like tail but gives the empty list when the argument is empty. Write three
distinct definitions using conditional expressions, guards and patterns.
-}

safetail :: [a] -> [a]
safetail l 
    | len <= 0 = []
    | otherwise = drop 1 l 
    where len = length l - 1