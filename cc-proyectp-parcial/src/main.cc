#include<iostream>
#include "Menu.hh"
#include "Stack.hh"
#include "Nodo.hh"

int main()
{
  Menu* tipo1{new Menu("acero inoxidable", "cuchillos", 14)};
  Menu* tipo2{new Menu("porcelana", "platos", 6)};
  Menu* tipo3{new Menu("metal", "tenedores", 20)};
  Menu* tipo4{new Menu("vidrio ", "vasos", 10)};

  Stack* stack{new Stack()};
  stack->Push(tipo1);
  stack->Push(tipo2);
  stack->Push(tipo3);
  stack->Print();

  stack->Pop();
  stack->Pop();
  stack->Push(tipo4);
  stack->Print();

  stack->Pop();
  stack->Pop();
  stack->Pop();
  stack->Pop();
  stack->Push(tipo2);

  std::cin.get();

  delete stack;
  return 0;
}



Node::Node(Menu *&menu){
  this->menupieza = menu;
}

Node::~Node(){
}

Menu *Node::GetMenu() const{
  return menupieza;
}

Stack::Stack(){
}

Stack::~Stack(){
}

void Stack::Pop()
{
  if(IsEmpty())
  {
    std::cout << "lista de piezas esta vacia :" << std::endl;
  }
  else
  {
    Node* current{head};
    head = head->next;
    delete current;
  }
}
bool Stack::IsEmpty() const{
  return head == nullptr;
}
void Stack::Push(Menu*& menu){
  if(IsEmpty()){
    head = new Node(menu);
  }
  {
    Node* back{head};
    head = new Node(menu);
    head->next = back;
  }
}

void Stack::Print(){
    Node* current{head};

    std::cout << "lista de piezas :"<< std::endl;
    std::cout << std::endl;
    while (current){
      std::cout << "tipo de pieza: " << current->GetMenu()->Getmaterial() << std::endl;
      std::cout << "pieza: " << current->GetMenu()->Getpieza() << std::endl;
      std::cout << "cuantas piezas: " << current->GetMenu()->Getcantidad() << std::endl;
      std::cout << std::endl;
      current = current->next;
    }
  }
Menu::Menu(std::string material, std::string pieza, int cantidad){
  this->material = material;
  this->pieza = pieza;
  this->cantidad = cantidad;
}

Menu::~Menu(){
}

std::string Menu::Getmaterial() const{
  return material; 
}
std::string Menu::Getpieza() const{
  return pieza;
}
int Menu::Getcantidad() const{
  return cantidad;
}
