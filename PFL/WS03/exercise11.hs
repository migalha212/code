myappend :: [a] -> [a] -> [a]
myappend xs ys = foldr (:) ys xs

myappend' :: [a] -> [a] -> [a]
myappend' = flip (foldr (:))