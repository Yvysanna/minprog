class Card:
    """A simple paying card. A Card is charactertized by two components.
    rank: an integer value in the range 1-13, inclusive (Ace-King)
    suit: a character in 'cdhs' for clubs, diamonds, hearts, and spades.
          """

    SUITS = 'cdhs'
    RANKS = range(1,14)

    SUIT_NAMES: list[str] = ['Clubs', 'Diamonds', 'Hearts', 'Spades']
    RANK_NAMES: list[str] = ['Ace' , 'Two' , 'Three' , 'Four' , 'Five' , 'Six' ,
                             'Seven' , 'Eight' , 'Nine' , 'Ten' , 'Jack' , 'Queen' ,
                             'King']

    def __init__(self, rank: int, suit: str) -> None:
        """Constructor
        pre: rank in range(1, 14) and suit in 'cdhs'
        post: self has the given rank and suit"""

        self.rank_num: int = rank
        self.suit_char: str = suit
        self.card_number: int = self.rank + (13 * self.SUITS[self.SUITS.index(self.suit)])

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

        return f'{self.rankName()} of {self.suitName()}'


if __name__ == "__main__":
    print(Card(0))