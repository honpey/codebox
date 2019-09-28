class Student(object):
    def __init__(self, name, score):
        self.name = name
        self.__score = score
    @property
    def score(self):
        return self.__score
    @score.setter
    def score(self, score):
        if score < 0 or score > 100:
            raise ValueError("invalid score")
        self.__score = score

if __name__ == "__main__":
    print("hello world")
    xiaoming = Student("xiaoming", 93)
    print(xiaoming.score)
    xiaoming.score = 94
    print(xiaoming.score)
