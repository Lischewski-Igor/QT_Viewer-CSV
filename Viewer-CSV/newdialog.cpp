#include "newdialog.h"
#include "ui_newdialog.h"

NewDialog::NewDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewDialog)
{
    ui->setupUi(this);
    setWindowTitle("New"); //Das wurde eingeführt
}

NewDialog::~NewDialog()
{
    delete ui;
}

int NewDialog::getRowCount() const
{
    return ui->rowCountSpinBox->value();
}

int NewDialog::getColCount() const
{
    return ui->colCountSpinBox->value();
}

void NewDialog::on_buttonBox_accepted()
{
    accept();
}

void NewDialog::on_buttonBox_rejected()
{
    reject();
}

