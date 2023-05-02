#include <iostream>
#include <cstdio>  // to use getchar
using namespace std;

class Node {
private:
  string name;
  int phone;
  Node *next;
public:
  void loaddata(string n, int pn, Node* p);
  string getname() { return name; }
  int getnumber() { return phone; }
  Node* getnext() { return next; }
  void setnext(Node* p) { next = p; }
};

void enterdata();
void searchlist(string str);

Node* listpointer;

int main() {
  string search;
  listpointer = NULL;
  enterdata();
  cout << "\nEnter the name to search for ";
  getline(cin, search);
  searchlist(search);
}
//ran out of time
void enterdata() {
  Node *temp, *lastnode;
  string n;
  int pn;
  while(n != "??"){
    cout << "Enter the Name (?? to stop): ";
    cin >> n;
    cout << "Enter the phone number for " << n << ": ";
    cin >> pn;
    if(n != "??"){
      temp = new Node;
      temp->loaddata(n, pn, NULL);
      lastnode->setnext(temp);
      lastnode = temp;
    }
  }
}

void searchlist(string str) {
  Node* current;
  string currentname;
  current = listpointer;
  while (current != NULL) {
    if (currentname == str) {
      cout << "Phone number for " << currentname;
      cout << " is " << current->getnumber() << endl;
      return;
    }
    current = current->getnext();
  }
  cout << str << " is not in the list.\n";
}

//---------- methods for the Node ---------
void Node::loaddata(string n, int pn, Node* p) {
  name = n;
  phone = pn;
  next = p;
}
