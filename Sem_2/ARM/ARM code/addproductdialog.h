#ifndef ADDPRODUCTDIALOG_H
#define ADDPRODUCTDIALOG_H

#include <QDialog>
#include <QStandardItemModel>

QT_BEGIN_NAMESPACE
class QLineEdit;
QT_END_NAMESPACE

class AddProductDialog : public QDialog {
    Q_OBJECT

public:
    AddProductDialog(QStandardItemModel *model, QWidget *parent = nullptr);

private slots:
    void onAddButtonClicked();

private:
    QLineEdit *nameEdit;
    QLineEdit *quantityEdit;
    QStandardItemModel *model;
};

#endif // ADDPRODUCTDIALOG_H
