class LispValidator:

    def __init__(self, code: str) -> None:
        self.code = code

    def is_valid(self) -> bool:
        if self.check(self.code):
            return True
        return False

    def check(self, code: str) -> bool:
        bracket = 0
        for char in code:
            if char == '(':
                bracket += 1
            elif char == ')':
                bracket -= 1
        return True if bracket == 0 else False
