//  Copyright 2020 <Hans Buss Heidemann>
#ifndef STRUCTURES_ARRAY_LIST_H
#define STRUCTURES_ARRAY_LIST_H

#include <cstdint>
#include <stdexcept>


namespace structures {

template<typename T>
  //! Classe Vetor
class ArrayList {
 public:
    //! Gerador
    ArrayList() {
        max_size_ = DEFAULT_MAX;
        contents = new T[max_size_];
        size_ = 0;
}
    //! Gerador com paramêtro
    explicit ArrayList(std::size_t max_size) {
        max_size_ = max_size;
        contents = new T[max_size_];
        size_ = 0;
}
    //! Destruidor
    ~ArrayList() {
        delete[] contents;
}
    //! Zera a lista
    void clear() {
        size_ = 0;
}
    //! Insere na ultima
    void push_back(const T& data) {
        insert(data, size());
}
    //! Insere na primeira
    void push_front(const T& data) {
        insert(data, 0);
}
    //! Insere
    void insert(const T& data, std::size_t index) {
        size_t aux;
        if (full()) {
            throw std::out_of_range("Lista cheia");
        }
        if ( index > size_ || index < 0 ) {
            throw std::out_of_range("Posição invalida.");
        }
        aux = size_;
        while (aux > index) {
            contents[aux] = contents[aux - 1];
            aux--;
        }
        size_++;
        contents[index] = data;
}
    //! Insere em ordem
    void insert_sorted(const T& data) {
        size_t aux;
        if (full()) {
            throw std::out_of_range("Lista cheia");
}
        aux = 0;
        while ( aux <size_ && data > contents[aux] ) {
            aux++;
        }
        insert(data, aux);
}
    //! Tira
    T pop(std::size_t index) {
        size_t aux;
        T value;
        if (index >= size_ || index < 0) {
            throw std::out_of_range("Posição invalida");
}
        if (empty()) {
            throw std::out_of_range("Lista vazia");
}
        size_--;
        value = contents[index];
        aux = index;
        while (aux <= size_) {
            contents[aux] = contents[aux + 1];
            aux++;
        }
        return value;
}   //! Tira último
    T pop_back() {
    return pop(size_ - 1);
}   //! Tira primeiro
    T pop_front() {
        return pop(0);
}   //! remove
    void remove(const T& data) {
        if (empty()) {
            throw std::out_of_range("Lista vazia");
        }
        for (int i = 0; i< size_; i++) {
            if (contents[i] == data) {
                pop(i);
            }
        }
}   //! cheio
    bool full() const {
        return size_ == max_size_;
}   //! vazio
    bool empty() const {
        return size_ == 0;
}   //! contem
    bool contains(const T& data) const {
        bool value = false;
        for (int i = 0; i < size_; i++) {
            if (contents[i] == data) {
                value = true;
            }
        }
    return value;
}   //! acha
    std::size_t find(const T& data) const {
        if (empty()) {
            throw std::out_of_range("Lista vázia");
        }
        size_t value = size_;
        for (int i = 0; i<= size_; i++) {
            if (contents[i] == data) {
            value = i;
            }
        }
    return value;
}   //! tamanho
    std::size_t size() const {
        return size_;
}   //! maior tamanho
    std::size_t max_size() const {
        return max_size_;
}   //! Posição
    T& at(std::size_t index) {
        if (empty()) {
            throw std::out_of_range("Lista vazia");
        }
        if (index >= size_) {
            throw std::out_of_range("Posição errada");
        }
        return contents[index];
}   //! []
    T& operator[](std::size_t index) {
        return contents[index];
}   //! Posição
    const T& at(std::size_t index) const {
        if (empty()) {
            throw std::out_of_range("Lista vazia");
        }
        if (index >= size_) {
            throw std::out_of_range("Posição errada");
        }
        return contents[index];
}   //! {}
    const T& operator[](std::size_t index) const {
        return contents[index];
    }

 private:
    T* contents;
    std::size_t size_;
    std::size_t max_size_;

    static const auto DEFAULT_MAX = 10u;
};
}  // namespace structures

#endif
