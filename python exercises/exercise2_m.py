def check_divisores(number):
          sum = 0
          for i in range(1, number):
             resto = number % i
             if resto == 0:
                sum = sum + i
          return sum

print(check_divisores(220))