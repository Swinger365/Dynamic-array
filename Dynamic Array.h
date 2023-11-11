#ifndef INCLUDED
#define INCLUDED
#include <iostream>
namespace Dynamic{
    template <class T,unsigned int new_size = 0>
    class DynamicArray{
    protected:
        T *arr;
        unsigned int size_arr;
    public:
        //-------------------------Constructors and Destructors----------------------------------
        DynamicArray(){arr = new T[new_size];size_arr = new_size;}
        //-------------------------Getters and Setters--------------------------------------------
        virtual T get_el(const unsigned int &index) const {return arr[index];}
        virtual void set_el(const unsigned int &index,const T &value){arr[index] = value;}
        void set_size(const unsigned int &new_sz){
            if(size_arr<=new_sz){
                size_arr = new_sz;
            }else{
                T *new_arr = new T[new_sz];
                for(int i = 0; i < new_sz;i++)new_arr[i] = arr[i];
                delete[] arr;
                arr = new_arr;
                size_arr = new_sz;
            }//if
        }
        unsigned int get_size() const {return size_arr;}
        //------------------------Useful Methods--------------------------------------------------
        void pushback(const T &value){
            T *new_arr = new T[++size_arr];
            for(int i = 0;i<size_arr;i++)new_arr[i] = arr[i];
            new_arr[--size_arr] = value;
            size_arr++;
            delete[] arr;
            arr = new_arr;
        }
        void popback(){
            if(size_arr != 0){
                T *new_arr = new T[size_arr];
                for(int i = 0; i < (size_arr-1);i++)new_arr[i] = arr[i];
                delete[] arr;
                arr = new_arr;
                size_arr--;
            }
        }
        void delete_el(const unsigned int &index){
            T *new_arr = new T[size_arr-1];
            unsigned int j = 0;
            for(int i = 0; i < size_arr;i++){
                if(i == index){
                    continue;
                } else {
                    new_arr[j] = arr[i];
                    j++;
                }//if
            }//for
            delete[] arr;
            arr = new_arr;
            size_arr--;
        }
        void insert_back(const unsigned int &index,const T &value){
            T *new_arr = new T[size_arr+1];
            unsigned int j = 0;
            bool inserted = false;
            if(index != size_arr){
                for(int i = 0;i<size_arr;i++){
                    if(i == index && !inserted){
                        new_arr[j] = value;
                        j++;
                        inserted = true;
                        i--;
                    } else {
                        new_arr[j] = arr[i];
                        j++;
                    }//if incl
                }//for
                delete[] arr;
                size_arr++;
                arr = new_arr;
            } else {
                pushback(value);
            }//if main
        }
        virtual T* find_el(const T &value){
            for(int i = 0;i<size_arr;i++) {
                if (arr[i] == value) return &arr[i];
                else continue;
            }//for
            return nullptr;
        }
        virtual void show() const {
            if(size_arr != 0){
                T *start = arr;
                std::cout<<"Array: ";
                for(int i = 0;i<size_arr;++i)std::cout<<*start++<<" ";
                std::cout<<std::endl;
                std::cout<<"Size: "<<size_arr<<std::endl;
            }else {
                std::cout<<"[!]Array is empty now[!]\n";
            }//if
        }
    };//class DynamicArr
}//namespace Dynamic
#endif // INCLUDED
