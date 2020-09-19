from copy import deepcopy

class G: # trick for global variables in python
    count =0 
    colup = [4, 3, 2, 1]
    coldown = [1, 2, 2, 2]
    rowleft = [4, 3, 2, 1]
    rowright = [1, 2, 2, 2]

def count_visible_row_left(t,row):
    max_sofar = 0
    vis_sofar = 0
    for i in [0,1,2,3]:
        if t[row][i] > max_sofar:
            max_sofar = t[row][i]
            vis_sofar+=1
    return vis_sofar

def count_visible_row_right(t,row):
    max_sofar = 0
    vis_sofar = 0
    for i in [3,2,1,0]:
        if t[row][i] > max_sofar:
            max_sofar = t[row][i]
            vis_sofar+=1
    return vis_sofar


def count_visible_col_up(t,col):
    max_sofar = 0
    vis_sofar = 0
    for i in [0,1,2,3]:
        if t[col][i] > max_sofar:
            max_sofar = t[i][col]
            vis_sofar+=1
    return vis_sofar

def count_visible_col_down(t,col):
    max_sofar = 0
    vis_sofar = 0
    for i in [3,2,1,0]:
        if t[col][i] > max_sofar:
            max_sofar = t[i][col]
            vis_sofar+=1
    return vis_sofar

def vis_ok(t):
    for i in range(4):
        if G.colup[i]!=count_visible_col_up(t,i): return False
        if G.coldown[i]!=count_visible_col_down(t,i): return False
        if G.rowleft[i]!=count_visible_row_left(t,i): return False
        if G.rowright[i]!=count_visible_row_right(t,i): return False
    return True

def myprint(t):
    t = [[str(t[i][j]) for j in range(4)] for i in range(4)]
    print(["".join(t[i]) for i in range(4)])

def fill_row(board, row):
    """ fill row with all possible permutations"""
    if row>=4: 
        G.count +=1
        if vis_ok(board):    
            myprint(board)
        return
    t = deepcopy(board) # en C il faut faire un malloc et copier les valeurs avec une double boucle
    for a in [1,2,3,4]:
        t[row][0] = a
        for b in [1,2,3,4]:
            if b == a: continue
            t[row][1] = b
            for c in [1,2,3,4]:
                if c == a or c == b: continue
                t[row][2] = c
                for d in [1,2,3,4]:
                    if d == a or d == b or d == c: continue
                    t[row][3] = d
                    if row_ok(t,row): fill_row(t,row+1) # fill next row
    # en C faire free(t) ici 

def row_ok(t,row):  
    for col in range(4):
        for i in range(row):
            if t[i][col] == t[row][col]: return False
    return True
#main 

t = [[0, 0, 0, 0],[0, 0, 0, 0],[0, 0, 0, 0],[0, 0, 0, 0]]
fill_row(t,0)
print("COUNT",G.count)
