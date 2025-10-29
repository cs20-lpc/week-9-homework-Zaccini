template <typename T>
LinkedQueue<T>::LinkedQueue() {
    this->length = 0;
    head = nullptr;
    last = nullptr;
}

template <typename T>
LinkedQueue<T>::LinkedQueue(const LinkedQueue<T>& copyObj) {
    copy(copyObj);
}

template <typename T>
LinkedQueue<T>& LinkedQueue<T>::operator=(const LinkedQueue<T>& rightObj) {
    if (this != &rightObj) {
        clear();
        copy(rightObj);
    }
    return *this;
}

template <typename T>
LinkedQueue<T>::~LinkedQueue() {
    clear();
}

template <typename T>
T LinkedQueue<T>::back() const {
    if (isEmpty()) {
        throw string("Queue is empty!");
    }
    return last->value;
}

template <typename T>
void LinkedQueue<T>::clear() {
    Node* current = head;
    while (current != nullptr) {
        Node* next = current->next;
        delete current;
        current = next;
    }
    head = nullptr;
    last = nullptr;
    this->length = 0;
}

template <typename T>
void LinkedQueue<T>::copy(const LinkedQueue<T>& copyObj) {
    head = nullptr;
    last = nullptr;
    this->length = 0;

    Node* current = copyObj.head;
    while (current != nullptr) {
        Node* newNode = new Node(current->value);
        if (head == nullptr) {
            head = newNode;
        } else {
            last->next = newNode;
        }
        last = newNode;
        ++this->length;
        current = current->next;
    }
}

template <typename T>
void LinkedQueue<T>::dequeue() {
    if (isEmpty()) {
        throw string("Queue is empty!");
    }
    Node* oldHead = head;
    head = head->next;
    delete oldHead;
    --this->length;
    if (this->length == 0) {
        last = nullptr;
    }
}

template <typename T>
void LinkedQueue<T>::enqueue(const T& elem) {
    Node* newNode = new Node(elem);
    if (isEmpty()) {
        head = newNode;
    } else {
        last->next = newNode;
    }
    last = newNode;
    ++this->length;
}

template <typename T>
T LinkedQueue<T>::front() const {
    if (isEmpty()) {
        throw string("Queue is empty!");
    }
    return head->value;
}

template <typename T>
int LinkedQueue<T>::getLength() const {
    return this->length;
}

template <typename T>
bool LinkedQueue<T>::isEmpty() const {
    return this->length == 0;
}
