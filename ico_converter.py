from PyQt5.QtWidgets import QWidget, QGridLayout, QGroupBox, \
							QLabel, QPushButton, QRadioButton, QCheckBox
from PyQt5.QtGui import QPixmap	
class ICOConverter(QWidget):
	def __init__(self):
		super().__init__()
		self.initUI()

	def initUI(self):

		grid = QGridLayout()
		grid.addWidget(self.create_preview_box(), 0,0, 3,1)
		grid.addWidget(self.create_crop_box(), 0,1, 1,1)
		grid.addWidget(self.create_size_box(), 1,1, 1,1)
		grid.addWidget(self.create_btn_box(), 2,1, 1,1)
		self.setLayout(grid)

		self.setWindowTitle('ICO Converter v1.0')
		self.show()


	def create_preview_box(self):
		preview_box = QGroupBox("Preview: ")
		trans_background = QLabel()
		trans_background.setPixmap(QPixmap('./src/trans.png'))
		trans_background.setFixedSize(200,200)

		layout = QGridLayout()
		layout.addWidget(trans_background,0,0,1,1)
		preview_box.setLayout(layout)

		return preview_box


	def create_crop_box(self):
		crop_box = QGroupBox("Crop:")
		crop_cover = QRadioButton("cover")
		crop_contain = QRadioButton("contain")
		crop_cover.setChecked(True)

		layout = QGridLayout()
		layout.addWidget(crop_cover,0,0,0,1)
		layout.addWidget(crop_contain,0,1,0,1)
		crop_box.setLayout(layout)

		return crop_box


	def create_size_box(self):
		size_box = QGroupBox("Size: ")
		size_x16 = QCheckBox("x16")
		size_x32 = QCheckBox("x32")
		size_x48 = QCheckBox("x48")
		size_x64 = QCheckBox("x64")
		size_x128 = QCheckBox("x128")
		size_x256 = QCheckBox("x256")

		layout = QGridLayout()
		layout.addWidget(size_x16, 0,0,1,1)
		layout.addWidget(size_x32, 0,1,1,1)
		layout.addWidget(size_x48, 0,2,1,1)
		layout.addWidget(size_x64, 1,0,1,1)
		layout.addWidget(size_x128, 1,1,1,1)
		layout.addWidget(size_x256, 1,2,1,1)
		size_box.setLayout(layout)

		return size_box


	def create_btn_box(self):
		btn_box = QGroupBox()
		btn_load = QPushButton("Load")
		btn_save = QPushButton("Save")

		layout = QGridLayout()
		layout.addWidget(btn_load, 0,0, 1,1)
		layout.addWidget(btn_save, 0,1, 1,1)
		btn_box.setLayout(layout)

		return btn_box