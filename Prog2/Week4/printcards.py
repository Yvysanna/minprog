# printcards.py
# Simple test of the Card ADT

from card import Card

def printAll():
    for suit in 'cdhs':
        for rank in range(1,14):
            card = Card(rank, suit)
            print('Rank: ' , card.rank())
            print('Suit: ' , card.suit())
            print(card)

if __name__ == '__main__':
     printAll()
