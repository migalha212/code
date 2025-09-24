triangleArea :: Floating a => a -> a -> a -> a
triangleArea a b c = sqrt(s*(s- a)*(s-b)*(s-c))
    where s = (a + b + c) / 2


triangleArea2 :: Floating a => a -> a -> a -> a
triangleArea2 a b c = let s = (a+b+c)/2 in
    sqrt(s*(s-a)*(s-b)*(s-c))