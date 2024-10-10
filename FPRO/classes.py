class test:
    '''Masterclass em classes'''
    def __init__(self,life,attack):
        self.life = life
        self.attack = attack

def hit(p1,p2):
    p2.life -= p1.attack
    if p2.life <= 0:
        print(f'{p2} is dead')


player = test(100,15)
enemy = test(19,200)

hit(player,enemy)
hit(player,enemy)
hit(player,enemy)