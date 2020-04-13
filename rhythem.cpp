                 
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<fstream>
#include<string.h>
#include<conio.h>
using namespace std;
class Lib
{
   public:
       char books[100],auname[50],sc[20],sc1[50];
       int q,B,p;
       Lib()
       {
           strcpy(books,"NO Book Name");
           strcpy(auname,"No Author Name");
           strcpy(sc,"No Book ID");
           strcpy(sc1,"No Book ID");
           q=0;
           B=0;
           p=0;
       }
          void get();
          void student();
          void librarian();
          void getdata();
          void show(int);
          void booklist(int);
          void modify();
          void see(int);
          int branch(int);
          void issue();
          void der(char[],int,int);
};
void Lib::getdata()
{
                    int i;
                    fflush(stdin);
                    cout<<"\n\t\tEnter the details :-\n";
                    cout<<"\n\t\tEnter Book's Name : ";
                    cin.getline(books,100);
                    for(i=0;books[i]!='\0';i++)
                    {
                    if(books[i]>='a'&&books[i]<='z')
                       books[i]-=32;
                    }
                    cout<<"\n\t\tEnter Author's Name : ";
                    cin.getline(auname,50);
                    cout<<"\n\t\tEnter Publication name : ";
                    cin.getline(sc1,50);
                    cout<<"\n\t\tEnter Book's ID : ";
                    cin.getline(sc,20);
                    cout<<"\n\t\tEnter Book's Price : ";
                    cin>>p;
                    cout<<"\n\t\tEnter Book's Quantity : ";
                    cin>>q;
}
void Lib::show(int i)
{
    cout<<"\n\t\tBook Name : "<<books<<endl;
    cout<<"\n\t\tBook's Author Name : "<<auname<<endl;
    cout<<"\n\t\tBook's ID : "<<sc<<endl;
    cout<<"\n\t\tBook's Publication : "<<sc1<<endl;
    if(i==2)
    {
        cout<<"\n\t\tBook's Price : "<<p<<endl;
        cout<<"\n\t\tBook's Quantity : "<<q<<endl;
    }
}
  void Lib::booklist(int i)
  {
                int b,r=0;
                system("cls");
                b=branch(i);
                system("cls");
                ifstream intf("Booksdata.txt",ios::binary);
                if(!intf)
                    cout<<"\n\t\tFile Not Found.";
                else
                {
                    cout<<"\n\t    ************ Book List ************ \n\n";
                    intf.read((char*)this,sizeof(*this));
                while(!intf.eof())
                {
                    if(b==B)
                    {
                        if(q==0 && i==1)
                        {

                        }
                        else
                            {
                                r++;
                                cout<<"\n\t\t********** "<<r<<". ********** \n";
                                show(i);
                            }
                    }
                    intf.read((char*)this,sizeof(*this));
                }
                }
                cout<<"\n\t\tPress any key to continue.....";
                getch();
                system("cls");
                if(i==1)
                    student();
                else
                    librarian();
    }
  void Lib::modify()
  {
    char ch,st1[100];
    int i=0,b,cont=0;
    system("cls");
    cout<<"\n\t\t>>Please Choose one option :-\n";
    cout<<"\n\t\t1.Modification In Current Books\n\n\t\t2.Add New Book\n\n\t\t3.Delete A Book\n\n\t\t4.Go back\n";
    cout<<"\n\n\t\tEnter your choice : ";
    cin>>i;
    if(i==1)
    {
                    system("cls");
                    b=branch(2);
                    ifstream intf1("Booksdata.txt",ios::binary);
                    if(!intf1)
                    {
                        cout<<"\n\t\tFile Not Found\n";
                        cout<<"\n\t\tPress any key to continue.....";
                        getch();
                        system("cls");
                        librarian();
                    }
                        intf1.close();
                        system("cls");
                        cout<<"\n\t\tPlease Choose One Option :-\n";
                        cout<<"\n\t\t1.Search By Book Name\n\n\t\t2.Search By Book's ID\n";
                        cout<<"\n\t\tEnter Your Choice : ";
                        cin>>i;
                        fflush(stdin);
                        if(i==1)
                            {
                                system("cls");
                                cout<<"\n\t\tEnter Book Name : ";
                                cin.getline(st1,100);
                                system("cls");
                                fstream intf("Booksdata.txt",ios::in|ios::out|ios::ate|ios::binary);
                                intf.seekg(0);
                                intf.read((char*)this,sizeof(*this));
                                while(!intf.eof())
                                    {
                                        for(i=0;b==B&&books[i]!='\0'&&st1[i]!='\0'&&(st1[i]==books[i]||st1[i]==books[i]+32);i++);
                                        if(books[i]=='\0'&&st1[i]=='\0')
                                            {
                                                cont++;
                                                getdata();
                                                intf.seekp(intf.tellp()-sizeof(*this));
                                                intf.write((char*)this,sizeof(*this));
                                                break;
                                            }
                                                     intf.read((char*)this,sizeof(*this));
                                    }
                                    intf.close();
                            }
                        else if(i==2)
                        {
                                cout<<"\n\t\tEnter Book's ID : ";
                                cin.getline(st1,100);
                                system("cls");
                                fstream intf("Booksdata.txt",ios::in|ios::out|ios::ate|ios::binary);
                                intf.seekg(0);
                                intf.read((char*)this,sizeof(*this));
                                while(!intf.eof())
                                    {
                                        for(i=0;b==B&&sc[i]!='\0'&&st1[i]!='\0'&&st1[i]==sc[i];i++);
                                        if(sc[i]=='\0'&&st1[i]=='\0')
                                            {
                                                cont++;
                                                getdata();
                                                intf.seekp(intf.tellp()-sizeof(*this));
                                                intf.write((char*)this,sizeof(*this));
                                                break;
                                            }
                                        intf.read((char*)this,sizeof(*this));
                                    }

                                intf.close();
                        }
                        else
                        {
                            cout<<"\n\t\tIncorrect Input.....:(\n";
                            cout<<"\n\t\tPress any key to continue.....";
                            getch();
                            system("cls");
                            modify();
                        }
                        if(cont==0)
                        {
                            cout<<"\n\t\tBook Not Found.\n";
                            cout<<"\n\t\tPress any key to continue.....";
                            getch();
                            system("cls");
                            modify();
                        }
                        else
                            cout<<"\n\t\tUpdate Successful.\n";


    }
    else if(i==2)
    {
                    system("cls");
                    B=branch(2);
                    system("cls");
                    getdata();
                    ofstream outf("Booksdata.txt",ios::app|ios::binary);
                    outf.write((char*)this,sizeof(*this));
                    outf.close();
                    cout<<"\n\t\tBook added Successfully.\n";
    }
    else if(i==3)
    {
                    system("cls");
                    b=branch(2);
                    ifstream intf1("Booksdata.txt",ios::binary);
                    if(!intf1)
                    {
                        cout<<"\n\t\tFile Not Found\n";
                        cout<<"\n\t\tPress any key to continue.....";
                        getch();
                        intf1.close();
                        system("cls");
                        librarian();
                    }
                        intf1.close();
                        system("cls");
                        cout<<"\n\t\tPlease Choose One Option for deletion:-\n";
                        cout<<"\n\t\t1.By Book Name\n\n\t\t2.By Book's ID\n";
                        cout<<"\n\t\tEnter Your Choice : ";
                        cin>>i;
                        fflush(stdin);
                        if(i==1)
                            {
                                system("cls");
                                cout<<"\n\t\tEnter Book Name : ";
                                cin.getline(st1,100);
                                ofstream outf("temp.txt",ios::app|ios::binary);
                                ifstream intf("Booksdata.txt",ios::binary);
                                intf.read((char*)this,sizeof(*this));
                                while(!intf.eof())
                                    {
                                        for(i=0;b==B&&books[i]!='\0'&&st1[i]!='\0'&&(st1[i]==books[i]||st1[i]==books[i]+32);i++);
                                        if(books[i]=='\0'&&st1[i]=='\0')
                                            {
                                                cont++;
                                                intf.read((char*)this,sizeof(*this));

                                            }
                                        else
                                        {
                                        outf.write((char*)this,sizeof(*this));
                                        intf.read((char*)this,sizeof(*this));
                                        }
                                    }

                    intf.close();
                    outf.close();
                    remove("Booksdata.txt");
                    rename("temp.txt","Booksdata.txt");
                            }
                        else if(i==2)
                        {
                                cout<<"\n\t\tEnter Book's ID : ";
                                cin.getline(st1,100);
                                ofstream outf("temp.txt",ios::app|ios::binary);
                                ifstream intf("Booksdata.txt",ios::binary);
                                intf.read((char*)this,sizeof(*this));
                                while(!intf.eof())
                                    {
                                        for(i=0;b==B&&sc[i]!='\0'&&st1[i]!='\0'&&st1[i]==sc[i];i++);
                                        if(sc[i]=='\0'&&st1[i]=='\0')
                                            {
                                                cont++;
                                                intf.read((char*)this,sizeof(*this));
                                            }
                                        else
                                        {
                                        outf.write((char*)this,sizeof(*this));
                                        intf.read((char*)this,sizeof(*this));
                                        }
                                    }
                    outf.close();
                    intf.close();
                    remove("Booksdata.txt");
                    rename("temp.txt","Booksdata.txt");
                        }
                        else
                        {
                            cout<<"\n\t\tIncorrect Input.....:(\n";
                            cout<<"\n\t\tPress any key to continue.....";
                            getch();
                            system("cls");
                            modify();
                        }
                        if(cont==0)
                        {
                            cout<<"\n\t\tBook Not Found.\n";
                            cout<<"\n\t\tPress any key to continue.....";
                            getch();
                            system("cls");
                            modify();
                        }
                        else
                            cout<<"\n\t\tDeletion Successful.\n";

    }
    else if(i==4)
    {
    system("cls");
    librarian();
    }
    else
    {
    cout<<"\n\t\tWrong Input.\n";
    cout<<"\n\t\tPress any key to continue.....";
    getch();
    system("cls");
    modify();
    }
    cout<<"\n\t\tPress any key to continue.....";
    getch();
    system("cls");
    librarian();

  }
  int Lib::branch(int x)
  {
      int i;
      cout<<"\n\t\t>>Please Choose one Branch :-\n";
      cout<<"\n\t\t1.BIT\n\n\t\t2.EE\n\n\t\t3.EC\n\n\t\t4.CIVIL\n\n\t\t5.MECHANICAL\n\n\t\t6.1ST YEAR\n\n\t\t7.Go to menu\n";
      cout<<"\n\t\tEnter youur choice : ";
      cin>>i;
      switch(i)
      {
          case 1: return 1;
                  break;
          case 2: return 2;
                  break;
          case 3: return 3;
                  break;
          case 4: return 4;
                  break;
          case 5: return 5;
                  break;
          case 6: return 6;
                  break;
          case 7: system("cls");
                  if(x==1)
                  student();
                  else
                    librarian();
          default : cout<<"\n\t\tPlease enter correct option :(";
                    getch();
                    system("cls");
                    branch(x);
        }
  }
  void Lib::see(int x)
  {
      int i,b,cont=0;
      char ch[100];
      system("cls");
      b=branch(x);
      ifstream intf("Booksdata.txt",ios::binary);
        if(!intf)
        {
            cout<<"\n\t\tFile Not Found.\n";
            cout<<"\n\t\t->Press any key to continue.....";
            getch();
            system("cls");
            if(x==1)
            student();
            else
            librarian();
        }

      system("cls");
      cout<<"\n\t\tPlease Choose one option :-\n";
      cout<<"\n\t\t1.Search By Name\n\n\t\t2.Search By Book's ID\n";
      cout<<"\n\t\tEnter Your Choice : ";
      cin>>i;
      fflush(stdin);
      intf.read((char*)this,sizeof(*this));
      if(i==1)
      {
          cout<<"\n\t\tEnter Book's Name : ";
          cin.getline(ch,100);
          system("cls");
          while(!intf.eof())
          {
            for(i=0;b==B&&q!=0&&books[i]!='\0'&&ch[i]!='\0'&&(ch[i]==books[i]||ch[i]==books[i]+32);i++);
            if(books[i]=='\0'&&ch[i]=='\0')
                {
                        cout<<"\n\t\tBook Found :-\n";
                        show(x);
                        cont++;
                        break;
                }
             intf.read((char*)this,sizeof(*this));
          }
      }
          else if(i==2)
          {
          cout<<"\n\t\tEnter Book's ID : ";
          cin.getline(ch,100);
          system("cls");
          while(!intf.eof())
          {
              for(i=0;b==B&&q!=0&&sc[i]!='\0'&&ch[i]!='\0'&&ch[i]==sc[i];i++);
              if(sc[i]=='\0'&&ch[i]=='\0')
                {
                            cout<<"\n\t\tBook Found :-\n";
                            show(x);
                            cont++;
                            break;
                }
               intf.read((char*)this,sizeof(*this));
          }

          }
          else
          {
             cont++;
             cout<<"\n\t\tPlease enter correct option :(";
             getch();
             system("cls");
             see(x);
          }
          intf.close();
          if(cont==0)
              cout<<"\n\t\tThis Book is not available :( \n";

    cout<<"\n\t\tPress any key to continue.....";
    getch();
    system("cls");
    if(x==1)
    student();
    else
    librarian();


  }
void Lib::issue()
{
    char st[50],st1[20];
    int b,i,j,d,m,y,dd,mm,yy,cont=0;
    system("cls");
    cout<<"\n\t\t->Please Choose one option :-\n";
    cout<<"\n\t\t1.Issue Book\n\n\t\t2.Return Book\n\n\t\t3.Go back to menu\n\n\t\tEnter Your Choice : ";
    cin>>i;
    fflush(stdin);
    if(i==1)
    {
    system("cls");
    b=branch(2);
    system("cls");
    fflush(stdin);
    cout<<"\n\t\t->Please Enter Details :-\n";
    cout<<"\n\t\tEnter Book Name : ";
    cin.getline(books,100);
    cout<<"\n\t\tEnter Book's ID : ";
    cin.getline(sc,20);
    //strcpy(st,sc);
    der(sc,b,1);
    cout<<"\n\t\tEnter Student Name : ";
    cin.getline(auname,100);
    cout<<"\n\t\tEnter Student's ID : ";
    cin.getline(sc1,20);
    cout<<"\n\t\tEnter date : ";
    cin>>q>>B>>p;
    ofstream outf("student.txt",ios::binary|ios::app);
    outf.write((char*)this,sizeof(*this));
    outf.close();
    cout<<"\n\n\t\tIssue Successfully.\n";
    }
    else if(i==2)
    {
    system("cls");
    b=branch(2);
    system("cls");
    fflush(stdin);
    cout<<"\n\t\t->Please Enter Details :-\n";
    cout<<"\n\t\tEnter Book's ID : ";
    cin.getline(st1,20);
    der(st1,b,2);
    cout<<"\n\n\t\tEnter Student's ID : ";
    cin.getline(st,20);
    cout<<"\n\t\tEnter Present date : ";
    cin>>d>>m>>y;
    ofstream outf("temp.txt",ios::app|ios::binary);
    ifstream intf("student.txt",ios::binary);
    intf.read((char*)this,sizeof(*this));
    while(!intf.eof())
        {
            for(i=0;sc[i]!='\0'&&st1[i]!='\0'&&st1[i]==sc[i];i++);
            for(j=0;sc1[j]!='\0'&&st[j]!='\0'&&st[j]==sc1[j];j++);
            if(sc[i]=='\0'&&sc1[j]=='\0'&&st[j]=='\0'&&st1[i]=='\0'&&cont==0)
                {
                    cont++;
                    intf.read((char*)this,sizeof(*this));
                    cout<<"\n\t\tReturned successfully.";
                }
            else
                {
                    outf.write((char*)this,sizeof(*this));
                    intf.read((char*)this,sizeof(*this));
                }
        }

    intf.close();
    outf.close();
    getch();
    remove("student.txt");
    rename("temp.txt","student.txt");
    }
    else if(i==3)
    {
    system("cls");
    librarian();
    }
    else
        cout<<"\n\t\tWrong Input.\n";

    cout<<"\n\n\t\tPress any key to continue.....";
    getch();
    system("cls");
    librarian();
}

void Lib::der(char st[],int b,int x)
{
    int i,cont=0;
    fstream intf("Booksdata.txt",ios::in|ios::out|ios::ate|ios::binary);
    intf.seekg(0);
    intf.read((char*)this,sizeof(*this));
    while(!intf.eof())
    {
        for(i=0;b==B&&sc[i]!='\0'&&st[i]!='\0'&&st[i]==sc[i];i++);
        if(sc[i]=='\0'&&st[i]=='\0')
        {
            cont++;
            if(x==1)
            {
                q--;
            }
            else
            {
                q++;
            }
            intf.seekp(intf.tellp()-sizeof(*this));
            intf.write((char*)this,sizeof(*this));
            break;
        }
        intf.read((char*)this,sizeof(*this));
    }
    if(cont==0)
    {
        cout<<"\n\t\tBook not found.\n";
        cout<<"\n\n\t\tPress any key to continue.....";
        getch();
        system("cls");
        issue();
    }
    intf.close();
}
void Lib::get()
{
   int i;
        cout<<"\n\t*********** LIBRARY MANAGEMENT SYSTEM ***********\n"<<"\n\t\t\t    L M S C++\n";
        cout<<"\n\t\t>>Please Choose Any Option To login \n";
        cout<<"\n\t\t1.Student\n\n\t\t2.Librarian\n\n\t\t3.Close Application\n";
        cout<<"\n\t\tEnter your choice : ";
        cin>>i;
        if(i==1)
        {
            system("cls");
            student();
        }
        else if(i==2)
        	librarian();
            //pass();

        else if(i==3)
            exit(0);
        else
        {
            cout<<"\n\t\tPlease enter correct option :(";
            getch();
            system("CLS");
           get();
        }
}
void Lib::student()
{
    int i;
        cout<<"\n\t************ WELCOME STUDENT ************\n";
        cout<<"\n\t\t>>Please Choose One Option:\n";
        cout<<"\n\t\t1.View BookList\n\n\t\t2.Search for a Book\n\n\t\t3.Go to main menu\n\n\t\t4.Close Application\n";
        cout<<"\n\t\tEnter your choice : ";
        cin>>i;
            if(i==1)
                booklist(1);
            else if(i==2)
                see(1);
            else if(i==3)
            {
                system("cls");
                get();
            }
            else if(i==4)
                exit(0);
            else
            {
                cout<<"\n\t\tPlease enter correct option :(";
                getch();
                system("cls");
                student();
            }
}

void Lib::librarian()
{
    int i;
        cout<<"\n\t************ WELCOME LIBRARIAN ************\n";
        cout<<"\n\t\t>>Please Choose One Option:\n";
        cout<<"\n\t\t1.View BookList\n\n\t\t2.Search for a Book\n\n\t\t3.Issue Book\n\n\t\t4.Go to main menu\n\n\t\t5.Close Application\n";
        cout<<"\n\t\tEnter your choice : ";
        cin>>i;
        switch(i)
        {
            case 1:booklist(2);
                     break;
            case 2:see(2);
                     break;
            case 3:issue();
                     break;
            case 4:system("cls");
                     get();
                     break;
            case 5:exit(0);
            default:cout<<"\n\t\tPlease enter correct option :(";
            getch();
            system("cls");
            librarian();
        }
}
int main()
{
    Lib obj;
    obj.get();
    getch();
    return 0;
}

