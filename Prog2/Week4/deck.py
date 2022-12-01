class Card:
    """A simple paying card. A Card is charactertized by two components.
    rank: an integer value in the range 1-13, inclusive (Ace-King)
    suit: a character in 'cdhs' for clubs, diamonds, hearts, and spades.
          """

    SUIT_NAMES: list[str] = ['Clubs', 'Diamonds', 'Hearts', 'Spades']
    RANK_NAMES: list[str] = ['Ace' , 'Two' , 'Three' , 'Four' , 'Five' , 'Six' ,
                             'Seven' , 'Eight' , 'Nine' , 'Ten' , 'Jack' , 'Queen' ,
                             'King']

    def __init__(self, number: int) -> None:
        """Constructor
        pre: rank in range(1, 14) and suit in 'cdhs'
        post: self has the given rank and suit"""

        self.card_number: int = number

    def suit(self) -> int:
        """Card suit
        post: Returns the suit of self as a single number"""

        return self.card_number // 13

    def rank(self) -> int:
        """Card rank
        post: Returns the rank of self as an int"""

        return self.card_number % 13

    def suitName(self) -> str:
        """Card suit name
        post: Returns one of ('Clubs', 'Diamonds', 'Hearts',
              'Spades') corresponding to self's suit."""

        return self.SUIT_NAMES[self.suit()]

    def rankName(self) -> str:
        """Card rank name
        post: Returns one of ('Ace', 'Two', 'Three', ..., 'King')
              corresponding to self's rank."""

        return self.RANK_NAMES[self.rank()]

    def __str__(self) -> str:
        """String representation
        post: Returns string representing self, e.g. 'Ace of Spades' """

        #return f'{self.rank()} of {self.suit()}'
        return f'{self.rankName()} of {self.suitName()}'




""" Schrijf een niet te ingewikkelde implementatie van een Deck 
class die random kaarten kan “delen”, zoals dat heet. 
Een instatie van Deck start met de 52 kaarten. 
Er moet een deal()-methode zijn die een random plek uit de lijst met kaarten 
kiest en deze uit de lijst popt. Maak ook een cardsLeft()-methode
die aangeeft hoeveel kaarten nog resteren. (Een meer ingewikkelde 
versie van deze class staat verderop in het boek, en ongetwijfeld online,
maar maak gewoon zelf een eenvoudige implementatie.)"""

class Deck:
    def __init__(self, card: Card) -> None:
        pass

    def deal() -> str:
        pass

    def cardsLeft() -> int:
        pass



if __name__ == "__main__":
    print(Card(0))