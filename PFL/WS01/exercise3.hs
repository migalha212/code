-- Define a function to get the second element from a list
second :: [a] -> a
second l = head (drop 1 (take 2 l))
second' l = head (tail l)

-- The function last gets the last element of a list
last :: [a] -> a
last l = head (reverse l)

-- Define the init function that removes the last element from a list.
init :: [a] -> [a]
init l = reverse (tail (reverse l))

--  Define a middle function that gives que the middle element in a list.
middle :: [a] -> a
middle l = head (drop half l)
    where half = div (length l) 2

--   Define a function checkPalindrome that checks if a string is a palindrome
checkPalindrome :: String -> Bool
checkPalindrome l = l == (reverse l)