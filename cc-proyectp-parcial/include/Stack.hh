#pragma once
#include "Nodo.hh"
#include "Menu.hh"

class Stack
{
private:
  Node* head{nullptr};
public:
  Stack();
  ~Stack();
  void Pop(); 
  void Push(Menu*& Menu);
  bool IsEmpty() const;
  void Print();
};
