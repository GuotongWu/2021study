# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'd:\Github\2021study\pyqt5\hello.ui'
#
# Created by: PyQt5 UI code generator 5.15.2
#
# WARNING: Any manual changes made to this file will be lost when pyuic5 is
# run again.  Do not edit this file unless you know what you are doing.


from PyQt5 import QtCore, QtGui, QtWidgets


class Ui_MainWindow(object):
    def setupUi(self, MainWindow):
        MainWindow.setObjectName("MainWindow")
        MainWindow.resize(800, 600)
        MainWindow.setCursor(QtGui.QCursor(QtCore.Qt.ArrowCursor))
        self.centralwidget = QtWidgets.QWidget(MainWindow)
        self.centralwidget.setObjectName("centralwidget")
        self.beginButton = QtWidgets.QPushButton(self.centralwidget)
        self.beginButton.setGeometry(QtCore.QRect(460, 180, 75, 23))
        font = QtGui.QFont()
        font.setFamily("微软雅黑")
        font.setPointSize(10)
        self.beginButton.setFont(font)
        self.beginButton.setObjectName("beginButton")
        self.widget = QtWidgets.QWidget(self.centralwidget)
        self.widget.setGeometry(QtCore.QRect(190, 150, 38, 68))
        self.widget.setObjectName("widget")
        self.verticalLayout = QtWidgets.QVBoxLayout(self.widget)
        self.verticalLayout.setContentsMargins(0, 0, 0, 0)
        self.verticalLayout.setObjectName("verticalLayout")
        self.label_6 = QtWidgets.QLabel(self.widget)
        self.label_6.setText("")
        self.label_6.setObjectName("label_6")
        self.verticalLayout.addWidget(self.label_6)
        self.label_3 = QtWidgets.QLabel(self.widget)
        self.label_3.setObjectName("label_3")
        self.verticalLayout.addWidget(self.label_3)
        self.label_4 = QtWidgets.QLabel(self.widget)
        self.label_4.setObjectName("label_4")
        self.verticalLayout.addWidget(self.label_4)
        self.label_5 = QtWidgets.QLabel(self.widget)
        self.label_5.setObjectName("label_5")
        self.verticalLayout.addWidget(self.label_5)
        self.widget1 = QtWidgets.QWidget(self.centralwidget)
        self.widget1.setGeometry(QtCore.QRect(270, 150, 80, 89))
        self.widget1.setObjectName("widget1")
        self.gridLayout = QtWidgets.QGridLayout(self.widget1)
        self.gridLayout.setContentsMargins(0, 0, 0, 0)
        self.gridLayout.setObjectName("gridLayout")
        self.label = QtWidgets.QLabel(self.widget1)
        self.label.setObjectName("label")
        self.gridLayout.addWidget(self.label, 0, 0, 1, 1)
        self.label_2 = QtWidgets.QLabel(self.widget1)
        self.label_2.setObjectName("label_2")
        self.gridLayout.addWidget(self.label_2, 0, 1, 1, 1)
        self.get_max = QtWidgets.QSpinBox(self.widget1)
        self.get_max.setObjectName("get_max")
        self.gridLayout.addWidget(self.get_max, 1, 0, 1, 1)
        self.get_min = QtWidgets.QSpinBox(self.widget1)
        self.get_min.setObjectName("get_min")
        self.gridLayout.addWidget(self.get_min, 1, 1, 1, 1)
        self.give_max = QtWidgets.QSpinBox(self.widget1)
        self.give_max.setObjectName("give_max")
        self.gridLayout.addWidget(self.give_max, 2, 0, 1, 1)
        self.give_min = QtWidgets.QSpinBox(self.widget1)
        self.give_min.setObjectName("give_min")
        self.gridLayout.addWidget(self.give_min, 2, 1, 1, 1)
        self.ration_max = QtWidgets.QSpinBox(self.widget1)
        self.ration_max.setObjectName("ration_max")
        self.gridLayout.addWidget(self.ration_max, 3, 0, 1, 1)
        self.ratio_min = QtWidgets.QSpinBox(self.widget1)
        self.ratio_min.setObjectName("ratio_min")
        self.gridLayout.addWidget(self.ratio_min, 3, 1, 1, 1)
        MainWindow.setCentralWidget(self.centralwidget)
        self.menubar = QtWidgets.QMenuBar(MainWindow)
        self.menubar.setGeometry(QtCore.QRect(0, 0, 800, 22))
        self.menubar.setObjectName("menubar")
        MainWindow.setMenuBar(self.menubar)
        self.statusbar = QtWidgets.QStatusBar(MainWindow)
        self.statusbar.setObjectName("statusbar")
        MainWindow.setStatusBar(self.statusbar)

        self.retranslateUi(MainWindow)
        QtCore.QMetaObject.connectSlotsByName(MainWindow)

    def retranslateUi(self, MainWindow):
        _translate = QtCore.QCoreApplication.translate
        MainWindow.setWindowTitle(_translate("MainWindow", "MainWindow"))
        self.beginButton.setText(_translate("MainWindow", "开始"))
        self.label_3.setText(_translate("MainWindow", "收入"))
        self.label_4.setText(_translate("MainWindow", "支出"))
        self.label_5.setText(_translate("MainWindow", "收支率"))
        self.label.setText(_translate("MainWindow", "最大值"))
        self.label_2.setText(_translate("MainWindow", "最小值"))
