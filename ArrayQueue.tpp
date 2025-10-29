template <typename T>
ArrayQueue<T>::ArrayQueue(int i) {
    buffer = new T[i];
    maxSize = i;
    frontIndex = 0;
    backIndex = i - 1;
    this->length = 0;
}

template <typename T>
ArrayQueue<T>::ArrayQueue(const ArrayQueue<T>& copyObj) {
    copy(copyObj);
}

template <typename T>
ArrayQueue<T>& ArrayQueue<T>::operator=(const ArrayQueue<T>& rightObj) {
    if (this != &rightObj) {
        clear();
        copy(rightObj);
    }
    return *this;
}

template <typename T>
ArrayQueue<T>::~ArrayQueue() {
    clear();
}

template <typename T>
T ArrayQueue<T>::back() const {
    if(this->length == 0){
        throw std::string("Queue is empty!");
    }
    return buffer[backIndex];
}

template <typename T>
void ArrayQueue<T>::clear() {
    if (buffer == nullptr){
        return;
    }
    delete[] buffer;
    buffer = new T[maxSize];
    frontIndex = 0;
    backIndex = maxSize - 1;
    this->length = 0;
}

template <typename T>
void ArrayQueue<T>::copy(const ArrayQueue<T>& copyObj) {
    maxSize = copyObj.maxSize;
    buffer = new T[maxSize];
    this->length = copyObj.length;
    frontIndex = 0;
    backIndex = (this->length == 0 ? maxSize - 1 : this->length - 1);
    for (int i = 0; i < this->length; i++) {
        int srcIndex = (copyObj.frontIndex + i) % copyObj.maxSize;
        this->buffer[i] = copyObj.buffer[srcIndex];
    }

}

template <typename T>
void ArrayQueue<T>::dequeue() {
    if(this->length == 0) {
        throw std::string("Queue is empty!");
    }
    frontIndex = (frontIndex + 1) % maxSize;
    this->length--;
}

template <typename T>
void ArrayQueue<T>::enqueue(const T& elem) {
    if(this->length == maxSize) {
        throw std::string("Queue is full!");
    }
    backIndex = (backIndex + 1) % maxSize;
    buffer[backIndex] = elem;
    this->length++;
}

template <typename T>
T ArrayQueue<T>::front() const {
    if(this->length == 0){
    throw std::string("Queue is empty!");
    }
    return buffer[frontIndex];
}

template <typename T>
int ArrayQueue<T>::getLength() const {
    return this->length;
}

template <typename T>
int ArrayQueue<T>::getMaxSize() const {
    return maxSize;
}

template <typename T>
bool ArrayQueue<T>::isEmpty() const {
    return this->length == 0;
}

template <typename T>
bool ArrayQueue<T>::isFull() const {
    return this->length == maxSize;
}
