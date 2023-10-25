/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;

class studentGrade {
    public:
        string studentName;
        int get_gpa();
        
        studentGrade(string name = "", int a = 0, int b = 0, int c = 0, int d = 0, int f = 0) {
            studentName = name;
            As = a;
            Bs = b;
            Cs = c;
            Ds = d;
            Fs = f;
        }
        
    private:
        int As = 0, Bs = 0, Cs = 0, Ds = 0, Fs = 0;
};

int studentGrade::get_gpa() {
    return (4 * As + 3 * Bs + 2 * Cs  + Ds) / (As + Bs + Cs + Ds + Fs);
}

int main()
{
    studentGrade Shonal("Shonal", 4, 3, 2, 1);
    studentGrade Libby("Libby", 3, 4, 1);
    studentGrade VerySmart;
    
    cout << Shonal.get_gpa() << endl;
    cout << Libby.get_gpa() << endl;
    cout << VerySmart.get_gpa() << endl;
    
    return 0;
}
