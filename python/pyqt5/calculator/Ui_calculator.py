# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'd:\Github\2021study\pyqt5\calculator\calculator.ui'
#
# Created by: PyQt5 UI code generator 5.15.2
#
# WARNING: Any manual changes made to this file will be lost when pyuic5 is
# run again.  Do not edit this file unless you know what you are doing.


from PyQt5 import QtCore, QtGui, QtWidgets


class Ui_Calculator(object):
    def setupUi(self, Calculator):
        Calculator.setObjectName("Calculator")
        Calculator.resize(800, 600)
        Calculator.setMinimumSize(QtCore.QSize(441, 121))
        self.centralwidget = QtWidgets.QWidget(Calculator)
        self.centralwidget.setObjectName("centralwidget")
        self.horizontalLayout_6 = QtWidgets.QHBoxLayout(self.centralwidget)
        self.horizontalLayout_6.setObjectName("horizontalLayout_6")
        self.verticalLayout = QtWidgets.QVBoxLayout()
        self.verticalLayout.setObjectName("verticalLayout")
        self.lcdNumber = QtWidgets.QLCDNumber(self.centralwidget)
        self.lcdNumber.setMinimumSize(QtCore.QSize(500, 101))
        self.lcdNumber.setObjectName("lcdNumber")
        self.verticalLayout.addWidget(self.lcdNumber)
        self.horizontalLayout_5 = QtWidgets.QHBoxLayout()
        self.horizontalLayout_5.setObjectName("horizontalLayout_5")
        self.keyButtom_clear = QtWidgets.QPushButton(self.centralwidget)
        self.keyButtom_clear.setObjectName("keyButtom_clear")
        self.horizontalLayout_5.addWidget(self.keyButtom_clear)
        self.keyButton_equal = QtWidgets.QPushButton(self.centralwidget)
        self.keyButton_equal.setObjectName("keyButton_equal")
        self.horizontalLayout_5.addWidget(self.keyButton_equal)
        self.verticalLayout.addLayout(self.horizontalLayout_5)
        self.horizontalLayout_4 = QtWidgets.QHBoxLayout()
        self.horizontalLayout_4.setObjectName("horizontalLayout_4")
        self.keyButtom_7 = QtWidgets.QPushButton(self.centralwidget)
        self.keyButtom_7.setObjectName("keyButtom_7")
        self.horizontalLayout_4.addWidget(self.keyButtom_7)
        self.keyButtom_8 = QtWidgets.QPushButton(self.centralwidget)
        self.keyButtom_8.setObjectName("keyButtom_8")
        self.horizontalLayout_4.addWidget(self.keyButtom_8)
        self.keyButtom_9 = QtWidgets.QPushButton(self.centralwidget)
        self.keyButtom_9.setObjectName("keyButtom_9")
        self.horizontalLayout_4.addWidget(self.keyButtom_9)
        self.keyButtom_div = QtWidgets.QPushButton(self.centralwidget)
        self.keyButtom_div.setObjectName("keyButtom_div")
        self.horizontalLayout_4.addWidget(self.keyButtom_div)
        self.verticalLayout.addLayout(self.horizontalLayout_4)
        self.horizontalLayout_3 = QtWidgets.QHBoxLayout()
        self.horizontalLayout_3.setObjectName("horizontalLayout_3")
        self.keyButtom_4 = QtWidgets.QPushButton(self.centralwidget)
        self.keyButtom_4.setObjectName("keyButtom_4")
        self.horizontalLayout_3.addWidget(self.keyButtom_4)
        self.keyButtom_5 = QtWidgets.QPushButton(self.centralwidget)
        self.keyButtom_5.setObjectName("keyButtom_5")
        self.horizontalLayout_3.addWidget(self.keyButtom_5)
        self.keyButtom_6 = QtWidgets.QPushButton(self.centralwidget)
        self.keyButtom_6.setObjectName("keyButtom_6")
        self.horizontalLayout_3.addWidget(self.keyButtom_6)
        self.keyButtom_mul = QtWidgets.QPushButton(self.centralwidget)
        self.keyButtom_mul.setObjectName("keyButtom_mul")
        self.horizontalLayout_3.addWidget(self.keyButtom_mul)
        self.verticalLayout.addLayout(self.horizontalLayout_3)
        self.horizontalLayout_2 = QtWidgets.QHBoxLayout()
        self.horizontalLayout_2.setObjectName("horizontalLayout_2")
        self.keyButtom_1 = QtWidgets.QPushButton(self.centralwidget)
        self.keyButtom_1.setObjectName("keyButtom_1")
        self.horizontalLayout_2.addWidget(self.keyButtom_1)
        self.keyButtom_2 = QtWidgets.QPushButton(self.centralwidget)
        self.keyButtom_2.setObjectName("keyButtom_2")
        self.horizontalLayout_2.addWidget(self.keyButtom_2)
        self.keyButtom_3 = QtWidgets.QPushButton(self.centralwidget)
        self.keyButtom_3.setObjectName("keyButtom_3")
        self.horizontalLayout_2.addWidget(self.keyButtom_3)
        self.keyButtom_sub = QtWidgets.QPushButton(self.centralwidget)
        self.keyButtom_sub.setObjectName("keyButtom_sub")
        self.horizontalLayout_2.addWidget(self.keyButtom_sub)
        self.verticalLayout.addLayout(self.horizontalLayout_2)
        self.horizontalLayout = QtWidgets.QHBoxLayout()
        self.horizontalLayout.setObjectName("horizontalLayout")
        self.keyButtom_0 = QtWidgets.QPushButton(self.centralwidget)
        self.keyButtom_0.setObjectName("keyButtom_0")
        self.horizontalLayout.addWidget(self.keyButtom_0)
        self.keyButtom_dot = QtWidgets.QPushButton(self.centralwidget)
        self.keyButtom_dot.setObjectName("keyButtom_dot")
        self.horizontalLayout.addWidget(self.keyButtom_dot)
        self.key_add = QtWidgets.QPushButton(self.centralwidget)
        self.key_add.setObjectName("key_add")
        self.horizontalLayout.addWidget(self.key_add)
        self.verticalLayout.addLayout(self.horizontalLayout)
        self.horizontalLayout_6.addLayout(self.verticalLayout)
        Calculator.setCentralWidget(self.centralwidget)
        self.menubar = QtWidgets.QMenuBar(Calculator)
        self.menubar.setGeometry(QtCore.QRect(0, 0, 800, 22))
        self.menubar.setObjectName("menubar")
        Calculator.setMenuBar(self.menubar)
        self.statusbar = QtWidgets.QStatusBar(Calculator)
        self.statusbar.setObjectName("statusbar")
        Calculator.setStatusBar(self.statusbar)

        self.retranslateUi(Calculator)
        # self.keyButtom_0.clicked.connect(self.lcdNumber.show)
        # self.keyButtom_0.clicked.connect(self.showNumber)
        QtCore.QMetaObject.connectSlotsByName(Calculator)

    def retranslateUi(self, Calculator):
        _translate = QtCore.QCoreApplication.translate
        Calculator.setWindowTitle(_translate("Calculator", "MainWindow"))
        self.keyButtom_clear.setText(_translate("Calculator", "Clear"))
        self.keyButton_equal.setText(_translate("Calculator", "="))
        self.keyButtom_7.setText(_translate("Calculator", "7"))
        self.keyButtom_8.setText(_translate("Calculator", "8"))
        self.keyButtom_9.setText(_translate("Calculator", "9"))
        self.keyButtom_div.setText(_translate("Calculator", "/"))
        self.keyButtom_4.setText(_translate("Calculator", "4"))
        self.keyButtom_5.setText(_translate("Calculator", "5"))
        self.keyButtom_6.setText(_translate("Calculator", "6"))
        self.keyButtom_mul.setText(_translate("Calculator", "*"))
        self.keyButtom_1.setText(_translate("Calculator", "1"))
        self.keyButtom_2.setText(_translate("Calculator", "2"))
        self.keyButtom_3.setText(_translate("Calculator", "3"))
        self.keyButtom_sub.setText(_translate("Calculator", "-"))
        self.keyButtom_0.setText(_translate("Calculator", "0"))
        self.keyButtom_dot.setText(_translate("Calculator", "."))
        self.key_add.setText(_translate("Calculator", "+"))
