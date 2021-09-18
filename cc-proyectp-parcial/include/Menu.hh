#pragma once
#include<string>

class Menu
{
private:
  std::string material;
  std::string pieza;
  int cantidad;
public:
  Menu(std::string material, std::string pieza,  int cantidad);
  ~Menu();
  std::string Getmaterial() const;
  std::string Getpieza() const;
  int Getcantidad() const;
};
