def is_won(board):
    """
    Controleert of het bord in een winnende configuratie staat. Geeft True als
    de configuratie winnend is, False als dat niet het geval is.
    """
    return False

def index_of(board, tile):
    for each in range(len(board)):
        for num in range(len(board[each])):
            if board[each][num] == tile:
                return each, num


def move_tile(board, tile):
    """
    Als de te verplaatsten tegel verplaatsbaar is: schuift de tegel in de
    configuratie van het bord en geeft True. Als dat niet het geval is, blijft
    het bord in de oorspronkelijke configuratie en functie geeft False.
    """

    tile_idx = index_of(board, tile)
    free_idx = index_of(board, 0)

    # If move to left or right
    if tile_idx[0] == free_idx[0]:
        if (tile_idx[1] + 1) == free_idx[1] or (tile_idx[1] - 1) == free_idx[1]:
            board[tile_idx[0]][tile_idx[1]], board[free_idx[0]][free_idx[1]] = board[free_idx[0]][free_idx[1]], board[tile_idx[0]][tile_idx[1]]
            return True
    return False


def print_board(board):
    """
    Print alle rijen van het bord onder elkaar. Het format is zoals in de
    voorbeelden onderaan de opdracht.
    """
    for i in range(len(board)):
        for j in board[i]:

            # Mooi format
            print("%2d" % j, end=' ')
        print()


def create_board():
    """
    Initialiseert en returnt een bord van formaat 4 x 4.
    Sorteert de nummers op aflopende volgorde van links boven naar rechts beneden.
    De volgorde van de tegels 1 en 2 is verwisseld.
    """
    board = []

    # Create list of lists
    for i in range(4):
        board.append([])

    board[0] = [15, 14, 13, 12]
    board[1] = [11, 10, 9, 8]
    board[2] = [7, 6, 5, 4]
    board[3] = [3, 1, 2, 0]

    return board

if __name__ == '__main__':
    print("Welkom bij de schuifpuzzel!")
    board = create_board()
    while not is_won(board):
        print_board(board)
        tile = input("Tegel die je wil schuiven: ")
        valid = move_tile(board, int(tile))
        if not valid:
            print("Deze tegel kan je niet schuiven.")
    print("Gefeliciteerd, je hebt de schuifpuzzel opgelost!")
