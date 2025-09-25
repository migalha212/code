{-
Write two definitions, one using conditional expressions and another using
guards for the function classify :: Int -> String that gives a qualititive
marks for a grade from 0 to 20 according to the following table.
≤ 9 "failed"
10–12 "passed"
13–15 "good"
16–18 "very good"
19–20 "excellent"
-}

classify :: Int -> String
classify s
    | s >= 0 && s <= 9 = "failed"
    | s <= 12 = "passed"
    | s <= 15 = "good"
    | s <= 18 = "very good"
    | s <= 20 = "excellent"
    | otherwise = "invalid"