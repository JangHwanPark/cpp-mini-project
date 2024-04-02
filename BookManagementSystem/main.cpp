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
    cout << "===================================" << "\n";
}

// 책 정보 입력 함수
void inputBookInfo() {
    cout << "이름";
    cout << "가격";
    cout << "저자";
    cout << "출판사";
    cout << "가격";
}

// 입력 받은 책 정보를 저장하는 함수
Book saveBookInfo(vector<Book>& books, Book& newBook) {
    books.push_back(newBook);

    // Todo : 벡터 내부에 저장된 구조체 데이터를 한꺼번에 모두 출력하기
    cout << "========================" << "\n" << "입력된 도서 정보" << "\n" << "========================" << "\n";
    cout << books[0].bookNumber << ". " << books[0].bookName << "\n";
    cout << books[0].author << "\n";
    cout << books[0].publisher << "\n";
    cout << books[0].price << "\n";
    cout << "========================" << "\n";
}

// Todo : 검색 기능 (return 해야함)
void getBookInfo(const vector<Book>& books) {
    cout << "검색 기능" << "\n";
    string dummySearch = "The Great Gats2by";
    cout << "TestValue: " << dummySearch << "\n";

    // 문자열 - KMP
    for (const auto& book : books) {
        cout << "검색 실행중" << book.bookName;
        if (book.bookName == dummySearch) cout << book.bookName;
        else cout << "입력한 도서가 존재하지 않습니다.";
    }
    // 번호 - 이진탐색
}

// Todo : 책 정보 수정
void setBookInfo() {

}
/**
 * 1. 수정할 책 검색 로직 작성 (공통 로직으로 사용할 듯)
 * 2. 데이터 수정 로직 작성
 */

// 실행 로직
void run(vector<Book> book, Book dummyBook) {
    while (true) {
        int keyword;
        cin >> keyword;

        switch (keyword) {
            // 정보 입력
            case 1:
                saveBookInfo(book, dummyBook);
                break;
            case 2:
                cout << "정보 수정";
                break;
            case 3:
                cout << "검색";
                break;
            case 4:
                cout << "데이터 삭제";
                break;
            case 5:
                cout << "프로그램 종료";
                break;
            default:
                cout << "올바른 명령어를 입력해 주세요" << "\n";
        }

        return;
    }
}

int main() {
    vector<Book> book;
    Book dummyBook = {1, "The Great Gatsby", "F. Scott Fitzgerald", "Charles Scribner's Sons", 19000};
    // 구조체 입력 테스트
    // Book test;
    //cin >> test.bookName;

    // 함수 실행
    // printMainDisplay();
    // run(book, dummyBook);
    saveBookInfo(book, dummyBook);
    getBookInfo(book);
    return 0;
}