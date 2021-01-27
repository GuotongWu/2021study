import sys
from PyQt5.QtWidgets import QApplication, QMainWindow
from Ui_MainWinSignal import *

class MyMainWindow(QMainWindow, Ui_Form):
    def __init__(self, parent=None):
        super().__init__(parent)
        self.setupUi(self)

if __name__ == '__main__':
    # pyqt对高分辨率屏幕调整
    QtCore.QCoreApplication.setAttribute(QtCore.Qt.AA_EnableHighDpiScaling)
    
    app = QApplication(sys.argv)
    myWin = MyMainWindow()
    myWin.show()
    sys.exit(app.exec_())