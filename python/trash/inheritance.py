class Animal():

    def __init__(self, name, age):
        self.age = age
        self.name = name

    def aprint(self):
        print(self.name + ' with age: ' + str(self.age))

    def say(self, number):
        print('Hello! ' + str(number))


class Dog(Animal):

    def aprint(self): # 重写父类的方法
        print(self.name + ' is a dog.')
        print(self.name + ' with age: ' + str(self.age))

animl = Animal('Jason', 18)
animl.aprint()

d = Dog('Jeff', 3)
d.aprint()
d.say(5) # 调用父类的方法

    