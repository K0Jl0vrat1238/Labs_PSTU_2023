#include "addproductdialog.h"
#include <QLineEdit>
#include <QPushButton>
#include <QFormLayout>
#include <QIntValidator>

AddProductDialog::AddProductDialog(QStandardItemModel *model, QWidget *parent) : QDialog(parent), model(model) {
    setWindowTitle(tr("Добавить товар"));

    nameEdit = new QLineEdit(this);
    quantityEdit = new QLineEdit(this);
    quantityEdit->setValidator(new QIntValidator(0, 10000, this));

    QPushButton *addButton = new QPushButton(tr("Добавить"), this);
    QPushButton *cancelButton = new QPushButton(tr("Отмена"), this);

    QFormLayout *layout = new QFormLayout(this);
    layout->addRow(tr("Название товара:"), nameEdit);
    layout->addRow(tr("Количество:"), quantityEdit);
    layout->addRow(addButton, cancelButton);

    connect(addButton, &QPushButton::clicked, this, &AddProductDialog::onAddButtonClicked);
    connect(cancelButton, &QPushButton::clicked, this, &AddProductDialog::reject);
}

void AddProductDialog::onAddButtonClicked() {
    model->appendRow({new QStandardItem(nameEdit->text()), new QStandardItem(quantityEdit->text())});
    accept();
}
