#include "ico-converter.h"
#include <QLabel>
#include <QGridLayout>
#include <QRadioButton>
#include <QCheckBox>
#include <QGroupBox>
#include <QPushButton>
#include <QPixmap>


ICO_Converter :: ICO_Converter(QWidget *parent) : QWidget(parent)
{
	/* set image preview */
	QGroupBox *canvas = new QGroupBox("Preview", this);
	QGridLayout *canvas_grid = new QGridLayout;

	QLabel *canvas_frame = new QLabel("", this);
	QLabel *canvas_trans = new QLabel("", this);

	/* transparent background */
	QPixmap *transparent = new QPixmap("src/trans.png");
	QPixmap trans(transparent->scaled(200,200,Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
	canvas_trans->setPixmap(trans);

	/* actual image preview */
	QPixmap *img = new QPixmap("sample2.png");
	QPixmap canvas_img(img->scaled(200,200,Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
	canvas_frame->setPixmap(canvas_img);

	canvas_grid->addWidget(canvas_trans,0,0,1,1);
	canvas_grid->addWidget(canvas_frame,0,0,1,1);
	canvas->setLayout(canvas_grid);
	

	/* crop group initialization */
	QGroupBox *crop_group = new QGroupBox("Crop", this);
	QGridLayout *crop_group_grid = new QGridLayout;

	QRadioButton *crop_btn_cover = new QRadioButton("cover");
	QRadioButton *crop_btn_contain = new QRadioButton("contain");

	crop_btn_cover->setChecked(true);

	crop_group_grid->addWidget(crop_btn_cover, 0,0,1,1);
	crop_group_grid->addWidget(crop_btn_contain, 0,1,1,1);
	crop_group->setLayout(crop_group_grid);


	/* size group initialization */
	QGroupBox *size_group = new QGroupBox("Size", this);
	QGridLayout *size_group_grid = new QGridLayout;

	QCheckBox *size_x16 = new QCheckBox("x16");
	QCheckBox *size_x32 = new QCheckBox("x32");
	QCheckBox *size_x48 = new QCheckBox("x48");
	QCheckBox *size_x64 = new QCheckBox("x64");
	QCheckBox *size_x128 = new QCheckBox("x128");
	QCheckBox *size_x256 = new QCheckBox("x256");
	size_group_grid->addWidget(size_x16,0,0,1,1);

	size_group_grid->addWidget(size_x32,0,1,1,1);
	size_group_grid->addWidget(size_x48,0,2,1,1);
	size_group_grid->addWidget(size_x64,1,0,1,1);
	size_group_grid->addWidget(size_x128,1,1,1,1);
	size_group_grid->addWidget(size_x256,1,2,1,1);
	size_group->setLayout(size_group_grid);


	/* add Buttons */
	QGroupBox *btn_group = new QGroupBox(this);
	QGridLayout *btn_group_grid = new QGridLayout;

	QPushButton *load_btn = new QPushButton("Load", this);
	QPushButton *save_btn = new QPushButton("Save", this);

	btn_group_grid->addWidget(load_btn,0,0,1,1);
	btn_group_grid->addWidget(save_btn,0,1,1,1);
	btn_group->setLayout(btn_group_grid);
	// btn_group->setStyleSheet("QGroupBox{border: 0;}");


	/* signature */
	QLabel *signature = new QLabel("Developed by @ChiantiBlaze", this);
	signature->setAlignment(Qt::AlignRight);
	signature->setStyleSheet("QLabel{font-size:12px;}");


	/* add components on the grid */
	QGridLayout *grid = new QGridLayout(this);

	grid->addWidget(canvas,0,0,3,1);
	grid->addWidget(crop_group,0,1,1,1);
	grid->addWidget(size_group,1,1,1,1);
	grid->addWidget(btn_group,2,1,1,1);
	grid->addWidget(signature,3,0,1,2);

	setLayout(grid);
}