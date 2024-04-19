def soup(matrix, word): 
     def soup_rec(matrix, word, line, col): 
         if word == "": return True 
         if matrix[line][col] != word[0]: return False 
         for l in [line-1,line,line+1]: 
             for c in [col-1,col,col+1]: 
                 if l != line and c != col: continue 
                 if l == line and c == col: continue 
                 try: 
                     if soup_rec(matrix, word[1:], l, c): return True 
                 except: pass 
         return False 
     for l in range(len(matrix)): 
         for c in range(len(matrix[0])): 
             if soup_rec(matrix, word, l, c): return f"{chr(ord('A')+l)}{c+1}"

print(soup([['X', 'R', 'Z', 'B', 'H', 'A'], ['K', 'A', 'S', 'I', 'G', 'O'], ['J', 'O', 'T', 'C', 'A', 'N'], ['F', 'S', 'R', 'H', 'T', 'U'], ['D', 'P', 'O', 'O', 'X', 'F'], ['Z', 'B', 'B', 'W', 'F', 'S']], 'POP'))