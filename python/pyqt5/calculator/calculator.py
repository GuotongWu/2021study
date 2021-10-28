import sys
from PyQt5.QtWidgets import QApplication, QMainWindow
from random import randint
import time

from Ui_calculator import *

class MyMainWindow(QMainWindow, Ui_Calculator):
    def __init__(self, parent=None):
        super().__init__(parent)
        self.setupUi(self)
        self.lcdNumber.setDigitCount(10)

        listDispNum = ['0']
        lastOperator = [' ']
        lastNumber = [0]

        self.keyButtom_0.clicked.connect(lambda: self.showNumber(listDispNum))
        self.keyButtom_1.clicked.connect(lambda: self.showNumber(listDispNum))
        self.keyButtom_2.clicked.connect(lambda: self.showNumber(listDispNum))
        self.keyButtom_3.clicked.connect(lambda: self.showNumber(listDispNum))
        self.keyButtom_4.clicked.connect(lambda: self.showNumber(listDispNum))
        self.keyButtom_5.clicked.connect(lambda: self.showNumber(listDispNum))
        self.keyButtom_6.clicked.connect(lambda: self.showNumber(listDispNum))
        self.keyButtom_7.clicked.connect(lambda: self.showNumber(listDispNum))
        self.keyButtom_8.clicked.connect(lambda: self.showNumber(listDispNum))
        self.keyButtom_9.clicked.connect(lambda: self.showNumber(listDispNum))
        self.keyButtom_dot.clicked.connect(lambda: self.showNumber(listDispNum))

        self.keyButtom_clear.clicked.connect(lambda: self.clearNumber(listDispNum))

        self.key_add.clicked.connect(lambda: self.operatorNumber(listDispNum, lastOperator, lastNumber))
        self.keyButtom_sub.clicked.connect(lambda: self.operatorNumber(listDispNum, lastOperator, lastNumber))
        self.keyButtom_mul.clicked.connect(lambda: self.operatorNumber(listDispNum, lastOperator, lastNumber))
        self.keyButtom_div.clicked.connect(lambda: self.operatorNumber(listDispNum, lastOperator, lastNumber))

        self.keyButton_equal.clicked.connect(lambda: self.equlNumber(listDispNum, lastOperator, lastNumber))
        
    def operatorNumber(self, listDispNum, lastOperator, lastNumber):

        if listDispNum != []:
            lastNumber[0] = eval(''.join(listDispNum))

        sender = self.sender()

        if sender.text() == '*':
            lastOperator[0] = '*'
        elif sender.text() == '+':
            lastOperator[0] = '+'
        elif sender.text() == '/':
            lastOperator[0] = '/'
        elif sender.text() == '-':
            lastOperator[0] = '-'

        listDispNum.clear()
        listDispNum.append('0')
        self.lcdNumber.display(0)

    def equlNumber(self, listDispNum, lastOperator, lastNumber):
        secondNumber = eval(''.join(listDispNum))
        listDispNum.clear()
        dispNum = 0
        
        if lastOperator[0] == '+':
            dispNum = lastNumber[0] + secondNumber
        elif lastOperator[0] == '-':
            dispNum = lastNumber[0] - secondNumber
        elif lastOperator[0] == '*':
            dispNum = lastNumber[0] * secondNumber
        elif lastOperator[0] == '/':
            dispNum = lastNumber[0] / secondNumber

        # for n in str(dispNum):
        #     listDispNum.append(n)

        lastNumber[0] = dispNum
        self.lcdNumber.display(dispNum)


    def clearNumber(self, listDispNum):
        listDispNum.clear()
        listDispNum.append('0')
        self.lcdNumber.display('0')
        
    
    def showNumber(self, listDispNum):
        sender = self.sender()
        dispNum = ''.join(listDispNum)

        if dispNum == '0' and sender.text() != '.':
            dispNum = sender.text()
            listDispNum[0] = sender.text()
        else:
            dispNum = dispNum + sender.text()
            listDispNum.append(sender.text())
        
        self.lcdNumber.display(dispNum)
        print(eval(dispNum))
        


if __name__ == '__main__':      
    # pyqt对高分辨率屏幕调整
    QtCore.QCoreApplication.setAttribute(QtCore.Qt.AA_EnableHighDpiScaling)
    
    app = QApplication(sys.argv)
    myWin = MyMainWindow()
    myWin.show()
    sys.exit(app.exec_())