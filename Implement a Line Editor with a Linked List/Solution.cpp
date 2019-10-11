//your linked list implementation here
#include<string>
#include<iostream>
#include <locale>
#include <cstring>
using namespace std;
struct Node
{
public:
    string text;
    Node * next = nullptr;
};
class LinkedList
{
public:
    int size;
    Node *head;
    LinkedList()    //when should constructor be private
    {
        head = nullptr;
        size = 0;
    }
    Node* add(int index, string textToAdd) //returns the new head and inserts a new node (line)
    {
        int count = 1;
        Node *curr = head; //curr points to the address of head
        Node * toDeleteHead = head;
        Node *newNode = new Node(); //needs the operating system to assign memory also struct dont need ()
        Node * toDeleteNew = newNode;
        newNode->text = textToAdd;
        /**
        if(index>size+1){
            return head;
        }**/
        if(head == nullptr){
            head = newNode;
            delete toDeleteHead;
            size++;
            return head;
        }
        if(index ==0){
            newNode->next = curr;
            size++;
            return newNode;
        }
        while((curr->next) != nullptr){
            if(index == count){
                newNode->next = curr->next;
                curr->next = newNode;
                size++;
                return head;
            }
            curr = curr->next;
            count++;
        }
        if(index>count){ //I'm pretty sure this code never runs due to insert x method's print statement
            //Node * toDelete = head;
            cout<<"WOW U REALLY SCREWED UP \n";
            return nullptr;
        }
        curr->next = newNode;
        newNode->next = nullptr;
        size++;
        return head;
    }
    void print(){
        int count = 1;
        Node * temp = head;
        while(temp != nullptr){
            cout<< count << " " <<temp->text<<"\n";
            temp = temp->next;
            count++;
        }
    }
    void search(const string look){
        int count = 1;
        bool find = false;
        Node * temp = head;
        while(temp != nullptr){
            if((temp->text).find(look)!= string::npos){
                cout<<count<< " " <<temp->text<<"\n";
                find = true;
            }
            temp = temp->next;
            count++;
        }
        if(!find)
            cout<<"not found" <<"\n";
    }
    void edit(int index, const string textReplace){
        int count = 1;
        bool find = false;
        Node * temp = head;
        while(temp != nullptr){
            if(count == index){
                temp->text = textReplace;
                find = true;
                break;
            }
            temp = temp->next;
            count++;
        }
        if(!find){}
        //cout<<"not found - edit" <<"\n";
    }
    void deletetext(int index){ //delete 1 on empty needs to be fixed
        int count = 1;
        Node * prev = head;
        if(index == 1){
            if(head != nullptr){
                Node * toDelete = head;
                prev = nullptr;
                head = head->next;
                delete toDelete;
                size--; //why was this not here before
            }
        }
        while(prev != nullptr){
            if(prev->next ==nullptr){ //testing failed case
                break;
            }
            if((count+1) == index){
                Node * toDelete = prev->next;
                prev->next = prev->next->next; //prob should delete the value.
                delete toDelete;
                size--;
                break;
            }
            count++;
            prev = prev->next;
        }
    }
};
//your line editor implementation here
class LineEditor
{
public:
    LinkedList list;
    /*
    void insertEnd(string s){
        list.head = list.add(1,s);
    }*/
    void insert(int index, string s){
        list.head = list.add(index, s);
    }
    void deletetext(int index){
        list.deletetext(index);
    }
    void edit(int index, string s){
        list.edit(index,s);
    }
    void print(){
        list.print();
    }
    void search(string s){
        list.search(s);
    }
};

int main() //need to do more than "9 lines"
{
    //your code to invoke line editor here
    LineEditor le;
    string s;
    locale loc;
    while (s != "quit"){
        getline (cin,s);
        if(s.empty()){
            //cout<<"you inputted like an empty string\n";
            s="";
        }
        if(s.substr(s.find("\"")+1,s.find_last_of("\"")-1-s.find_first_of("\"")).size()>80){
            //cout<<"you inputted text with more than 80 chars\n";
            s="";
        }
        if(s.substr(s.find(" ")+1,1)=="-"){
            //cout<<"you inputted a negative index\n";
            s="";
        }
        int temp = s.find(" ");
        for (int i=0; i<temp; ++i) // you need string:: .. actually u dont seems to be unsign int
            s[i] = tolower(s[i],loc);
        if(s.find("insertend") != string::npos) { //you need string::
            //cout<<(s.find_last_of("\"")-s.find_first_of("\""))<<"\n";
            le.insert(le.list.size, s.substr(s.find("\"")+1,s.find_last_of("\"")-1-s.find_first_of("\"")));// don't use -12
        }
        if(s.find("insert ") != string::npos){
            //cout<<stoi(s.substr(s.find(" ")+1,s.find_last_of(" ")-1-s.find_first_of(" ")))<<" " <<le.list.size<< "\n";
            if(s.substr(s.find(" ")+1,1)!="-" && stoi(s.substr(s.find(" ")+1,s.find_last_of(" ")-1-s.find_first_of(" ")))>0){ //&& !(stoi(s.substr(s.find(" ")+1,s.find_last_of(" ")-1-s.find_first_of(" ")))>le.list.size)
                int indexNumber = stoi(s.substr(s.find(" ")+1,s.find_last_of(" ")-1-s.find_first_of(" ")));
                /**le.insert(stoi(s.substr(s.find(" ")+1,1))-1, s.substr(s.find("\"")+1,s.find_last_of("\"")-1-s.find_first_of("\"")));//int to string**/
                /*if(stoi(s.substr(s.find(" ")+1,s.find_last_of(" ")-1-s.find_first_of(" ")))==le.list.size){
                    le.insert(le.list.size, s.substr(s.find("\"")+1,s.find_last_of("\"")-1-s.find_first_of("\"")));
                }
                else{*/
                if(!(le.list.size==0 && indexNumber-1>0) && indexNumber-1<=le.list.size){
                    le.insert(indexNumber-1, s.substr(s.find("\"")+1,s.find_last_of("\"")-1-s.find_first_of("\"")));
                }
            }
            //if(s.substr(s.find(" ")+1,1)!="-"

        }
        if(s.find("search") != string::npos){
            le.search(s.substr(s.find("\"")+1,s.find_last_of("\"")-1-s.find_first_of("\"")));
        }
        if(s.find("print") != string::npos){
            le.print();
        }
        if(s.find("edit") != string::npos){
            le.edit(stoi(s.substr(s.find(" ")+1,s.find_last_of(" ")-1-s.find_first_of(" "))), s.substr(s.find("\"")+1,s.find_last_of("\"")-1-s.find_first_of("\"")));
        }
        if(s.find("delete") != string::npos){
            le.deletetext(stoi(s.substr(s.find(" ")+1,s.find_last_of(" ")-1-s.find_first_of(" "))));
        }

    }
}