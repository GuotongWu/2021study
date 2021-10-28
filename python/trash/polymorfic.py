class User():
    def __init__(self, name):
        self.name = name

    def printUser(self):
        print('Hello! My name is ' + self.name)

class Uclass(User):

    def __init__(self, name, classname):
        super().__init__(name) # super() 函数是用于调用父类(超类)的一个方法
        self.classname = classname

    def printUser(self):
        print('Hello! My name is ' + self.name + '\nMy class is ' + self.classname)


if __name__ == '__main__':
    a = User('Jack')
    a.printUser()
    print('-'*20)
    b = Uclass('Jack','E2004')
    b.printUser()

    print(dir(a)) #打印所有属性
    print(dir(b))