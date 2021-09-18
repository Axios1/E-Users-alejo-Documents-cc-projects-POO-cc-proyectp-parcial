#pragma once
#include "Menu.hh"

class Node
{
private:
  Menu* menupieza{};
public:
  Node* next{};
  Node(Menu*& menupieza);
  ~Node();

  Menu* GetMenu() const;
};
