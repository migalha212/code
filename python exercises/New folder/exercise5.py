import random

def cows_bulls(seed):
    random.seed(seed)

    def game(guess):
     correct = random.randint(0,9999)
     result = [0,0]
     correct = list(str(correct))
     guess = list(str(guess))
     for i in range(len(correct)):
        if correct[i] == guess[i]:
           correct[i] = 'a'
           guess[i] = 'b'
           result[0] += 1
     for i in guess:
           if i in correct:
              result[1] += 1
              correct.remove(i)
     return tuple(result)            
    return game



