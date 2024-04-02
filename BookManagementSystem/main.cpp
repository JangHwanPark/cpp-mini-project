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

// [Test]객체 출력을 위한 연산자 오버로딩
ostream& operator<<(ostream& os, const Book& book) {
    os << "Book Number: " << book.bookNumber
       << ", Name: " << book.bookName
       << ", Author: " << book.author
       << ", Publisher: " << book.publisher
       << ", Price: " << book.price;
    return os;
}

// 메인 화면
void printMainDisplay() {
    string title = "========== 도서 관리 시스템 ==========";
    string menu =
            "1. 책 정보 입력\n"
            "2. 책 정보 수정\n"
            "3. 책 검색\n"
            "4. 데이터 삭제\n"
            "5. 프로그램 종료\n";
    string bottomLine = string(title.length(), '=');
    cout << title << "\n"
         << menu
         << bottomLine << "\n";
}

// 책 정보 입력 함수
void inputBookInfo(vector<Book> book) {
    cout << "이름";
    cout << "가격";
    cout << "저자";
    cout << "출판사";
    cout << "가격";
}

// 입력 받은 책 정보를 저장하는 함수 (Book)
void saveBookInfo(vector<Book>& books, Book& newBook) {
    books.push_back(newBook);
    cout << "입력하신 정보가 저장되었습니다." << "\n";
}

// const Book* 은 포인터가 가리키는 Book 객체를 상수로 취급함을 의미
const Book* searchBookInfo(const vector<Book>& books) {
    string dummySearch = "The Great Gatsby";
    // cout << "const Book& books: " << books[0] << "\n";

    // const type& .. - 참조된 객체를 변경할 수 없게 만듬 (읽기만 가능, 데이터 무결성 보장)
    for (const Book& book : books) {
        if (book.bookName == dummySearch) {
            cout << "검색 결과: " << book.bookName << "\n";
            return &book;
        }
    }

    cout << "입력한 도서가 존재하지 않습니다." << "\n";
    return nullptr;
}

// 입력된 정보를 수정하는 함수
// Book Fn() {} - 실행 될때마다 값으로 반환 (반환시 복사본 생성)
// Book* Fn() {} - 값의 포인터를 반환. (객체 포인터 반환x, 동적 할당 객체/전역, 정적 범위 객체 해당)
void modifyBookInfo(vector<Book>& books) {
    string dummyQuery = "The Great Gatsby";
    string searchQuery;

    for (Book& book : books) {
        cout << "수정할 정보를 선택하세요.";
        cout << "1. 책 이름 변경";
        cout << "2. 저자 변경";
        cout << "3. 출판사 변경";
        cout << "4. 가격 변경";
        // getline(cin, searchQuery);
        if (book.bookName == dummyQuery) {
            cout << "변경할 책 이름을 입력 하세요.";
        } else {
            cout << "잘못된 속성 입니다.";
        }
        cout << "도서 정보가 수정되었습니다.";
    }
}

void deleteBook(vector<Book>& books) {
    string dummySearch = "The Great Gatsby";

    if (books[0].bookName == dummySearch) {
        cout << "\"" << books[0].bookName << "\"" << " 도서가 삭제되었습니다." << "\n";
        books.pop_back();
    } else cout << "입력한 도서가 존재하지 않습니다." << "\n";
}

// 실행 로직
void run(vector<Book> book, Book dummyBook) {
    while (true) {
        printMainDisplay();
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
                searchBookInfo(book);
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
    cout << "\n";
    searchBookInfo(book);
    cout << "\n";
    deleteBook(book);
    cout << "\n";
    searchBookInfo(book);
    cout << "\n";
    modifyBookInfo(book);
    return 0;
}