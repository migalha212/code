f :: [a] -> (a,[a])
f (_:_:x:y) = (x,y)

{- FT-10
a) what does it compute: 
b) Implement function f using functions from the Prelude, and without using
pattern matching nor recursion.
-}

f' :: [a] -> (a,[a])
f' l = (head b, tail b)
    where b = drop 2 l

{- LI-17
Implement differentFromNext which receives a list and returns all the elements that are different to the one that comes next in the list.
Usage examples:
-}

differentFromNext :: Eq a => [a] -> [a]
differentFromNext [] = []
differentFromNext [_] = []
differentFromNext (x:y:xs)
    |  x == y = differentFromNext (y : xs)
    | otherwise = x : differentFromNext (y:xs)

-- LI-31 List comprehension version

differentFromNext' :: Eq a => [a] -> [a]
differentFromNext' l = [ x | (x,y) <- zip l (tail l), x /= y]

{- IP-5
Implement reverseUntil, which reads lines from the keyboard and prints
them in reverse until an empty line is typed
-}

reverseUntil :: IO ()
reverseUntil = do
    input <- getLine
    let x = input
    if null x
        then return ()
    else do
        putStrLn (reverse x)
        reverseUntil

{- UT-18
Implement insert, which inserts a key into a BST and returns the resulting
tree. If the key is already present, then the function returns the same tree it
received as input.
-}

data Bst a = Empty | Node (Bst a) a (Bst a)
    deriving Show

insert' :: (Eq a,Ord a) => a -> Bst a -> Bst a
insert' key Empty = Node Empty key Empty
insert' key (Node left val right)
    | key == val =  Node left val right
    | key < val = Node (insert' key left) val right
    | otherwise = Node left val (insert' key right)


{- HO-13

Indicate the result of the following expressions:
a) map (replicate 3)[1..3] -> [[1,1,1],[2,2,2][3,3,3]]
b) map (‘div‘ 3)[1..10] -> [0,0,1,1,1,2,2,2,3,3] operador de divisão de inteiros
c) filter even (map (^2)[1..]) -> infinite list of all squared even numbers, since odd * odd is still odd, doesn't pass filter
d) sum (takeWhile (<= 100)(filter even (map (^2)[1..]))) -> the sum of all squared even numbers below 100, so 220
e) zipWith (xy -> (x * 10 + 3)/ y)[5,4,3,2,1] [1,2,3,4,5] -> [53,43/2,11,23/4,13/5]
f) takeWhile (<200)(iterate (3*)1) -> [1,3,9,27,81]
g) length(filter (<=’z’)[’a’..]) -> 26

-}

{- FT-14
Implement the scalarProduct, which computes the scalar product between
two lists X and Y with the same length n, using the formula:
-}

scalarProduct :: Num a => [a] -> [a] -> a
scalarProduct [] [] = 0
scalarProduct (x:xs) (y:ys) = x*y + scalarProduct xs ys

scalarProduct' :: Num a => [a] -> [a] -> a
scalarProduct' l1 l2 = sum [x * y | (x,y) <- zip l1 l2]

{- HO-18
Consider the myAll function, which, similarly to Prelude’s any, given a
predicate p and a list l, checks if all the elements of l satisfy p.
a) Implement myAll using recursion (and without using user higher-order
functions).
b) Implement myAll using a list comprehension and the ‘and’ function, and
without using recursion.
c) Implement myAll using map and without using recursion or list comprehensions.
d) Implement myAll using any and without using map, recursion or list
comprehensions.
e) Implement myAll using other higher-order functions (other than map, any
and all) and without using recursion or list comprehensions.
-}

-- a)
myAll :: [a] -> (a->Bool) -> Bool
myAll [] _ = True
myAll (x:xs) f
    | f x = myAll xs f
    | otherwise = False

-- b)
myAll' :: [a] -> (a->Bool) -> Bool
myAll' l f = and [f x | x <- l]

-- c)
myAll'' :: [a] -> (a->Bool) -> Bool
myAll'' l f = (and . map f) l

-- d)
myAll''' :: [a] -> (a->Bool) -> Bool
myAll''' l f = not (any (not . f) l)

-- e)
myAll'''' :: [a] -> (a->Bool) -> Bool
myAll'''' l f = null (filter (not . f) l)


{- LI-10
Implement myCycle, which, similarly to Prelude’s cycle, creates an infinite
list where the input list is concatenated to itself an infinite number of times
-}

myCycle :: [a] -> [a]
myCycle [] = []
myCycle l = [x | y <- [1..], x <- l]

{-
Explain why computing the following expression leads to an error: sentence
,→ = "Hello,␣my␣name␣is␣"++ getLine .
getline is an IO action, not a string/list, so it doesn't work
-}

{- LI-16
a) Implement myZip, which, similarly to Prelude’s zip, returns a list of pairs
containing the elements of both input lists occurring at the same positions. The
length of the output is equal to the length of the shortest of the input lists.
b) Implement myZip3, which, similarly to Prelude’s zip3, returns a list of
triples containing the elements of the three input lists occurring at the same
positions. The length of the output is equal to the length of the shortest of the
input lists.
-}

-- a)
myZip :: [a] -> [b] -> [(a,b)]
myZip [] _ = []
myZip _ [] = []
myZip (x1:xs1) (x2:xs2) = (x1,x2) : myZip xs1 xs2

-- b)
myZip3 :: [a] -> [b] -> [c] -> [(a,b,c)]
myZip3 (x1:x2) (y1:y2) (z1:z2) = (x1,y1,z1) : myZip3 x2 y2 z2
myZip3 _ _ _ = []

{- LI-33
Implement myZip3, which, similarly to Prelude’s zip3, returns a list of triples
containing the elements of the three input lists occurring at the same positions.
Suggestion: use zip.
-}
myZip3' :: [a] -> [b] -> [c] -> [(a,b,c)]
myZip3' l1 l2 l3 = [(x,y,z) | ((x,y),z) <- zip (zip l1 l2) l3]

{- HO-32
Using a fold, implement myMap, which works similarly to Prelude’s map.
-}

myMap :: (a -> b) -> [a] -> [b]
myMap f =  foldr(\x acc -> (f x):acc) [] 

{- UT-12
Define the type SyntaxTree , which represents a syntax tree.
The definition should use three value constructors:
• One for leaves, which contain a constant value.
• Another for nodes of unary functions, which have a child and contain a unary
function.
• Another for nodes of binary functions, which have two children and contain
a binary function.
-}

data SyntaxTree a = Const a | Unary (a -> a) (SyntaxTree a) | Binary (a->a->a) (SyntaxTree a) (SyntaxTree a)

{- UT-13
Implement countConsts, which counts the number of constants/leaves in a
SyntaxTree .
-}

countConsts :: Integral b => SyntaxTree a -> b
countConsts (Const _) = 1 
countConsts (Binary f a b) = countConsts a + countConsts b
countConsts (Unary f a) = countConsts a 

{- UT-14
Implement compute, which computes the result of the underlying expression
of a SyntaxTree .
-}

compute :: SyntaxTree a -> a
compute (Const a) = a
compute (Unary f a) = f (compute a)
compute (Binary f a b) = f (compute a) (compute b) 

{- LI-29
Indicate the result of each expression.
a) [mod x 7 | x <- ([1..5] ++ [16..23])] -> [1,2,3,4,5,2,3,4,5,6,0,1,2]
b) [x ++ "the"++ y | x <- ["buy","loan"], y <- ["car","house"]] -> ["buythecar","buythehouse","loanthecar","loanthehouse"]
c) [x | x <-[-5..5], abs(x^3)<= 20] -> [-2 -1 0 1 2]
d) take 10 [-x | x <- cycle [4,7,8]] -> [-4,-7,-8,-4,-7,-8,-4,-7,-8,-4]
e) take 10 [ 5*x*y | x<-[1..], y <-[1..]] ->  [5,10,15,20,25,30,35,40,45,50]
f) [(a+1,b)| (a,b)<- zip [1..3] [10..]] -> [(2,10),(3,11),(4,12)]
g) [[x | (x,y)<- zip xs (tail xs), x > y] | xs <- [[3,4,3],[4,3,3],[4,2,3,1],[5,4,1],[4,3,2,1]]] -> [[4],[4],[4,3],[5,4],[4,3,2]]
-}

{- FT-19
Consider the definition of function f below: -}
f'' :: (Ord a) => [a] -> a
f'' [] = error "Empty␣list"
f'' [_] = error " Singleton "
f'' (x:y:zs)
    | x > y = g zs x y
    | otherwise = g zs y x
g :: (Ord a) => [a] -> a -> a -> a
g [] _ y = y
g (z:zs) x y
    | z >= x = g zs z x
    | z >= y = g zs x z
    | otherwise = g zs x y
-- Explain concisely what function f'' computes.
