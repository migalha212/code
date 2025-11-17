-- map: Takes a function and a list, applies said function to all elements
-- filter: Takes a function with a condition and a list, if element passes the condition it stays otherwise is deleted from method
-- zipWith: Takes a function and 2 lists, creating a joint function by applying with an element of each list, if list size is not equal, smalest size is taken

{-
    ((+2).(*3))10
    . - function composition, to do one after the other
    f = (+2), g = (*3) f . g = (+2)((*3)10) = (+2)30 = 32

    lambda: (\x -> x*2); shorthand equivalent: *2

    $: Argument passing symbol

!   sqrt $1 + 2 + 3 = sqrt 6
!   sqrt 1 + 2 + 3 = 6

-- foldl: takes a function, an initial value for the acumulator and a list, applies the acumulator at the left of the list, using it as the first element and going through each
*   folds from left to right, usually more efficient, O(n)
*   equivalent to acumulator based recursive functions
    ((0-1)-2)-3 = -6
!   or as a lambda    (\acc x -> acc - x)
-- foldr: takes a function, an initial value for the acumulator and a list, with the acumulator as the right most element
*   folds from right to left, usually less efficient, O(n^2)
*   equivalent to naive recursive functions
    1-(2-(3-0)) = 2
!   or as a lambda     (\x acc -> x - acc)
*   the acumulator dictates where the innermost parenthesis is
-}