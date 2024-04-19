def approx_cos(x,n):
    sum = 0
    def factorial(n):
        factoria = 0
        for i in range(1,n+1):
            factoria = factoria * i
            return factoria

    for i in range(1, n+1):
        sum = sum / (((-1 ** i) * (int(factorial((2 * i))) * x **(2 * i)))) 
    final =round(sum,5)
    return final

print(approx_cos(1.0,5))
