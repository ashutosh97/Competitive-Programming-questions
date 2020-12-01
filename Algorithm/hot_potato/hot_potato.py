def init_game(players, N):
    for player_idx in range(0, N):
        players[player_idx] = 'Alive'

def get_next_idx(index, N, I, players):
    sum = 0
    index = index+1
    while True:
        if index >= N:
            index = index-N
        if players[index] == 'Alive':
            sum += 1
        if sum == I:
            return index
        index += 1

def get_good_idx(players):
    for i, pl in enumerate(players):
        if pl == 'Alive':
            return i+1

def has_to_stop(players):
    stop = False
    alives = 0
    for pl in players:
        if pl == 'Alive':
            alives += 1
    if alives == 1:
        stop = True
    return stop

def hot_potato(N, I, players):
    idx = I-1
    loop = 1
    while True:
        if loop == 1:
            players[idx] = 'Dead'
            loop += 1
            continue

        idx = get_next_idx(idx, N, I, players)
        players[idx] = 'Dead'

        if has_to_stop(players):
            return

N = 2
I = 3
assert I <= N

players = list(range(N))

init_game(players, N)
print(f'Players: {players}\n')

hot_potato(N, I, players)
print(f'Alive Player: {players}\n')

goodIdx = get_good_idx(players)
print(f'Position to win: {goodIdx}')
