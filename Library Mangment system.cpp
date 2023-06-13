#include<bits/stdc++.h>
using namespace std;

class Book_Linkedlist{
public:
    class Book{
    public:
        string book_name;
        string category;
        string author_name;
        int QR;
        Book* next;
        Book* prev;
        Book(){
            next=NULL;
            prev=NULL;
        }
    };
    Book*head=NULL;
    void Book_insert(string c,string n,string an,int Q){
        Book*newBook=new Book;
        newBook->category=c;
        newBook->book_name=n;
        newBook->author_name=an;
        newBook->QR=Q;
        if(head==NULL){
            head=newBook;
            newBook->next=NULL;
            newBook->prev=NULL;
        }else{
            Book*last=head;
            while(last->next!=NULL){
                last=last->next;
            }
            last->next=newBook;
            newBook->prev=last;
        }
    }
    void Book_insert_be(string c,string n,string an,int Q){
        Book*newBook=new Book;
        newBook->category=c;
        newBook->book_name=n;
        newBook->author_name=an;
        newBook->QR=Q;
        if(head==NULL){
            head=newBook;
            newBook->next=NULL;
        }else{
            newBook->next=head;
            head->prev=newBook;
            head=newBook;
        }
    }
    int count(){
        int cot=0;
        Book *temp=head;
        while(temp!=NULL){
            cot++;
            temp=temp->next;
        }
        return cot;
    }
    void sort_linkedlist_book(){
        Book *cur1 = head;
        Book *cur2 = head;
        for (int i = 0; i < count(); i++) {
            for (int j = 0; j < count()-1; j++) {
                if (cur1->QR < cur2->QR) {
                    int temp = cur1->QR;
                    string temp_auth=cur1->author_name;
                    string temp_bn=cur1->book_name;
                    string temp_cat=cur1->category;
                    cur1->QR = cur2->QR;
                    cur1->book_name=cur2->book_name;
                    cur1->author_name=cur2->author_name;
                    cur1->category=cur2->category;
                    cur2->QR = temp;
                    cur2->book_name=temp_bn;
                    cur2->author_name=temp_auth;
                    cur2->category=temp_cat;
                }
                cur2 = cur2->next;
            }
            cur2 = head;
            cur1 = head->next;
            for (int k = 0; k < i; k++) {
                cur1 = cur1->next;
            }
        }
    }
    bool search(string newName){
        if(head==NULL){
            cout<<"NOT FOUND ANY BOOKS\n";
            return false;
        }
        else{
            Book *temp=head;
            while (temp!=NULL && temp->book_name!=newName){
                temp=temp->next;
            }
            if(temp==NULL){
                cout<<"BOOK IS NOT AVILABILE RIGHT NOW\n";
                return false;
            }
            else{
                cout<<"BOOK IS FOUND\n";
                cout<<"Book name: "<<temp->book_name<<endl<<"Author name: "<<temp->author_name<<endl<<"Category: "<<temp->category<<
                "QR: "<<temp->QR<<endl;
                return true;
            }
        }
    }
    void Book_insert_pos(string c,string n,string an,int Q,int pos){
        Book*newBook=new Book;
        newBook->category=c;
        newBook->book_name=n;
        newBook->author_name=an;
        newBook->QR=Q;
        if(pos==0){
            newBook->next=head;
            head->prev=newBook;
            head=newBook;
            return;
        }else{
            Book*temp=head;
            for(int i=0;i<pos && temp!=NULL;i++){
                temp=temp->next;
            }
            if(temp==NULL){
                this->Book_insert(c,n,an,Q);
                return;
            }
            newBook->prev=temp->prev;
            temp->prev->next=newBook;
            temp->prev=newBook;
            newBook->next=temp;
        }
    }
    void display() {
        if (head == NULL) {
            cout << "NOT FOUND ANY BOOKS\n";
            return;
        } else {
            Book *temp = head;
            int i = 1;
            while (temp != NULL) {
                cout << "BOOK #" << i << endl;
                cout << "Book name: " << temp->book_name << endl << "Author name: " << temp->author_name << endl
                     << "Category: " << temp->category <<endl<<"QR: "<<temp->QR<< endl<<endl;
                temp = temp->next;
                i++;
            }
        }
    }
    void del_pos(int pos){
        if(head==NULL){
            cout<<"Linkedlist is empty \n";
            return;
        }
        if(pos==0){
            Book*temp=head;
            head=temp->next;
            if(head!=NULL)
                head->prev=NULL;
            delete temp;
            return;
        }else{
            Book*temp=head;
            for(int i=0;i<pos && temp!=NULL;i++){
                temp=temp->next;
            }
            if(temp==NULL){
                cout<<"position is bigger than linkedlist\n";
                return;
            }else{
                temp->prev->next=temp->next;
                if(temp->next!=NULL)
                    temp->next->prev=temp->prev;
                delete temp;
            }
        }
    }
    void del(){
        if(head==NULL){
            return;
        }else{
            Book*temp=head;
            head=temp->next;
            head->prev=NULL;
            delete temp;
        }
    }
    void del_end(){
        if(head==NULL){
            return;
        }else{
            Book*prev,*temp;
            prev=temp=head;
            while(temp->next!=NULL){
                prev=temp;
                temp=temp->next;
            }
            prev->next=NULL;
            delete temp;
        }
    }
    void del_name(string v){
        if(head==NULL){
            return;
        }else{
            Book*temp=head;
            if(temp->book_name==v){
                head=temp->next;
                if(head!=NULL)
                    head->prev=NULL;
                delete temp;
                return;
            }else{
                while(temp!=NULL && temp->book_name!=v){
                    temp=temp->next;
                }
                if(temp==NULL){
                    return;
                }else{
                    temp->prev->next=temp->next;
                    if(temp->next!=NULL)
                        temp->next->prev=temp->prev;
                    delete temp;}
            }
        }
    }
};
class Student_Linkedlist{
public:
    class Student{
    public:
        string name;
        int id;
        string phone;
        Student* next;
        Student* prev;
        Student(){
            next=NULL;
            prev=NULL;
        }
    };
    Student*head=NULL;
    void Student_insert(int val,string n,string p){
        Student*newStudent=new Student;
        newStudent->id=val;
        newStudent->name=n;
        newStudent->phone=p;
        if(head==NULL)
        {
            head=newStudent;
            newStudent->next=NULL;
            newStudent->prev=NULL;
        }else{
            Student*last=head;
            while(last->next!=NULL)
            {
                last=last->next;
            }
            last->next=newStudent;
            newStudent->prev=last;
        }
    }
    void Student_insert_be(int val,string n,string p){
        Student*newStudent=new Student;
        newStudent->id=val;
        newStudent->name=n;
        newStudent->phone=p;
        if(head==NULL)
        {
            head=newStudent;
            newStudent->next=NULL;
        }
        else
        {
            newStudent->next=head;
            head->prev=newStudent;
            head=newStudent;
        }
    }
    int count(){
        int cot=0;
        Student *temp=head;
        while(temp!=NULL){
            cot++;
            temp=temp->next;
        }
        return cot;
    }
    void sort_linkedlist(){
        Student *cur1=head;
        Student *cur2=head;
        for(int i=0;i<count();i++){
            for(int j=0;j<count()-1;j++) {
                if (cur1->id < cur2->id) {
                    int temp = cur1->id;
                    string temp_name =cur1->name;
                    string temp_phone=cur1->phone;
                    cur1->id = cur2->id;
                    cur1->name=cur2->name;
                    cur1->phone=cur2->phone;
                    cur2->id = temp;
                    cur2->name=temp_name;
                    cur2->phone=temp_phone;
                }
                cur2 = cur2->next;
            }
            cur2=head;
            cur1=head->next;
            for(int k=0;k<i;k++){
                cur1=cur1->next;
            }
        }
    }
    void Student_insert_pos(int val,string n,string p,int pos){
        Student*newStudent=new Student;
        newStudent->id=val;
        newStudent->name=n;
        newStudent->phone=p;
        if(pos==0){
            newStudent->next=head;
            head->prev=newStudent;
            head=newStudent;
            return;
        }else{
            Student*temp=head;
            for(int i=0;i<pos && temp!=NULL;i++)
            {
                temp=temp->next;
            }
            if(temp==NULL){
                this->Student_insert(val,n,p);
                return;
            }
            newStudent->prev=temp->prev;
            temp->prev->next=newStudent;
            temp->prev=newStudent;
            newStudent->next=temp;
        }
    }
    void Student_display(){
        if(head==NULL){
            cout<<"DID NOT FOUND ANY STUDENTS \n";
            return;
        }
        else{
            int i=1;
            Student *temp = head;
            while (temp!=NULL)
            {
                cout<<"STUDENT #"<<i<<endl;
                cout<<"Name: "<<temp->name<<endl<<"ID: "<<temp->id<<endl
                <<"Phone Number: "<<temp->phone<<endl<<endl;
                temp=temp->next;
                i++;
            }
        }
    }
    void student_update(string newName,int newId,string newPhone,int searchid){

        if(head==NULL)
        {
            cout<<" The Linked list is empty"<<endl;
            return;
        }
        else {
            Student *temp = head;

            while (temp != NULL && temp->id!=searchid){
                temp=temp->next;
            }
            temp->name = newName;
            temp->id = newId;
            temp->phone = newPhone;

            cout<<"Data Updated Successfully"<<endl;
        }

    }
    bool search(int newID){
        if(head == NULL){
            cout<<"ID IS NOT FOUND \n";
            return false ;
        }
        else{
            Student *temp = head;
            while (temp != NULL && temp->id != newID){
                temp=temp->next;
            }
            if(temp == NULL){
                cout<<"STUDENT IS NOT FOUND\n";
                return false;
            }
            else{
                cout<<"Name: "<<temp->name<<endl<<"ID: "<<temp->id<<endl<<"Phone Number: "<<temp->phone<<endl;
                return true;
            }
        }
    }

    void Student_del_pos(int pos){
        if(head==NULL){
            cout<<"Linkedlist is empty \n";
            return;
        }
        if(pos==0){
            Student*temp=head;
            head=temp->next;
            if(head!=NULL)
                head->prev=NULL;
            delete temp;
            return;
        }else{
            Student*temp=head;
            for(int i=0;i<pos && temp!=NULL;i++){
                temp=temp->next;
            }
            if(temp==NULL){
                cout<<"position is bigger than linkedlist\n";
                return;
            }else{
                temp->prev->next=temp->next;
                if(temp->next!=NULL)
                    temp->next->prev=temp->prev;
                delete temp;
            }
        }
    }
    void Student_del(){
        if(head==NULL){
            return;
        }else{
            Student*temp=head;
            head=temp->next;
            head->prev=NULL;
            delete temp;
        }
    }
    void Student_del_end(){
        if(head==NULL){
            return;
        }else{
            Student*prev,*temp;
            prev=temp=head;
            while(temp->next!=NULL){
                prev=temp;
                temp=temp->next;
            }
            prev->next=NULL;
            delete temp;
        }
    }
    void Student_del_id(int v){
        if(head==NULL){
            return;
        }else{
            Student*temp=head;
            if(temp->id==v){
                head=temp->next;
                if(head!=NULL)
                    head->prev=NULL;
                delete temp;
                return;
            }else{
                while(temp!=NULL && temp->id!=v){
                    temp=temp->next;
                }
                if(temp==NULL){
                    return;
                }else{
                    temp->prev->next=temp->next;
                    if(temp->next!=NULL)
                        temp->next->prev=temp->prev;
                    delete temp;}
            }
        }
    }

};
class Node_book
{
public:
    string name_book;
    string auther;
    string subject;
    Node_book*next;
    Node_book(string name_book,string auther,string subject){
        this->name_book=name_book;
        this->auther=auther;
        this->subject=subject;
        this->next=NULL;
    }
};

class Node_Student
{
public:
    string name_student;
    string id_student;
    string number_phone;
    Node_Student*next;
    Node_Student(string name_student,string id_student,string number_phone){
        this->name_student=name_student;
        this->id_student=id_student;
        this->number_phone=number_phone;
        this->next=NULL;
    }
};
class Stack_book {
    Node_book * head;
public:
    int max_book;
    int listsize_book;
    Stack_book (int max_book)
    {
        this->max_book=max_book;
        listsize_book=0;
        head=NULL;
    }

    bool IsEmpty(){
        if (head==NULL){

            return true;}
        else{
            return false;}
    }

    bool IsFull(){
        if(listsize_book==max_book){

            return true;
        }
        else
            return false;
    }

    bool push_Book(string name_book,string auther,string subject){
        if(listsize_book<max_book){
            Node_book * newnode =new Node_book( name_book, auther, subject);
            newnode->name_book=name_book;
            newnode->auther=auther;
            newnode->subject=subject;

            if(IsEmpty()){
                head=newnode;
                newnode->next=NULL;

            }
            else{
                newnode->next=head;
                head=newnode;
            }
            listsize_book ++;
            return true;
        }
        else{

            cout<<"stack is full"<<endl;
            return false;

        }
    }

    void pop_book()
    {
        if (IsEmpty())
        {
            cout<<"stack is empty"<<endl;
            exit(1);
        }
        else
        {
            string name_book=head->name_book;
            string auther=head->auther;
            string subject=head->subject;
            head =head->next;
            listsize_book --;

            cout << "Book name: " << name_book << endl << "Author name: " << auther << endl
                 << "Category: " << subject << endl<<endl;

        }
    }
    void peack_book(){

        if(IsEmpty()){
            cout<<"stack is empty"<<endl;
            return;
        }
        else{
            Node_book*temp=head;
            int i=1;
            while(temp!=NULL){
                cout << "BOOK #" << i << endl;
                cout << "Book name: " << temp->name_book << endl << "Author name: " << temp->auther << endl
                     << "Category: " << temp->subject << endl<<endl;
                temp = temp->next;
                i++;
            }
        }
    }
};
class Stack_student
{
    Node_Student * top;
public:
    int max_student;
    int listsize_student;
    Stack_student (int max_student)
    {
        this->max_student=max_student;
        listsize_student=0;
        top=NULL;
    }

    bool IsEmpty(){
        if (top==NULL){
            return true;}
        else{
            return false;}
    }

    bool IsFull(){
        if(listsize_student==max_student){

            return true;
        }
        else
            return false;
    }

    bool push_student(string name_student,string id_student,string number_phone){
        if(listsize_student<max_student){
            Node_Student * newnode =new Node_Student(  name_student, id_student, number_phone);
            newnode->name_student=name_student;
            newnode->id_student=id_student;
            newnode->number_phone=number_phone;

            if(IsEmpty()){
                top=newnode;
                newnode->next=NULL;

            }
            else{
                newnode->next=top;
                top=newnode;
            }
            listsize_student ++;
            return true;
        }
        else{

            cout<<"stack is full"<<endl;
            return false;

        }
    }

    void pop_student()
    {
        if (IsEmpty())
        {
            cout<<"stack is empty"<<endl;
            return ;
        }
        else
        {


            string name_student=top->name_student;
            string id_student=top->id_student;
            string number_phone=top->number_phone;
            top =top->next;
            listsize_student --;

            cout << "Student name: " << name_student << endl << "Student id: " << id_student << endl
                 << "Student phone: " << number_phone << endl<<endl;

        }
    }
    void peak_student(){

        if(IsEmpty()){
            cout<<"Stack is empty\n";
            return ;}
        else{
            Node_Student*temp=top;
            int i=1;
            while(temp!=NULL){
                cout<<"STUDENT #"<<i<<endl;
                cout<<"Name: "<<temp->name_student<<endl<<"ID: "<<temp->id_student<<endl
                <<"Phone Number: "<<temp->number_phone<<endl<<endl;
                temp=temp->next;
                i++;
            }
        }
    }
};
int main() {
    Book_Linkedlist qw;
    Student_Linkedlist qa;
    Stack_book *s=new Stack_book(10);
    Stack_student *y=new Stack_student(10);
    qw.Book_insert("Fantasy","harry_potter","Helmey",1);
    qw.Book_insert("Fantasy","lord_of_the_ring ","Gandalif",2);
    qw.Book_insert("Romance","titanic","Rose",3);
    qw.Book_insert("Romance","sunshine","Adam",4);
    qw.Book_insert("Historical","pharphos","hossam",5);
    qw.Book_insert("Historical","alexander","Alex",6);
    qw.Book_insert("Horror","the_conjuring","Valak",7);
    qw.Book_insert("Horror","ring","Ghost",8);
    qw.Book_insert("Action","marvel","Tony",9);
    qw.Book_insert("Action","spider_man","Peter",10);
    qa.Student_insert(42110057,"hossam","012367891");
    qa.Student_insert(42110288,"ahmed","012367892");
    qa.Student_insert(42110113,"akrm","010034567893");
    qa.Student_insert(42110189,"bilal","001234567894");
    qa.Student_insert(42110115,"yassmin","01134567895");
    qa.Student_insert(42110020,"gasser","01234567896");
    qa.Student_insert(42110030,"polo","0124567897");
    qa.Student_insert(42110100,"mohamed","0123456798");
    qa.Student_insert(42110600,"mahmoud","0123456899");
    qa.Student_insert(42110575,"mostafa","0123457890");

    cout<<"***********************************************\n";
    cout<<"*                                             *\n";
    cout<<"*                                             *\n";
    cout<<"*          ----------------------             *\n";
    cout<<"*          WELCOME TO ACU LIBRARY             *\n";
    cout<<"*          ----------------------             *\n";
    cout<<"*                                             *\n";
    cout<<"*                                             *\n";
    cout<<"***********************************************\n";

    cout<<"***********************************************\n";
    cout<<"*                                             *\n";
    cout<<"*                                             *\n";
    cout<<"*          ----------------------             *\n";
    cout<<"*             ACU LIBRARY INFO                *\n";
    cout<<"*          ----------------------             *\n";
    cout<<"*          Egypt,6 of Octobor                 *\n";
    cout<<"*         Email:ACULIBRAY@gmail.com           *\n";
    cout<<"*         phone:0124*****32                   *\n";
    cout<<"*                                             *\n";
    cout<<"***********************************************\n";

    cout<<"        Press Enter to continue                 \n";
    getchar();

    int choice;
    string pass;
    cout<<"Please enter the password (Which is admin123  ;)  /  ^__^ )\n";
    cin>>pass;
    while(pass!="admin123"){
        cout<<"incorrect password ***(admin123)***\n";
        cin>>pass;
    }
    while(choice!=4) {
        cout << "***********************************************\n";
        cout << "*               MAIN MENU                     *\n";
        cout << "                1.Borrow a Book                \n";
        cout << "                2.Return a Book                \n";
        cout << "                3.ADMINISTRATOR MENU           \n";
        cout << "                4.Exit                         \n";


        cout << "*      Please enter your choice     *\n";
        cin >> choice;
        if (choice == 1) {

            string name;
            cout << "Please enter the name of the book \n";
            cin>>name;

            if(qw.search(name)==true) {
                cout<<endl << "Please Remember To Return it in One Week\n"<<endl;
                cout << "Have Fun Reading it ^__^\n"<<endl;
            }

            qw.del_name(name);
            cout << "                1.Return to Main menu                               \n";
            cout << "                2.Exit                \n";
            int c;
            cout << "*      Please enter your choice     *\n";
            cin>>c;
            if(c==2)
            {
                cout<<"Have a good day";
                return 0;
            }

            /*use search function ifreturn true cout please return it in 3 days
             * and have fun reading else cout<<this book is not avilable at the moment*/

        } else if (choice == 2) {
            string ca;
            string n;
            string a;
            int q;
            cout << "Please enter the category of the book \n";
            cin>>ca;
            cout << "Please enter the name of the book \n";
            cin>>n;
            cout << "Please enter the name  of the author \n";
            cin>>a;
            cout << "Please enter the QR  of the book \n";
            cin>>q;
            qw.Book_insert(ca,n,a,q);
            cout << "                1.Return to Main Menu                               \n";
            cout << "                2.Exit                \n";
            int c;
            cout << "*      Please enter your choice     *\n";
            cin>>c;
            if(c==2)
            {
                cout<<"Have a good day";
                return 0;
            }
        } else if (choice == 3) {
            cout << "***********************************************\n";
            cout << "*              ADMINISTRATOR MENU             *\n";
            cout << "                1.System by Linkedlist                   \n";
            cout << "                2.System by stack                \n";
            int p;
            cout<<"Enter your choice \n";
            cin>>p;
            string ca;
            string n;
            string a;
            int q;
            if(p==1) {
                cout << "***********************************************\n";
                cout << "*              ADMINISTRATOR MENU             *\n";
                cout << "                1.BOOK MENU                   \n";
                cout << "                2.STUDENT MENU                \n";
                int p;
                cout << "Enter your choice \n";
                cin >> p;
                if (p == 1) {
                    while (p != 12) {
                        cout << "***********************************************\n";
                        cout << "*              BOOK MENU                      *\n";
                        cout << "                1.Enter a Book at the end of the list                \n";
                        cout << "                2.Enter a Book at the beginning of the list                \n";
                        cout << "                3.Enter a Book at any position                 \n";
                        cout << "                4.Remove a Book by name               \n";
                        cout << "                5.Remove a Book by position               \n";
                        cout << "                6.Remove a Book from the start of the list                \n";
                        cout << "                7.Remove a Book from the end of the list               \n";
                        cout << "                8.Sort Books                   \n";
                        cout << "                9.Display all Books            \n";
                        cout << "                10.Search by name for book      \n";
                        cout << "                11.Numbers of Books      \n";
                        cout << "                12.Return to main menu                         \n";
                        cout << "                13.Exit                         \n";
                        cout << "         Please Enter your choice                \n ";
                        cin >> p;
                        if (p == 1) {
                            int x;
                            cout << "Enter how many books you want to add\n";
                            cin >> x;
                            for (int i = 0; i < x; i++) {
                                cout << "Please enter the category of the book  #" << i + 1 << "\n";
                                cin >> ca;
                                cout << "Please enter the name of the book #" << i + 1 << "\n";
                                cin >> n;
                                cout << "Please enter the name  of the author #" << i + 1 << "\n";
                                cin >> a;
                                cout << "Please enter the QR  of the book #" << i + 1 << "\n";
                                cin>>q;
                                qw.Book_insert(ca, n, a,q);
                            }
                        } else if (p == 2) {
                            int x;
                            cout << "Enter how many books you want to add\n";
                            cin >> x;
                            for (int i = 0; i < x; i++) {
                                cout << "Please enter the category of the book  #" << i + 1 << "\n";
                                cin >> ca;
                                cout << "Please enter the name of the book #" << i + 1 << "\n";
                                cin >> n;
                                cout << "Please enter the name  of the author #" << i + 1 << "\n";
                                cin >> a;
                                cout << "Please enter the QR  of the book #" << i + 1 << "\n";
                                cin>>q;
                                qw.Book_insert_be(ca, n, a,q);
                            }
                        } else if (p == 3) {
                            cout << "Enter position you want to add the book to \n";
                            cin >> p;
                            cout << "Please enter the category of the book  \n";
                            cin >> ca;
                            cout << "Please enter the name of the book \n";
                            cin >> n;
                            cout << "Please enter the name  of the author \n";
                            cin >> a;
                            cout << "Please enter the QR  of the book \n";
                            cin>>q;
                            qw.Book_insert_pos(ca, n, a, p,q);
                        } else if (p == 4) {
                            string j;
                            cout << "Enter name of the book \n";
                            cin>>j;
                            qw.del_name(j);
                        }
                        else if(p==5){
                            int g;
                            cout<<"Enter the position of the book you want to delete\n";
                            cin>>g;
                            qw.del_pos(g);
                        }
                        else if (p == 6) {
                            qw.del();
                        }

                        else if (p == 7) {
                            qw.del_end();
                        } else if (p == 8) {
                            qw.sort_linkedlist_book();
                            cout<<"List is sorted\n";
                        } else if (p == 9) {
                            qw.display();
                        } else if (p == 10) {
                            string name;
                            cout << "Enter name of the book \n";
                            cin >> name;
                            qw.search(name);
                        }else if (p == 11) {
                            cout<<qw.count()<<endl;
                        }else if (p == 12) {
                            break;
                        } else if (p == 13) {
                            cout << "Have a good day \n";
                            return 0;
                        } else {
                            cout << "invalid number please enter again \n";
                        }
                    }
                } else if (p == 2) {

                    int id;
                    string ph;
                    string n;
                    int k;

                    while (k != 13) {
                        cout << "***********************************************\n";
                        cout << "*              STUDENTS MENU                     *\n";
                        cout << "                1.Add a Student at the end of the list                   \n";
                        cout << "                2.Add a Student at the beginning of the list                  \n";
                        cout << "                3.Add a Student at any position                 \n";
                        cout << "                4.Remove a Student by id               \n";
                        cout << "                5.Remove a Student from any position               \n";
                        cout << "                6.Remove a Student from the start of the list                \n";
                        cout << "                7.Remove a Student from the end of the list                \n";
                        cout << "                8.Update a Student Info           \n";
                        cout << "                9.Sort Students                   \n";
                        cout << "                10.Display all Students            \n";
                        cout << "                11.Search for Student by id        \n";
                        cout << "                12.Number of Students        \n";
                        cout << "                13.Return to main menu                            \n";
                        cout << "                14.Exit                            \n";

                        cout << "please enter your choice \n";
                        cin >> k;
                        if (k == 1) {
                            cout << "Enter the number of students you want to enter \n";
                            cin >> k;
                            for (int i = 0; i < k; i++) {
                                cout << "Enter id of the student #" << i + 1 << endl;
                                cin >> id;
                                cout << "Enter name of the student #" << i + 1 << endl;
                                cin >> n;
                                cout << "Enter phone of the student #" << i + 1 << endl;
                                cin >> ph;
                                qa.Student_insert(id, n, ph);
                            }
                        } else if (k == 2) {
                            cout << "Enter the number of students you want to enter \n";
                            cin >> k;
                            for (int i = 0; i < k; i++) {
                                cout << "Enter id of the student #" << i + 1 << endl;
                                cin >> id;
                                cout << "Enter name of the student #" << i + 1 << endl;
                                cin >> n;
                                cout << "Enter phone of the student #" << i + 1 << endl;
                                cin >> ph;
                                qa.Student_insert_be(id, n, ph);
                            }
                        } else if (k == 3) {
                            cout << "Enter position you want to add the student in the list\n";
                            cin >> k;
                            cout << "Enter id of the student " << endl;
                            cin >> id;
                            cout << "Enter name of the student " << endl;
                            cin >> n;
                            cout << "Enter phone of the student " << endl;
                            cin >> ph;
                            qa.Student_insert_pos(id, n, ph, k);
                        } else if (k == 4) {
                            int h;
                            cout << "Enter id of the student you want to delete\n";
                            cin >> h;
                            qa.Student_del_id(h);
                        }
                        else if (k == 5) {
                         int g;
                         cout<<"Enter position you want to delete\n";
                         cin>>g;
                         qa.Student_del_pos(g);
                        }else if (k == 6) {

                            qa.Student_del();

                        } else if (k == 7) {
                            qa.Student_del_end();
                        } else if (k == 8) {
                            int id;
                            cout << "Enter id of the studnet you want to update \n";
                            cin >> id;

                            if (qa.search(id) == true) {
                                int newid;
                                string newname;
                                string newphone;
                                cout << "                              \n";
                                cout << "Enter updated id \n";
                                cin >> newid;
                                cout << "Enter updated name \n";
                                cin >> newname;
                                cout << "Enter updated phone \n";
                                cin >> newphone;
                                qa.student_update(newname, newid, newphone, id);
                            }
                        } else if (k == 9) {
                            qa.sort_linkedlist();
                            cout<<"List is sorted\n";
                        } else if (k == 10) {
                            qa.Student_display();
                        } else if (k == 11) {
                            int id;
                            cout << "Enter the id of the student \n";
                            cin >> id;
                            qa.search(id);
                        }
                        else if(k==12){
                            cout<<qa.count()<<endl;
                        }
                        else if (k == 13) {
                            break;
                        } else if (k == 14) {
                            cout << "Have a good day \n";
                            return 0;
                        } else {
                            cout << "invalid number please enter again\n";
                        }
                    }
                }
                else{
                    cout<<"Invalid number please enter again \n";
                }
            }
            else if(p==2){
                cout << "***********************************************\n";
                cout << "*              ADMINISTRATOR MENU             *\n";
                cout << "                1.BOOK MENU                   \n";
                cout << "                2.STUDENT MENU                \n";
                int p;
                cout << "Enter your choice \n";
                cin >> p;
                if(p==1){
                    string np;
                    string na;
                    string nc;
                    while (p != 7) {

                        cout << "***********************************************\n";
                        cout << "*              BOOK MENU                      *\n";
                        cout << "                1.Push a Book                 \n";
                        cout << "                2.PoP a Book                \n";
                        cout << "                3.Display all Books                 \n";
                        cout << "                4.Check if stack is full               \n";
                        cout << "                5.Check if stack is empty                \n";
                        cout << "                6.Return to main menu                         \n";
                        cout << "                7.Exit                         \n";
                        cout << "         Please Enter your choice                \n ";
                        cin >> p;
                        if(p==1){
                            cout << "Enter name of the book \n";
                            cin >> np;
                            cout << "Enter name of the author \n";
                            cin >> na;
                            cout << "Enter category of the book \n";
                            cin >> nc;
                            s->push_Book(np,na,nc);
                        }
                        else if(p==2){
                            s->pop_book();
                        }
                        else if(p==3){
                            s->peack_book();
                        }
                        else if(p==4)
                        {
                            if(s->IsFull()==true)
                            {
                                cout<<"Stack is Full\n";
                            }
                            else{
                                cout<<"Stack is not Full\n";
                            }
                        }
                        else if(p==5)
                        {
                            if(s->IsEmpty()==true)
                            {
                                cout<<"Stack is Empty\n";
                            }
                            else
                            {
                                cout<<"Stack is not Empty\n";
                            }
                        }
                        else  if(p==6)
                        {
                            break;
                        }
                        else if(p==7){
                            cout<<"Have a good day \n";
                            return 0;
                        }
                        else{
                            cout<<"Invalid number please enter again\n";
                        }
                    }

                }
                if(p==2){

                    string si;
                    string pn;
                    string ns;

                    while (p != 7) {
                        cout << "***********************************************\n";
                        cout << "*              STUDENT MENU                      *\n";
                        cout << "                1.Push a Student                 \n";
                        cout << "                2.PoP a Student                \n";
                        cout << "                3.Display all Students                 \n";
                        cout << "                4.Check if stack is full               \n";
                        cout << "                5.Check if stack is empty                \n";
                        cout << "                6.Return to main menu                         \n";
                        cout << "                7.Exit                         \n";
                        cout << "         Please Enter your choice                \n ";
                        cin >> p;
                        if(p==1){
                            cout << "Enter id of the student \n";
                            cin >> si;
                            cout << "Enter name of the student \n";
                            cin >> ns;
                            cout << "Enter phone of the student \n";
                            cin >> pn;
                            y->push_student(ns,si,pn);
                        }
                        else if(p==2)
                        {
                            y->pop_student();
                        }
                        else if(p==3)
                        {
                            y->peak_student();
                        }
                        else if(p==4)
                        {
                            if(y->IsFull()==true)
                            {
                                cout<<"Stack is Full\n";
                            }
                            else{
                                cout<<"Stack is not Full\n";
                            }
                        }
                        else  if(p==5){
                            if(y->IsEmpty()==true){
                                cout<<"Stack is Empty\n";
                            }
                            else
                            {
                                cout<<"Stack is not Empty\n";
                            }
                        }
                        else if(p==6)
                        {
                            break;
                        }
                        else if(p==7){
                            return 0;
                        }
                        else{
                            cout<<"Invalid number please enter again\n";
                        }
                    }
                }
            }
            else {
                cout<<"Invalid number please enter again\n";
            }
        }
        else if(choice ==4){
            cout<<"Have a good day \n";
        }
        else{
            cout<<"invalid number please enter again\n";
        }
    }
    return 0;
}