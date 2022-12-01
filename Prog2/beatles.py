class Beatles:

    # Initializing function to assign values to object
    def __init__(self, name, born):
        self.name = name
        self.born = born
        self._instruments = []

    def _can_be_added(self, object: str, list_objects: list[str]) -> bool:
        """Checks if an object can be added - to avoid duplicates"""

        if object not in list_objects:
            return True

        return False

    def add_instrument(self, instrument: str) -> True:
        """Adds given instrument into instrument list"""

        # Checks through other function if object not already in list
        if self._can_be_added(instrument, self._instruments):
            self._instruments.append(instrument)

        return True

    def add_several_instruments(self, instruments_to_add: list[str]) -> True:
        """Adds several instruments into instrument list"""

        # Check if given instrument not already in list
        for instrument in instruments_to_add:
            if self._can_be_added(instrument, self._instruments):

                # Add to list
                self._instruments.append(instrument)

        return True


    def __str__(self) -> str:
        """For printing"""

        return f'Beatle: {self.name}\nborn in: {self.born} \nplayed: {"".join(self._instruments)}'
