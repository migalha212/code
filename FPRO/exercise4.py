def next_prime(number):
    number += 1
    n = True

    while n:
        for i in range(2,number+1):
            
            if number % i == 0:break
            if number / i == 1:return number

        number += 1    




             
 
    return number


print(next_prime(12))




