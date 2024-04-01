#include <bits/stdc++.h>
using namespace std;

// 책 구조체 정의
struct Book {
    int bookNumber;
    string bookName;
    string author;
    string publisher;
    int price;
};

// 메인 화면
void printMainDisplay() {
    cout << "========== 도서 관리 시스템 ==========" << "\n";
    cout << "1. 책 정보 입력\n" << "2. 책 정보 수정\n" << "3. 책 검색\n" << "4. 데이터 삭제\n" << "5. 프로그램 종료" << "\n";
    cout << "===================================";
}

// 정보 입력 함수
Book inputBookInfo(vector<Book>& books, Book& newBook) {
    books.push_back(newBook);
}

void printBookInfo() {

}

int main() {
    vector<Book> book;
    Book dummyBook = {1, "The Great Gatsby", "F. Scott Fitzgerald", "Charles Scribner's Sons", 10};

    // 함수 실행
    printMainDisplay();
}