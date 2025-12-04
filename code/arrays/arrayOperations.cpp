#include<iostream>

int main() {
	int a[50], size = 0;
	std::cout << "Enter the size of the array: ";
	std::cin >> size;

	for (int i = 0; i < size; i++) {
		std::cout << " Enter element: ";
		std::cin >> a[i];
	}
	for (int i = 0; i < size; i++) {
		std::cout << "Elements: " << a[i] << std::endl;
	}
	// Insertion
	int num = 0, pos=0;
	std::cout << "Enter number you want to insert: ";
	std::cin >> num;
	std::cout << "Enter position: ";
	std::cin >> pos;

	for (int i = size - 1; i >= pos - 1; i--) {
		a[i + 1] = a[i];
	}
	a[pos - 1] = num;
	size++;

	for (int i = 0; i < size; i++) {
		std::cout << "Position " << i + 1<< ": "  << a[i] << std::endl;
	}

	//Deletion
	std::cout << "Enter position to delete: ";
	std::cin >> pos;
	if (pos <= 0 || pos > size) {
		std::cout << "Invalid position";
	}
	else {
		for (int i = pos - 1; i < size - 1; i++) {
			a[i] = a[i + 1];
		}
		size--;
	}
	for (int i = 0; i < size; i++) {
		std::cout << "Position: " << i+1 << ": " << a[i] << std::endl;
	}
}
