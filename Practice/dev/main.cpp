#include "dev.h"
#include "service.h"
#include <iostream>
#include <QtWidgets/QApplication>
#include <QMessageBox>

using namespace std;

void testService()
{
    Repo repo("dev.txt", "issues.txt");

    Service serv(repo);
    QMessageBox::information(nullptr, "Test", "Starting tests...");

    try {
        // Test 1: Add new issue
        serv.addIssue("Test issue - Login button broken", "Alice");
        std::cout << "Test 1 (Add) - OK\n";

        // Test 2: Add second issue
        serv.addIssue("Test issue - Page crashes", "Carol");
        std::cout << "Test 2 (Add) - OK\n";
            
        // Test 3: Resolve issue
        serv.resolveIssue("Test issue - Login button broken", "Bob");
        std::cout << "Test 3 (Resolve) - OK\n";

        // Test 4: Try duplicate → should be caught
        try {
            serv.addIssue("Test issue - Login button broken", "Alice");
        }
        catch (...) {
            std::cout << "Test 4 (Duplicate) - OK (correctly rejected)\n";
        }

        // Test 5: Try resolve closed issue → should be caught
        try {
            serv.resolveIssue("Test issue - Login button broken", "Dave");
        }
        catch (...) {
            std::cout << "Test 5 (Closed issue) - OK (correctly rejected)\n";
        }

        std::cout << "All tests passed!\n";
        QMessageBox::information(nullptr, "Test", "All tests passed!");

    }
    catch (const std::exception& e) {
        std::cout << "Test failed: " << e.what() << std::endl;
        QMessageBox::warning(nullptr, "Test", "Some tests failed!");
    }
    catch (...) {
        QMessageBox::warning(nullptr, "Test", "Unknown error during testing!");
    }
}

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    Repo repo("dev.txt","issues.txt");

    Service serv(repo);

    QVector<dev*> windows;
    testService();
    for (auto i : repo.getUsers())
    {
        dev* w = new dev(i, serv);
        w->show();
        windows.push_back(w);
    }
    int result = app.exec();
    //serv.saveIssues();
    return result;
}
