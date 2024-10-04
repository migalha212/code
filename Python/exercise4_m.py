def check_friendly(number_one, number_two):
      def check_divisores(number):
          sum = 0
          for i in range(1, number):
             resto = number % i
             if resto == 0:
                sum = sum + i
          return sum
      check1 = (check_divisores(number_one) == number_two)
      check2 = (check_divisores(number_two) == number_one)
      check3 = (number_one == number_two)
      if check3:
         result = f'identical numbers: {number_one}'
         return result
      elif check1 and check2:
         result = f'{number_one} and {number_two} are friendly'
         return result
      elif (check2 and not check1) or (not check1 and not check2):
         result = f'sum of divisors of {number_one} is not {number_two}'
         return result
      elif not check2 and check1:
         result = f'sum of divisors of {number_two} is not {number_one}'
         return result





    