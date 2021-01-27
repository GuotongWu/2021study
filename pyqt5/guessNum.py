import sys
from PyQt5.QtWidgets import QApplication, QMainWindow
from random import randint
import time

from Ui_guessNum import *

class MyMainWindow(QMainWindow, Ui_guessNum):
    def __init__(self, parent=None):
        super().__init__(parent)
        self.setupUi(self)

        self.num = randint(1, 100)

    def updateText(self):
        self.textBrowser.append('开始...\n生成数字')
        time.sleep(1) #暂停1s
        self.textBrowser.clear()
        self.textBrowser.append('请输入数字')

    def inputNum(self):
        textNum = eval(self.lineEdit.text())
        if textNum > self.num:
            self.textBrowser.clear()
            self.textBrowser.append('太大了，小一点呢？')
        elif textNum < self.num:
            self.textBrowser.clear()
            self.textBrowser.append('太小了，大一点呢？')
        else:
            self.textBrowser.clear()
            self.textBrowser.append('恭喜你！！！\n正确数字是' + str(self.num))




if __name__ == '__main__':      
    # pyqt对高分辨率屏幕调整
    QtCore.QCoreApplication.setAttribute(QtCore.Qt.AA_EnableHighDpiScaling)
    
    app = QApplication(sys.argv)
    myWin = MyMainWindow()
    myWin.show()
    sys.exit(app.exec_())

    # MainWindow = QMainWindow()
    # ui = Ui_hello.Ui_MainWindow()
    # ui.setupUi(MainWindow)
    # MainWindow.show()
    # sys.exit(app.exec_())