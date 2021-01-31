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
    
    def showNumber(self, listDispNum):
        sender = self.sender()
        dispNum = ''.join(listDispNum)

        if dispNum == '0':
            dispNum = sender.text()
            listDispNum[0] = sender.text()
        else:
            dispNum = dispNum + sender.text()
            listDispNum.append(sender.text())
        
        self.lcdNumber.display(dispNum)
        print(dispNum)
        




if __name__ == '__main__':      
    # pyqt对高分辨率屏幕调整
    QtCore.QCoreApplication.setAttribute(QtCore.Qt.AA_EnableHighDpiScaling)
    
    app = QApplication(sys.argv)
    myWin = MyMainWindow()
    myWin.show()
    sys.exit(app.exec_())