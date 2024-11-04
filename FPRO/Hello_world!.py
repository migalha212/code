import string
import time
import colorama

def Hello_World():
    word = ""
    for char in "Hello World!":
        for letter in string.printable:
            time.sleep(0.005)
            if letter == char:
                word += letter
                print(word, end= '\r')
                break
            print(colorama.Fore.MAGENTA + word + letter,end='\r') 
    print(word)


if __name__ == "__main__":
    Hello_World()

