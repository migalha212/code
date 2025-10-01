-- * ' -> lista em comprensão, '' -> função recursiva

-- redefinition of the concat function

-- Takes a list of lists and reduces a dimension
concat' :: [[a]] -> [a] 
concat' l = [x | y <- l, x <- y]

-- recursive concat
concat'' :: [[a]] -> [a]
concat'' [] = []
concat'' (h:t) = h ++ concat'' t

-- redefinition of the replicate function

replicate' :: Integral b => b -> a -> [a]
replicate' n x = [x | _ <- [1..n]]

replicate'' :: Integral b => b -> a -> [a]
replicate'' 0 _ = []
replicate'' n x
    | n > 0 = x:(replicate'' (n-1) x)
    | n < 0 = error "Negative input"    

-- ! defining an infix function

-- redefinition of the !! (index) function
(@@) :: Integral b => [a] -> b -> a
l @@ n = head [x | (x,i) <- zip l [0 ..], i == n]

(@@@) :: Integral b => [a] -> b -> a
[] @@@ _ = error "No index given >:("
(x:_) @@@ 0 = x
(x:xs) @@@ n 
    | n < 0 = error "Negative input"
    | n > 0 = xs @@@ (n-1)

-- takes a list and returns the reversed list
rev :: [a] -> [a]
rev [] = []
rev (h:t) = (rev t) ++ [h]

-- reverse with acumulator, uses an extra auxiliary method

rev' :: [a] -> [a]
rev' l = rev'Aux l []

-- Usually when a method with an acumulator reaches base case
-- it is time to return it as is most of the times
-- mux more efficient solution of the 2

rev'Aux :: [a] -> [a] -> [a]
rev'Aux [] acc = acc
rev'Aux (x:xs) acc = rev'Aux xs (x:acc)

{- testing eficiency
:set +s 
* prints the time taken to execute the method
-}

