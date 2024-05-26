#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "addproductdialog.h"
#include <QTableView>
#include <QPushButton>
#include <QVBoxLayout>
#include <QStandardItemModel>
#include <QRandomGenerator>
#include <QStyledItemDelegate>
#include <QPainter>

class HighlightDelegate : public QStyledItemDelegate {
public:
    HighlightDelegate(QObject *parent = nullptr) : QStyledItemDelegate(parent) {}

    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const override {
        QVariant quantity = index.model()->data(index, Qt::DisplayRole);
        if (quantity.toInt() < 10) {
            painter->fillRect(option.rect, Qt::yellow);
        }
        QStyledItemDelegate::paint(painter, option, index);
    }
};

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    model = new QStandardItemModel(this);
    ui->tableView->setModel(model);
    ui->tableView->setItemDelegate(new HighlightDelegate(this));

    QStringList productsList = {"Молоко", "Хлеб", "Яйца", "Сыр", "Йогурт", "Масло", "Мука", "Сахар", "Рис", "Макароны", "Картофель", "Овощи", "Фрукты", "Мясо", "Рыба", "Колбаса", "Консервы", "Сухофрукты", "Орехи", "Зелень"};
    for (const QString &productName : productsList) {
        QStandardItem *productItem = new QStandardItem(productName);
        QStandardItem *quantityItem = new QStandardItem(QString::number(QRandomGenerator::global()->bounded(1, 20)));
        model->appendRow({productItem, quantityItem});
    }

    connect(ui->addButton, &QPushButton::clicked, this, &MainWindow::addProduct);
}

void MainWindow::addProduct() {
    AddProductDialog *dialog = new AddProductDialog(model, this);
    dialog->exec();
}

MainWindow::~MainWindow() {
    delete ui;
}
