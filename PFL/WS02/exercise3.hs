{-
Consider two definitions of the max e min from the standard Prelude:
max, min :: Ord a => a -> a -> a
max x y = if x>=y then x else y
min x y = if x<=y then x else y
(a) Write similar definitions for two functions max3 e min3 that compute the
maximum and minimum between three values.
(b) Observe that the maximum and minimum operations are associative: to
compute the maximum of three values we can compute the maximum
between two of them and then the maximum between the result and third
value. Re-write the function max3 and min3 using this idea and the Prelude
max e min functions.
-}

max', min' :: Ord a => a -> a -> a -> a
max' x y z = if x >= y then if x >= z then x else z else if y >= z then y else z
min' x y z = if x <= y then (if x <= z then x else z) else if y <= z then y else z

max, min :: Ord a => a -> a -> a
max x y = if x>=y then x else y
min x y = if x<=y then x else y

max'', min'' :: Ord a => a -> a -> a -> a
max'' x y z= Prelude.max (Prelude.max x y) z
min'' x y z= Prelude.min (Prelude.min x y) z