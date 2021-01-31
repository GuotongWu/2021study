import sys
from PyQt5.QtWidgets import QApplication, QWidget, QLabel
from PyQt5 import QtCore

class PressKey(QWidget):
    def __init__(self):
        super().__init__()
        self.initUi()

    def initUi(self):
        self.setGeometry(300, 300, 350, 250)
        # self.resize(350, 250)
        self.lab = QLabel('方向', self)
        self.lab.setGeometry(150, 100, 50, 50)


    def keyPressEvent(self, e):
        if e.key() == QtCore.Qt.Key_Up:
            self.lab.setText('↑')
        elif e.key() == QtCore.Qt.Key_Down:
            self.lab.setText('↓')
        elif e.key() == QtCore.Qt.Key_Left:
            self.lab.setText('←')
        else:
            self.lab.setText('→')




if __name__ == '__main__':

    QtCore.QCoreApplication.setAttribute(QtCore.Qt.AA_EnableHighDpiScaling)
    
    app = QApplication(sys.argv)
    myWin = PressKey()
    myWin.show()
    sys.exit(app.exec_())

    # MainWindow = QMainWindow()
    # ui = Ui_hello.Ui_MainWindow()
    # ui.setupUi(MainWindow)
    # MainWindow.show()
    # sys.exit(app.exec_())