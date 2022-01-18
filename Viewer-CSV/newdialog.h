#ifndef NEWDIALOG_H
#define NEWDIALOG_H

#include <QDialog>

namespace Ui {
class NewDialog;
}

class NewDialog : public QDialog
{
    Q_OBJECT

public:
    explicit NewDialog(QWidget *parent = nullptr);
    ~NewDialog();
    int getRowCount() const; //Das wurde eingefügt
    int getColCount() const; //Das wurde eingefügt

private slots: //Das wurde eingefügt
    void on_buttonBox_accepted();
    void on_buttonBox_rejected();

private:
    Ui::NewDialog *ui;
};

#endif // NEWDIALOG_H
