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
            for (int i = 0; i < n; i++){
                vector_array[i] = *a+i;
            }
        }

        int capacity(){
            return n;
        }
        void Clear(){
            delete []vector_array;
            n = 0;
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

void test_pointerArray(float* a){
    cout << *(a+1);
}

void test_vector(){
    float a[]={1,2,3,4,5};
    //test_pointerArray(s);
    Vector b(a, 5);
    Vector c;
    cout << b.capacity() << endl;
    b.Clear();
    cout << b.capacity() << endl;
}

main()
{
 //test_prod();
 test_vector();

 //test_pointerArray();
 // getch();
  return 0;
}


