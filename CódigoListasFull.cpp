Google Classroom
Classroom
Estructuras de datos 2024-1
Inicio
Calendar
Recursos
Novedad
Cursos en los que te has inscrito
Tareas pendientes
F
FISICA II (CB 334) G11
L
Laboratorio Física 2
GRUPO 17, Miércoles: 12:00 m - 2:00 pm
E
Estructuras de datos 2024-1
M
Mate III
G-1
Clases archivadas
Ajustes
Tablón
Trabajo de clase
Personas
Estructuras de datos 2024-1

Meet
Próximas entregas
¡Yuju! ¡No tienes que entregar nada pronto!

Anuncia algo a tu clase

Anuncio: "Listas"
Gustavo Adolfo Gutierrez Sabogal
Fecha de creación: 10:0010:00
Listas

listc.hh
Texto

main.cc
Texto

Añade un comentario de clase…


Publicado por Jheniffer Florez Toro
Jheniffer Florez Toro
Fecha de creación: 9:539:53
.

clase 1 de marzo 2024.mp4
Vídeo

clase 28 de febrero 2024.mp4
Vídeo

clase 26 de febrero 2024.mp4
Vídeo

Añade un comentario de clase…


Anuncio: "Hola a todos, Yo no tengo problema en…"
Gustavo Adolfo Gutierrez Sabogal
Fecha de creación: 29 feb29 feb
Hola a todos,

Yo no tengo problema en dar la clase de manera virtual. Eso si, por favor el que no esté de acuerdo exprese su posición.

Añade un comentario de clase…


Publicado por Jose Felipe Duarte Coronado
Jose Felipe Duarte Coronado
Fecha de creación: 29 feb29 feb
Buen día estimados/as. Propongo que la clase de mañana la hagamos de manera virtual, dadas las circunstancias que se vieron hoy en la U. ¿Qué dicen?

Alejandro Loaiza Palacio29 feb
Yo apoyo la idea

Añade un comentario de clase…


Anuncio: "Hola a todos, Aquí va una descripción…"
Gustavo Adolfo Gutierrez Sabogal
Fecha de creación: 28 feb28 feb
Hola a todos,

Aquí va una descripción del ejercicio. Por favor lo realizan y me informan de cualquier problema. El viernes pondremos una fecha de entrega y otros ejercicios adicionales.

enunciado.pdf
PDF

rapidcsv.hh
Texto

test.cc
Texto

timer.hh
Texto

Añade un comentario de clase…


Publicado por Jheniffer Florez Toro
Jheniffer Florez Toro
Fecha de creación: 24 feb24 feb
.

clase 23 de febrero.mp4
Vídeo

Añade un comentario de clase…


Publicado por Jheniffer Florez Toro
Jheniffer Florez Toro
Fecha de creación: 21 feb21 feb
.

clase 16 de febrero.mp4
Vídeo

clase 12 de febrero.mp4
Vídeo

clase 9 de febrero.mp4
Vídeo

clase 7 de febrero.mp4
Vídeo

clase 21 de febrero.mp4
Vídeo
1 comentario de clase

Jose Felipe Duarte Coronado22 feb
Gracias Jheniffer!

Añade un comentario de clase…


Publicado por Juan David Garcia Arce
Juan David Garcia Arce
Fecha de creación: 19 feb19 feb
font:

microsoft/cascadia-code: This is a fun, new monospaced font that includes programming ligatures and is designed to enhance the modern look and feel of the Windows Terminal. (github.com)

Añade un comentario de clase…


Publicado por Jose Felipe Duarte Coronado
Jose Felipe Duarte Coronado
Fecha de creación: 19 feb19 feb
Fuente Monospace recomendada para programar

Monaspace
https://monaspace.githubnext.com/

Añade un comentario de clase…

Tarea: "Implementación operaciones vector"
Gustavo Adolfo Gutierrez Sabogal ha publicado una nueva tarea: Implementación operaciones vector
Fecha de creación: 19 feb19 feb
Estructuras de datos 2024-1
#ifndef __LIST_HH__
#define __LIST_HH__

#include <iostream>

template<typename T>
class List {
private:
  class Node {
  private:
    Node* next_;
    T data_;
  public:
    Node() : next_(nullptr), data_(T()) {}
    Node(const T& d) : next_(nullptr), data_(d) {}
    void setNext(Node* p) { next_ = p; }
    Node* getNext() { return next_; }
    const T& getData() {
      return data_;
    }
  };
  
  // Attributes
  Node* first_;
  Node* last_;
  unsigned int size_;
public:
  
  List() : first_(nullptr), last_(nullptr), size_(0) {}
  
  unsigned int size() const { return size_; }
  
  bool empty() { 
    return first_ == nullptr;
  }

  void push_back(const T& elem) {
    Node* n = new Node(elem);
    if(empty()) {
      first_ = n;
    } else {
      last_->setNext(n);
    }
    last_ = n;
    size_++;
  }

  void push_front(const T& elem) {
    Node* n = new Node(elem);
    if(empty()) {
      first_ = n;
      last_ = n;
      size_++;
    } else {
      n->setNext(first_);
      first_ = n;
      size_++;
    }
  }

  void print() {
    if (empty()) {
      std::cout << "< >" << std::endl;
    }
    Node* p = first_;
    while(p != nullptr) {
      std::cout << "(" << p->getData() 
                << "-> " << p->getNext() 
                << ")" << std::endl;
      p = p->getNext();
    }
    std::cout << "-----" << std::endl; 
  }
};
#endif
listc.hh
Mostrando listc.hh.
