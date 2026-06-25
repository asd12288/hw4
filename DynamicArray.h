#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H



class DynamicArray {

    private:
        int *data;
        int size;
        int capacity;

        void resize();

    public:
        enum Result {
            SUCCESS,
            OUT_OF_BOUNDS,
            NOT_FOUND
        };
        
         // Constructors
        DynamicArray();
        DynamicArray(int initialCapacity);
        DynamicArray(const DynamicArray& orgArray);

        // Destructor  
        ~DynamicArray();

        // Functions
        void append(int value);
        void append(const DynamicArray& other);

        Result insert(int index, int value);
        Result remove(int index);

        Result find(int value, int& outIndex) const;
        void print() const;
        int& getAt(int index);
};    



#endif


