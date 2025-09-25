{-
The body mass index (BMI) is a simple measure for classifying the weight
of adult individuals.1 The BMI is computed from the individual’s weight and
height (in Kg and meters):
BMI = weight/height2
For example: an individual with 70Kg and 1.70m height has a BMI of 70/1.702 ≈
24.22. We can classify the result in the following intervals:
BMI < 18.5 "underweight"
18.5 ≤ BMI < 25 "normal weight"
25 ≤ BMI < 30 "overweight"
30 ≤ BMI "obese"
Write a definition of the functions classifyBMI :: Float -> Float -> String
to implement the above classification table. The two function arguments are,
respectively, the weight and height.

-}

classifyBMI :: Float -> Float -> String
classifyBMI weight height 
    | bmi < 0 = "invalid"
    | bmi >= 0 && bmi < 18.5 = "underweight"
    | bmi < 25 = "normal weight"
    | bmi < 30 = "overweight"
    | otherwise = "obese"
    where bmi = weight / (height * height)