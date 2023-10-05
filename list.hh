class List {
    public:
    virtual void print() = 0;
    virtual int get(int pos) = 0;
    virtual void addHead(int num) = 0;
    virtual void addTail(int num) = 0;
    virtual void removeHead() = 0;
    virtual void removeTail() = 0;
    virtual int removeAt(int pos) = 0;
    virtual int removeAll(int num) = 0;
};