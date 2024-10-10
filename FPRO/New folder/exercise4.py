def move_ball(board:list):

    def move_aux(board,cardinal,curpos):
        if board[curpos[0]][curpos[1]] == 'X':
            return result
        elif cardinal == 'E':
             result.append(((curpos[0],curpos[1]+1)))
             if board[curpos[0]][curpos[1]+1] == ' ':
                 return move_aux(board,cardinal,(curpos[0],curpos[1]+1))
             elif board[curpos[0]][curpos[1]+1] == '/':
                 return move_aux(board,'N',(curpos[0],curpos[1]+1))
             elif board[curpos[0]][curpos[1]+1] == '\\':
                 return move_aux(board,'S',(curpos[0],curpos[1]+1))
             
        elif cardinal == 'W':
             newpos = (curpos[0],curpos[1]-1)
             result.append(((curpos[0],curpos[1]-1)))
             return move_aux(board,cardinal,newpos) if board[newpos[0]][newpos[1]] == ' ' else move_aux(board,'S',newpos) if board[newpos[0]][newpos[1]] == '/' else move_aux(board,'N',newpos)            

        elif cardinal == 'N':
            newpos = (curpos[0]-1,curpos[1])
            result.append(newpos)
            if board[curpos[0]-1][curpos[1]] == ' ':
                return move_aux(board,cardinal,(curpos[0]-1,curpos[1]))
            elif board[curpos[0]-1][curpos[1]] == '/':
                return move_aux(board,'E',(curpos[0]-1,curpos[1]))
            elif board[curpos[0]-1][curpos[1]] == '\\':
                return move_aux(board,'W',(curpos[0]-1,curpos[1]))

        elif cardinal == 'S':
            newpos = (curpos[0]+1,curpos[1])
            result.append(newpos)
            if board[curpos[0]+1][curpos[1]] == ' ':
                return move_aux(board,cardinal,(curpos[0]+1,curpos[1]))
            elif board[curpos[0]+1][curpos[1]] == '/':
                return move_aux(board,'W',(curpos[0]+1,curpos[1]))
            elif board[curpos[0]+1][curpos[1]] == '\\':
                return move_aux(board,'E',(curpos[0]+1,curpos[1]))         
    result = []
    board = list(map(list,board))

    for i in range(len(board)):
        for j in range(len(board[i])):
            if board[i][j] in ['E','W','S','N']:
                c = board[i][j]
                board[i][j] = ' '
                result.append((i,j))
                move_aux(board,c,[i,j])


                           
    return result

import functools
functools.reduce(,[1,2,3,4,5])
