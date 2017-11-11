# main.py
#
# developed by Chianti Blaze
# 11 Nov 17


def main():
	import sys
	from PyQt5.QtWidgets import QApplication
	from ico_converter import ICOConverter

	app = QApplication(sys.argv)
	ico_converter = ICOConverter()
	sys.exit(app.exec_())



if __name__ == "__main__":
	main()