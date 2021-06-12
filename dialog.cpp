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

listviewD->setGeometry(1148,143,370,230);
listview->setGeometry(10,35,350,140);
listviewD->setWindowTitle("ListView Dialog");
tableviewD->setGeometry(1148,667,370,230);
tableview->setGeometry(10,35,350,140);
tableviewD->setWindowTitle("TableView Dialog");                                                           // dimenzije prozora
treeviewD->setGeometry(1148,405,370,230);
treeview->setGeometry(10,35,350,140);
treeviewD->setWindowTitle("TreeView Dialog");

listviewLabel = new QLabel(listviewD);
listviewLabel->setText("ListView");
listviewLabel->setStyleSheet("font-size: 20px; font-weight: bold; color: black");
listviewLabel->setGeometry(10,5,130,30);


tableviewLabel = new QLabel(tableviewD);
tableviewLabel->setText("TableView");
tableviewLabel->setStyleSheet("font-size: 20px; font-weight: bold; color: black");       // natipisi u dialozima
tableviewLabel->setGeometry(10,5,130,30);

treeviewLabel = new QLabel(treeviewD);
treeviewLabel->setText("TreeView");
treeviewLabel->setStyleSheet("font-size: 20px; font-weight: bold; color: black");
treeviewLabel->setGeometry(10,5,130,30);




add = new QPushButton(listviewD);
remove = new QPushButton(listviewD);
add->setText("add");
remove->setText("remove");
add->setGeometry(70,190,75,30);
remove->setGeometry(230,190,75,30);

add1 = new QPushButton(tableviewD);
remove1 = new QPushButton(tableviewD);
add1->setText("add");
remove1->setText("remove");
add1->setGeometry(70,190,75,30);
remove1->setGeometry(230,190,75,30);

add2 = new QPushButton(treeviewD);
remove2 = new QPushButton(treeviewD);
add2->setText("add");
remove2->setText("remove");
add2->setGeometry(70,190,75,30);
remove2->setGeometry(230,190,75,30);

remove->setObjectName("remove");
remove1->setObjectName("remove1");
remove2->setObjectName("remove2");


      stringlist.append("Djordje Djuric");
      stringlist.append("Berina Mrkonjic");
      stringlist.append("Semir Celikovic");
      stringlist.append("Dino Mocic");
      stringlist.append("Mirza Dizdarevic");
      stringlist.append("Dzeneta Gutic");
      stringlist.append("Silvio Marjanovic");
      stringlist.append("Ajla Halilovic");
      stringlist.append("Tarik Jasarevic");
      stringlist.append("Nermina Zukic");
      stringlist.append("Eldin Osmanovic");
      stringmodel.setStringList(stringlist);
      listview->setModel(&stringmodel);
      tableview->setModel(&stringmodel);
      treeview->setModel(&stringmodel);




    connect(ui->ListView_B,QPushButton::clicked,this,&Dialog::btnclicked);
    connect(ui->TableView_B,QPushButton::clicked,this,&Dialog::btnclicked);
    connect(ui->TreeView_B,QPushButton::clicked,this,&Dialog::btnclicked);
    QObject::connect(add, SIGNAL(clicked()),this, SLOT(addclicked()));
    QObject::connect(remove, SIGNAL(clicked()),this, SLOT(removeclicked()));
    QObject::connect(add1, SIGNAL(clicked()),this, SLOT(addclicked()));
    QObject::connect(remove1, SIGNAL(clicked()),this, SLOT(removeclicked()));
    QObject::connect(add2, SIGNAL(clicked()),this, SLOT(addclicked()));
    QObject::connect(remove2, SIGNAL(clicked()),this, SLOT(removeclicked()));



}
Dialog::~Dialog()
{
    delete ui;
}

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


