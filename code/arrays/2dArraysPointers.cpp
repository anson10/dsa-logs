#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    // 1. Array Declaration and Initialization
    int a[3][3] = {
        {2, 4, 6},
        {1, 3, 5},
        {0, 1, 3}
    };

    int i = 1; // Target Row Index
    int j = 2; // Target Column Index
    
    cout << "--- Pointers and 2D Arrays Demonstration ---\n\n";

    // --- A. Accessing the Value (a[i][j]) ---
    cout << "A. Accessing VALUE of a[" << i << "][" << j << "] (Value: " << a[i][j] << ")\n";

    // Standard Array Access
    cout << "1. Standard a[i][j]: " << a[i][j] << endl;

    // Pointer Notation 1: *(*(a + i) + j)
    // a is ptr to first row. (a+i) is address of row i. *(a+i) is ptr to first element of row i.
    // *(a+i)+j is address of a[i][j]. *(*(a+i)+j) is value of a[i][j].
    cout << "2. Pointer **(a + i) + j): " << *(*(a + i) + j) << endl;

    // Pointer Notation 2: *(a[i] + j)
    // a[i] decays to a pointer to a[i][0]. a[i]+j is address of a[i][j].
    cout << "3. Pointer *(a[i] + j): " << *(a[i] + j) << endl;
    
    cout << "\n-----------------------------------------\n";

    // --- B. Accessing the ADDRESS (&a[i][j]) ---
    cout << "B. Accessing ADDRESS of a[" << i << "][" << j << "] (Value: " << a[i][j] << ")\n";
    cout << hex << uppercase; // Use hexadecimal format for addresses

    // Standard Address-of Operator
    cout << "1. Standard &a[i][j]:      " << &a[i][j] << endl;
    
    // Pointer Notation 1: *(a + i) + j
    // Address of the j-th element in the i-th row, obtained via the 2D array pointer 'a'.
    cout << "2. Pointer *(a + i) + j:   " << *(a + i) + j << endl;

    // Pointer Notation 2: a[i] + j
    // Address obtained via the row pointer a[i].
    cout << "3. Pointer a[i] + j:       " << a[i] + j << endl;
    
    cout << dec << nouppercase; // Reset to decimal

    cout << "\n-----------------------------------------\n";

    // --- C. Accessing Row Pointers ---
    cout << "C. Row Pointer Access (Row 1)\n";
    
    // a[1] is the pointer to the first element of row 1
    cout << "1. Address of Row 1 (a[1]): " << a[1] << endl;
    
    // a + 1 is the address of the entire row 1
    cout << "2. Address of Row 1 (a + 1): " << (a + 1) << endl;
    
    // Value of the first element in Row 1 using the row pointer
    cout << "3. Value of a[1][0] (*a[1]): " << *a[1] << endl;

    return 0;
}