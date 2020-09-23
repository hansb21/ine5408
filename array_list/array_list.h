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
    /*
     * @brief Constructor.
     */ 
    ArrayList() {
        max_size_ = DEFAULT_MAX;
        contents = new T[max_size_];
        size_ = 0;
}
    /*
     * @brief Constructor with parameters.
     * 
     * @params Max_size:Max size of the list
     */
    explicit ArrayList(std::size_t max_size) {
        max_size_ = max_size;
        contents = new T[max_size_];
        size_ = 0;
}
    /*
     * @brief Destructor. 
     */
    ~ArrayList() {
        delete[] contents;
}

    /*
     * @brief Clears the list, seting the size to 0.
     */
    void clear() {
        size_ = 0;
}

    /*
     * @brief Inserts data at the back of the list.
     *
     * @params data: data to be inserted.
     */
    void push_back(const T& data) {
        insert(data, size());
}

    /*
     * @brief Inserts data at the first position of the list.
     *
     * @params data: data to be inserted.
     */
    void push_front(const T& data) {
        insert(data, 0);
}

    /*
     * @brief Insert function based on the index.
     *
     * @param data: data to be inserted.
     * @param index: index where the data will be inserted.
     */
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

    /*
     * @brief Inserts data until the data is smaller than next one on the list.
     *
     * @param data: data to be inserted.
     */
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

    /*
     * @brief Remove the element from the index
     * 
     * @param index: index of the data to be removed.
     * @returns value: value removed.
     */
    T pop(std::size_t index) {
        size_t aux;
        T value;
        
	/* Check for errors */       
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
}  

    /*
     * @brief Removes the list's last element.
     *
     * @returns the last element of the list.
     */
    T pop_back() {
    return pop(size_ - 1);
}   
    /*
     * @brief Removes the list's first element.
     * 
     * @returns the list's first element.
     */	
    T pop_front() {
        return pop(0);

}   
    
    /*
     * @brief Removes the data searching for the index.
     */ 
    void remove(const T& data) {
        if (empty()) {
            throw std::out_of_range("Lista vazia");
        }
        for (int i = 0; i< size_; i++) {
            if (contents[i] == data) {
                pop(i);
            }
        }
}   
    /*
     * @brief Verify if the list is full.
     *
     * @return True: if the size of the list equals the max_size.
     * @return False: if the size of the list differs from the max_size.
     */
    bool full() const {
        return size_ == max_size_;
}

   /*
    * @brief Verify if the list is empty.
    *
    * @return True: if the size of the list equals 0.
    * @return False: if the size of the list differs from 0.
    */
    bool empty() const {
        return size_ == 0;
}   
    /*
     * @brief Verify if the list contains the data.
     * 
     * @params data: Data to be verified.
     * @returns True
     * @returns False
     */
    bool contains(const T& data) const {
        bool value = false;
        for (int i = 0; i < size_; i++) {
            if (contents[i] == data) {
                value = true;
            }
        }
    return value;
}   
    /*
     * @brief Finds the index of the given data.
     *
     * @params data: Data to be found the index.
     * @returns value: The index of the given data, if found. Else, returns the size of the list.
     */
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

}   
    /*
     * @brief Size getter.
     *
     * @returns size_: Size of the list.
     */
    std::size_t size() const {
        return size_;
}
    /*
     * @brief Max size getter.
     *
     * @returns max_size: Max possible size of the list.
     */
    std::size_t max_size() const {
        return max_size_;
}   
    //! Posição
    T& at(std::size_t index) {
        if (empty()) {
            throw std::out_of_range("Lista vazia");
        }
        if (index >= size_) {
            throw std::out_of_range("Posição errada");
        }
        return contents[index];
}   
    //! []
    T& operator[](std::size_t index) {
        return contents[index];
}   
    //! Posição
    const T& at(std::size_t index) const {
        if (empty()) {
            throw std::out_of_range("Lista vazia");
        }
        if (index >= size_) {
            throw std::out_of_range("Posição errada");
        }
        return contents[index];
}   
    //! {}
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
