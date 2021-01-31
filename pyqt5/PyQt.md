# PyQt

## 1. 事件和信号处理

简单的信号，槽

```python
dial.valueChanged.connect(lcd.display)
```

子类重写响应函数，键盘响应函数

```python
def keyPressEvent(self, e):
    if e.key() == Qt.Key_Up:
        self.lab.setText('↑')
    elif e.key() == Qt.Key_Down:
        self.lab.setText('↓')
    elif e.key() == Qt.Key_Left:
        self.lab.setText('←')
    else:
        self.lab.setText('→')
```

鼠标响应函数

```python
self.setMouseTracking(True) # 打开鼠标跟踪

def mouseMoveEvent(self, event):
    distance_from_center = round(((event.y() - 250)**2 + (event.x() - 500)**2)**0.5)
    self.label.setText('坐标: ( x: %d ,y: %d )' % (event.x(), event.y()) + " 离中心点距离: " + str(distance_from_center))       
    self.pos = event.pos()
    self.update()
    
def paintEvent(self, event):
    if self.pos:
        q = QPainter(self)
        q.drawLine(0, 0, self.pos.x(), self.pos.y())
        # 起始坐标->终点坐标
```

判断信号发送者

```python
sender = self.sender()

if sender.text() == '剪刀':
    player = 1
```

自定义信号

```python
class Signal(QObject):
    showmouse = pyqtSignal()

class Example(QWidget):
    def __init__(self):
        super().__init__()
        self.initUI()
    def initUI(self):
        self.setGeometry(200, 200, 300, 300)
        self.setWindowTitle('学点编程吧')
        
        self.s = Signal()
    #信号槽函数    
        self.s.showmouse.connect(self.about)
        
        self.show()
    #响应函数    
    def about(self):
        QMessageBox.about(self,'鼠标','你点鼠标了吧！')
    # 重写鼠标事件，发出信号至Signal
    def mousePressEvent(self, e):
        self.s.showmouse.emit()
```

