median :: Ord a => a -> a -> a -> a
median x y z
    | x > y = median y x z
    | y > z = median x z y
    | otherwise = y

median' :: (Ord a, Num a) => a -> a -> a -> a
median' x y z = (x + y + z) - min' - max'
    where min' = Prelude.min (Prelude.min x y) z
          max' = Prelude.max (Prelude.max x y) z