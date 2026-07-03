#include "Bureaucrat.hpp"

// Helper function to print a clean and visible header for each test case
void printTestHeader(const std::string& testName) {
    std::cout << "\n========================================\n";
    std::cout << " RUNNING: " << testName << "\n";
    std::cout << "========================================\n";
}

int main() {
    // -------------------------------------------------------------------------
    printTestHeader("Test 1: Creating valid bureaucrats");
    // -------------------------------------------------------------------------
    try {
        // Creating normal bureaucrats with allowed grades (between 1 and 150)
        Bureaucrat top("President", 1);    // Highest possible grade
        Bureaucrat mid("Secretary", 75);    // Middle grade
        Bureaucrat low("Intern", 150);     // Lowest possible grade

        // Printing them using the overloaded << operator
        std::cout << top << std::endl;
        std::cout << mid << std::endl;
        std::cout << low << std::endl;
    }
    catch (const std::exception& e) {
        // If an exception is caught here, something is wrong with our basic logic
        std::cerr << "Error (should not happen): " << e.what() << std::endl;
    }

    // -------------------------------------------------------------------------
    printTestHeader("Test 2: Creating INVALID bureaucrats (Grade too high)");
    // -------------------------------------------------------------------------
    try {
        std::cout << "Attempting to create a bureaucrat with grade 0..." << std::endl;
        Bureaucrat boss("Overlord", 0); // Should immediately throw GradeTooHighException
        std::cout << "CRITICAL ERROR: This line should NOT be executed!" << std::endl;
    }
    catch (const std::exception& e) {
        // The program should successfully catch the exception and print the error message
        std::cout << "Successfully caught exception: " << e.what() << std::endl;
    }

    try {
        std::cout << "\nAttempting to create a bureaucrat with a negative grade (-42)..." << std::endl;
        Bureaucrat boss("Anomaly", -42); // Also too high (less than 1)
        std::cout << "CRITICAL ERROR: This line should NOT be executed!" << std::endl;
    }
    catch (const std::exception& e) {
        std::cout << "Successfully caught exception: " << e.what() << std::endl;
    }

    // -------------------------------------------------------------------------
    printTestHeader("Test 3: Creating INVALID bureaucrats (Grade too low)");
    // -------------------------------------------------------------------------
    try {
        std::cout << "Attempting to create a bureaucrat with grade 151..." << std::endl;
        Bureaucrat lazy("Slacker", 151); // Should immediately throw GradeTooLowException
        std::cout << "CRITICAL ERROR: This line should NOT be executed!" << std::endl;
    }
    catch (const std::exception& e) {
        // Successfully caught the lower bound error (greater than 150)
        std::cout << "Successfully caught exception: " << e.what() << std::endl;
    }

    // -------------------------------------------------------------------------
    printTestHeader("Test 4: Successful grade increment and decrement");
    // -------------------------------------------------------------------------
    try {
        Bureaucrat jim("Jim", 3);
        std::cout << "Initial state: " << jim << std::endl;

        jim.incrementGrade(); // 3 -> 2 (remember: incrementing means decreasing the number)
        std::cout << "After increment (should be 2): " << jim << std::endl;

        jim.incrementGrade(); // 2 -> 1
        std::cout << "After another increment (should be 1): " << jim << std::endl;

        jim.decrementGrade(); // 1 -> 2 (decrementing means increasing the number)
        std::cout << "After decrement (should be 2): " << jim << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "Error (no exceptions should happen here): " << e.what() << std::endl;
    }

    // -------------------------------------------------------------------------
    printTestHeader("Test 5: Exception when incrementing past the limit (1 -> 0)");
    // -------------------------------------------------------------------------
    try {
        Bureaucrat god("Bureaucracy God", 2);
        std::cout << god << std::endl;

        god.incrementGrade(); // Changes grade from 2 to 1 (this is the absolute maximum)
        std::cout << god << std::endl;

        std::cout << "Attempting to increment grade 1 one more time (going to 0)..." << std::endl;
        god.incrementGrade(); // Internal safeguard should trigger and throw an exception!
        std::cout << "CRITICAL ERROR: This line should NOT be executed!" << std::endl;
    }
    catch (const std::exception& e) {
        std::cout << "Successfully caught exception: " << e.what() << std::endl;
    }

    // -------------------------------------------------------------------------
    printTestHeader("Test 6: Exception when decrementing past the limit (150 -> 151)");
    // -------------------------------------------------------------------------
    try {
        Bureaucrat intern("Intern", 149);
        std::cout << intern << std::endl;

        intern.decrementGrade(); // Changes grade from 149 to 150 (this is the absolute minimum)
        std::cout << intern << std::endl;

        std::cout << "Attempting to decrement grade 150 one more time (going to 151)..." << std::endl;
        intern.decrementGrade(); // Internal safeguard should trigger and throw an exception!
        std::cout << "CRITICAL ERROR: This line should NOT be executed!" << std::endl;
    }
    catch (const std::exception& e) {
        std::cout << "Successfully caught exception: " << e.what() << std::endl;
    }

    // -------------------------------------------------------------------------
    printTestHeader("Test 7: Verification of Orthodox Canonical Form (Copying)");
    // -------------------------------------------------------------------------
    try {
        Bureaucrat original("Original", 42);
        std::cout << "Original: " << original << std::endl;

        // Testing the COPY CONSTRUCTOR
        Bureaucrat copy(original);
        std::cout << "Copy:     " << copy << " (Created via copy constructor)" << std::endl;

        // Testing the COPY ASSIGNMENT OPERATOR
        Bureaucrat assigned("Temporary", 100);
        std::cout << "Before '=': " << assigned << std::endl;
        
        assigned = original; // Triggers our operator=
        std::cout << "After '=':  " << assigned << " (Name stayed 'Temporary' because it's const, but grade became 42)" << std::endl;
        
        // Testing SELF-ASSIGNMENT PROTECTION (original = original)
        // Verifies if the `if (this != &other)` condition works properly and doesn't crash the program.
        original = original;
        std::cout << "Self-assignment (original = original) completed successfully without crashing!" << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "Error during copying: " << e.what() << std::endl;
    }

    std::cout << "\n========================================\n";
    std::cout << " ALL TESTS COMPLETED SUCCESSFULLY!\n";
    std::cout << "========================================\n";

    return 0;
}