/* Production of a Complex number and a Real number: m(a+jb)=ma + jmb
  Create a friend function of both classes (Real and Complex) to perform this operation
*/
#include <iostream>
#include <conio.h>

using namespace std;

class Complex;
class Real
{
  private:
    float value;
  public:
    Real(float v = 0)
    {
      value = v;
    }
    void display()
    {
      cout << value;
    }
    friend class Complex;
};
class Complex
{
  private:
    float real, image;
  public:
    Complex(float a = 0, float b = 0)
    {
      real = a;
      image = b;
    }
    void display()
    {
      cout << real << " + j*" << image;
    }
    Complex prod(Real &A, Complex &B){
        Complex C;
        C.real = A.value * B.real;
        C.image = A.value * B.image;
        return C;
    }
};

class Vector
{
    private:
        float* vector_array;
        int n = 0;
    public:
        Vector(){
            cout << "Input the number element of Vector: ";
            cin >> n;
            //cout << n << endl;
            vector_array = new float[n];
            for (int i = 0; i < n; i++){
                cout << "Input the " << i + 1 << " element: ";
                cin >> vector_array[i];
            }
        }

        Vector(float *a, int c){
            n = c;
            vector_array = new float[n];

            for (int i = 0; i < n; i++){
                vector_array[i] = *(a+i);
            }
        }

        int capacity(){
            return n;
        }

        void Clear(){
            delete []vector_array;
            n = 0;
        }

        bool contains(float elem){
            for (int i = 0; i < n;i++){
                if (vector_array[i] == elem) return true;
            }
            return false;
        }

        int indexOf(float elem){
            for (int i = 0; i < n;i++){
                if (vector_array[i] == elem) return i+1;
            }
            return 0;
        }

        int lastIndexOf(float elem){
            for (int i = n-1; i >=0; i--){
                if (vector_array[i] == elem) return i+1;
            }
            return 0;
        }

        float elementAt(int index){
            return vector_array[index - 1];
        }

        bool isEmpty(){
            return (!n);
        }

        void display(){
            for (int i = 0; i < n; i++){
                cout << vector_array[i] << " ";
            }
            cout << endl;
        }

        ~Vector(){
            delete []vector_array;
        }
};
//Define the production function of a Real and a Complex

void test_prod(){
Real A(6);
  Complex B(5, 4);
  A.display();
  cout << "*(";
  B.display();
  cout << ")= ";
  Complex C = C.prod(A,B);
  C.display();
}

float* test_pointerArray(){
   float a[] = {1,2,3,4,5};
   float *p = a;
   return p;
}

void test_vector(){
    float a[]={1,2,3,4,5,2,3,4};

    Vector c(a, 8);
    Vector b;

    cout << "Capacity of b: " << b.capacity() << endl;
    cout << "Does b contain 13? : " << b.contains(13) << endl
         << "Does b contain 3? : " << b.contains(3) << endl; //for contain function

    cout << "Index position of 3: " << b.indexOf(3) << endl
         << "Index position of 15: " << b.indexOf(15) << endl; //if element not exist, return 0

    cout << "Last Index position of 3: " << b.lastIndexOf(3) << endl
         << "Last Index position of 15: " << b.lastIndexOf(15) << endl; //if element not exist, return 0

    cout << "Element at position 2 is: " << b.elementAt(2) << endl;

    cout << "Let see what we have in Vector b: ";
    b.display();

    b.Clear();
    cout << "b was cleared." << endl;
    cout << "Capacity of b: " << b.capacity() << endl;

    cout << "Is b empty? : " << b.isEmpty() << endl
         << "Is c empty? : " << c.isEmpty() << endl;
}

main()
{
 //test_prod();
 test_vector();

 //float* b = test_pointerArray();


 // getch();
  return 0;
}


