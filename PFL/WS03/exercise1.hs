mapFilter :: (a->b) -> (a->Bool) -> [a] -> [b]
mapFilter f p = map f . filter p

-- /\ Exercise 3.1 from the book
-- /\