def above(tree:tuple, name:str, people_on_top:list = []):
    if type(tree) == str: 
        if people_on_top and name == tree: 
            return people_on_top 
        else: 
            return None

    if name == tree[0]: 
        if people_on_top: 
            return people_on_top 
        else:
            return None

    for x in tree[1]:
        result = above(x, name, people_on_top=people_on_top + [tree[0]])
        if result: 
            return result

print(above(('Jeff',[('Adam', ['Alice', 'Bob']),('Paul',['Eve', 'Louis']),('Roger',[('David',['Jack', 'John']), 'Peter'])]), 'Jack'))