import random
#import pandas as pd


class Student:
    def __init__(self, name: str) -> None:
        self.name = name
        self.colleagues = set()

    def _add_colleagues(self, col_name: int) -> None:
        """Add colleage to set of student"""
        self.colleagues.add(col_name)
    
    def is_colleague(self, col_name: int) -> bool:
        """Checks if two students have already worked together"""
        if col_name in self.colleagues:
            return True 
        self._add_colleagues(col_name)
        #print(col_name)
        return False

    def __str__(self) -> str:
        return str(self.name)

    def __repr__(self) -> str:
        return str(self.name)

   

def make_student(name_list: list) -> list[str]:
    """Creates student object"""
    stud_obj :list = []
    for i in range(len(name_list)):
        stud_obj.append(Student(name_list[i]))
    
    return stud_obj


def match_students(student_a: Student, student_b: Student):
    """Matches two students"""
    if student_a.is_colleague(student_b.name):
        return False
    return True


if __name__ == '__main__':

    name_list = [
        "Katja",
      "Hector",
      "Kasandra",
      "Manuja",
      "David",
      "Coen",
      "Timon",
      "Noa",
      "Steven",
      "Finn",
      "Issa",
      "Daniel"
      ]

    students = make_student(name_list)
    choices = list(range(len(students)))
    

    while len(choices) > 0:
        max = choices
        n1, n2 = choices.pop(random.randint(0, len(choices))), choices.pop(random.randint(0, len(choices) - 1))
        s1, s2 = students[n1], students[n2]
        while match_students(s1, s2):
            #if s1.is_colleague(s2) or s1 == s2:
            choices.append(n1), choices.append(n2)
        students.append(s1), students.append(s2)
        print(len(choices))

    print([(s.name, s.colleague, "\n") for s in students])