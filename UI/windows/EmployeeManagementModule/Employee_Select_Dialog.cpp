#include "../../../Include/UI/Components/Headers/ui_employee_select_dialog.h"
#include "../../../Include/UI/Components/Headers/Employee_Select_Dialog.h"
#include <QWidget>
#include <QListWidgetItem>

EmployeeSelectDialog::EmployeeSelectDialog(QWidget *parent): QDialog(parent), ui(new Ui::EmployeeSelectDialog)
{
    ui->setupUi(this); 
    //ui->employeeList->clear();
        // Connect click signal to slot
    connect(ui->employeeList, &QListWidget::itemClicked,
            this, &EmployeeSelectDialog::onEmployeeSelected);
}

void EmployeeSelectDialog::populateEmployeeList() {
   ui->employeeList->clear();

    if (!empList) return; // safety check
    for (const auto& emp : *empList) {  // notice the *empList
        ui->employeeList->addItem(QString::fromStdString(emp.fullName));
    }
}

EmployeeSelectDialog::~EmployeeSelectDialog()
{
    delete ui;
}

QString EmployeeSelectDialog::getSelectedEmployee() const
{
    return selectedEmployee;
}
void EmployeeSelectDialog::on_buttonBox_accepted()
{
     if (ui->employeeList->currentItem())
        selectedEmployee = ui->employeeList->currentItem()->text();
}

void EmployeeSelectDialog::onEmployeeSelected(QListWidgetItem* item)
{
    if (!item || !empList) return;

    // Find the employee that matches the clicked name
    QString selectedName = item->text();

    for (const auto& emp : *empList) {
        if (QString::fromStdString(emp.fullName) == selectedName) {
            selectedEmployee = selectedName;
            qDebug() << "Selected employee:" << selectedEmployee;
            break;
        }
    }
}
