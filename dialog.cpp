#include "dialog.h"
#include "ui_dialog.h"


Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);


listviewD = new QDialog(this);
tableviewD = new QDialog(this);
treeviewD = new QDialog(this);
listview = new QListView(listviewD);        // deklaracija objekata
tableview = new QTableView(tableviewD);
treeview = new QTreeView(treeviewD);

//List View Dialog
listviewD->setGeometry(1148,143,370,230);
listview->setGeometry(10,35,350,140);
listviewD->setWindowTitle("ListView Dialog");
listviewLabel = new QLabel(listviewD);
listviewLabel->setText("ListView");
listviewLabel->setGeometry(10,5,130,30);

//Table View Dialog
tableviewD->setGeometry(1148,667,370,230);
tableview->setGeometry(10,35,350,140);
tableviewD->setWindowTitle("TableView Dialog");
tableviewLabel = new QLabel(tableviewD);
tableviewLabel->setText("TableView");
tableviewLabel->setGeometry(10,5,130,30);

//Tree View Dialog
treeviewD->setGeometry(1148,405,370,230);
treeview->setGeometry(10,35,350,140);
treeviewD->setWindowTitle("TreeView Dialog");
treeviewLabel = new QLabel(treeviewD);
treeviewLabel->setText("TreeView");
treeviewLabel->setGeometry(10,5,130,30);








//Button za List View
add = new QPushButton(listviewD);
remove = new QPushButton(listviewD);
add->setText("add");
remove->setText("remove");
add->setGeometry(70,190,75,30);
remove->setGeometry(230,190,75,30);

//Button za Table View
add1 = new QPushButton(tableviewD);
remove1 = new QPushButton(tableviewD);
add1->setText("add");
remove1->setText("remove");
add1->setGeometry(70,190,75,30);
remove1->setGeometry(230,190,75,30);

//Button za Tree View
add2 = new QPushButton(treeviewD);
remove2 = new QPushButton(treeviewD);
add2->setText("add");
remove2->setText("remove");
add2->setGeometry(70,190,75,30);
remove2->setGeometry(230,190,75,30);

remove->setObjectName("remove");
remove1->setObjectName("remove1");
remove2->setObjectName("remove2");

      //String Lista
      stringlist.append("Emsar Omic");
      stringlist.append("Sandra Glamocak");
      stringlist.append("Ajla Halilovic");
      stringlist.append("Vedran Savic");
      stringlist.append("Sejla Sakovic");
      stringlist.append("Kanita Karic");
      stringlist.append("Ajdin Mesic");
      stringlist.append("Faris Kadic");
      stringlist.append("Amar Zukic");
      stringlist.append("Adnan Strasevic");
      stringlist.append("Eldin Avdihodzic");
      stringmodel.setStringList(stringlist); //Dodavanje string liste u string model
      listview->setModel(&stringmodel);
      tableview->setModel(&stringmodel);
      treeview->setModel(&stringmodel);
      //dodavanje string modela i model views


    //Signali i slotovi za buttone tokom otvaranje novih dialoga
    connect(ui->ListView_B,QPushButton::clicked,this,&Dialog::btnclicked);
    connect(ui->TableView_B,QPushButton::clicked,this,&Dialog::btnclicked);
    connect(ui->TreeView_B,QPushButton::clicked,this,&Dialog::btnclicked);
    //Signali i slotovi za add and remove buttone na ListView
    QObject::connect(add, SIGNAL(clicked()),this, SLOT(addclicked()));
    QObject::connect(remove, SIGNAL(clicked()),this, SLOT(removeclicked()));
    //Signali i slotovi za add and remove buttone na table view
    QObject::connect(add1, SIGNAL(clicked()),this, SLOT(addclicked()));
    QObject::connect(remove1, SIGNAL(clicked()),this, SLOT(removeclicked()));
    //signali i slotovi za add and remove buttone na tree view
    QObject::connect(add2, SIGNAL(clicked()),this, SLOT(addclicked()));
    QObject::connect(remove2, SIGNAL(clicked()),this, SLOT(removeclicked()));



}
//destruktor
Dialog::~Dialog()
{
    delete ui;
}
//add button
void Dialog::addclicked() {

    bool ok;
        QString temp = QInputDialog::getText(this,"Unos","Unesite studenta:",QLineEdit::Normal,QString(),&ok);


        if (ok) {
            if(temp.isEmpty()) return;
            if(stringmodel.insertRow(stringmodel.rowCount())){
                 QModelIndex index=stringmodel.index((stringmodel.rowCount()-1),0);
                 stringmodel.setData(index,temp);
                 listview->setModel(&stringmodel);
                 tableview->setModel(&stringmodel);
                 treeview->setModel(&stringmodel);

               }
            }

}


void Dialog::removeclicked() {

     QPushButton *btn = qobject_cast<QPushButton*>(sender());
if (btn->objectName()=="remove") {

    QModelIndex index= listview->currentIndex();
    stringmodel.removeRow(index.row());
    }

if (btn->objectName()=="remove1") {

    QModelIndex index= tableview->currentIndex();
    stringmodel.removeRow(index.row());
    }

if (btn->objectName()=="remove2") {

    QModelIndex index= treeview->currentIndex();
    stringmodel.removeRow(index.row());
    }


}





void Dialog::btnclicked () {

    QPushButton *btn = qobject_cast<QPushButton*>(sender());

if(btn->text()=="ListView") {

   listviewD->setVisible(true);

}

if(btn->text()=="TableView") {
    tableviewD->setVisible(true);

}

if(btn->text()=="TreeView") {
treeviewD->setVisible(true);

}
}


