pyths :: Integer -> [(Integer,Integer,Integer)]
pyths n = [ (x,y,z) | x <- [1..n], y <- [1..n], z <- [1..n], x*x + y*y == z*z ]

pyths' :: Integer -> [(Integer,Integer,Integer)]
pyths' n = 
  [ (x,y,z)
  | x <- [1..n]
  , y <- [1..n]
  , let s = x*x + y*y
  , let z = floor (sqrt (fromIntegral s))
  , z*z == s
  , z <= n
  ]
